#include<bits/stdc++.h>
#define ll long long
#define MX 1000000
#define MN 100000
#define T 7
#define pa pair<ll,int>
using namespace std;
inline ll read()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
map<ll,int> mp;
vector<pa>v[65];
pa p[65];
ll s[65],d[MN+5];
int n,Ans[10005],num,b[MX+5],cnt,S[MX/5],last[MX+5];
inline ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
inline ll Mul(ll x,ll y,ll mod){return (((x*y-(ll)(((long double)x*y+0.5)/mod)*mod)%mod)+mod)%mod;}
inline ll pow(ll x,ll k,ll mod)
{
	ll res=1;
	for(;k;k>>=1,x=Mul(x,x,mod)) if(k&1) res=Mul(res,x,mod);
	return res;	
}
bool Miller_Rabin(ll x)
{
	if(x<=MX) return !b[x];
	ll b=x-1,c=0;
	while(~b&1) b>>=1,++c;
	for(int t=0;t<T;++t)
	{
		ll a=rand()%(x-1)+1,s=pow(a,b,x),S;
		for(int i=0;i<c;++i,s=S)
			if((S=Mul(s,s,x))==1&&s!=1&&s!=x-1) return false;
		if(s!=1) return false;
	}
	return true;
}
inline ll Abs(ll x){return x<0?-x:x;}
ll Pollard_Rho(ll n,ll c)
{
	ll k=2,x=rand()%n,y=x;
	for(int i=1;;++i)
	{
		y=(Mul(y,y,n)+c)%n;
		ll p=gcd(Abs(x-y),n);
		if(p>1) return p;
		if(i==k) k<<=1,x=y; 
	}
}
void Divide(ll x)
{
	if(x==1)return;
	if(Miller_Rabin(x))
	{
		if(!mp[x]) p[mp[x]=++num]=make_pair(x,0);
		++p[mp[x]].second;
		return;	
	}
	ll p=x<=MX?last[x]:x;
	while(p==x) p=Pollard_Rho(x,rand()%x);
	Divide(p);Divide(x/p);
}
inline void exgcd(ll a,ll b,ll&x,ll&y)
{
	if(!b){x=1;y=0;return;}
	exgcd(b,a%b,x,y);
	ll t=x;x=y;y=t-(a/b)*x;
}
int main()
{
	n=read();srand((long long)new char);
    for(int i=2;i<=MX;++i)
    {
        if(!b[i]) S[++cnt]=i,last[i]=i;
        for(int j=1;S[j]*i<=MX;++j)
        {
            b[S[j]*i]=1;last[S[j]*i]=S[j];
            if(i%S[j]==0) break;
        }
    }
	for(int i=1;i<=n;++i) 
	{
		ll n=read(),k=read();
		if(!mp[k]) mp[k]=++num,s[num]=k;
		v[mp[k]].push_back(make_pair(n,i));	
	}
	for(int i=num;i;--i)
	{
		if(s[i]==1) continue;
		num=0;mp.clear();Divide(s[i]);
		sort(p+1,p+num+1);ll P=p[1].first;
		if(num==1) 
		{
			for(int j=0;j<v[i].size();++j)
				if(v[i][j].first%P==0) Ans[v[i][j].second]=1;	
		}
		else if(num==2)
		{
            ll x,y;exgcd(p[1].first,p[2].first,x,y);
            if(x<0)
            {
                ll t=(-x+p[2].first-1)/p[2].first;
                x+=t*p[2].first;y-=t*p[1].first;
            }
			for(int j=0;j<v[i].size();++j)
			{
				ll A=Mul(x,v[i][j].first,p[2].first);
                if(v[i][j].first/p[1].first>=A) Ans[v[i][j].second]=1; 
			}
		}
		else
		{
			memset(d,63,sizeof(d));d[0]=0;int P=p[1].first;
			for(int i=2;i<=num;++i)
                for(int t=0,x=0,y;t<=2*P;++t,x=y)
                    y=(x+p[i].first)%P,d[y]=min(d[y],d[x]+p[i].first);
			for(int j=0;j<v[i].size();++j)
				if(v[i][j].first>=d[v[i][j].first%P]) 
					Ans[v[i][j].second]=1;	
		}
	}
	for(int i=1;i<=n;++i) puts(Ans[i]?"YES":"NO");
	return 0;
}