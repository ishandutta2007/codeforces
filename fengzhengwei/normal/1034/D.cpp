#include<bits/stdc++.h>
#define ll long long
#define dd double
#define ull unsigned ll
#define LL __int128
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int xx=3e5+5;
int n,m;
int L[xx],R[xx];
struct qu
{
	int id,op,v;
};
//
vector<qu>v[xx];
vector<qu>*S;
struct pr
{
	int l,r,v;
	bool operator<(const pr&w)const{return l<w.l;}
};
set<pr>s;
//xa~x-1,x~...
void split(int x)
{
	if(x==0||x==((int)1e9+1))return;
	//cerr<<x<<"@@@\n";
	auto it=(--s.upper_bound({x,0,0}));
	if(it->l!=x)
	{
		int l=it->l,r=it->r,col=it->v;
		s.erase(it),s.insert({l,x-1,col}),s.insert({x,r,col});
	}
}
ll tt[xx];
ll check(int mid)
{
	//>=midsum
	ll ans=0,sum=0;
	tt[0]=1e9;
	for(int i=1;i<=n;i++)tt[i]=0;
	int lp=1;
	for(int i=1;i<=n;i++)
	{
		for(auto it:v[i])
		{
			tt[it.id]+=it.op*it.v;
			if(lp<=it.id&&it.id<=i)sum+=it.op*it.v;
		}
		while(sum>=mid&&lp<i&&sum-tt[lp]>=mid)sum-=tt[lp++];
		if(sum>=mid)ans+=lp;
	}
	return ans;
}
int lb(int x){return x&-x;}
struct nod
{
	ll sum[xx];
	void add(int x,ll y){for(;x<xx;x+=lb(x))sum[x]+=y;}
	ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
}s1,s2;
//ss*i
void cg(int id,ll v)
{
	//cerr<<id<<" "<<v<<"#$#$\n";
	id=n+1-id;
	s1.add(id,v),s2.add(id,v*id);
}
ll get(int t){return s1.ask(t)*(t+1)-s2.ask(t);}
int main(){
	//freopen("a.in","r",stdin);
	n=read(),m=read();
	for(int i=1;i<=n;i++)L[i]=read(),R[i]=read()-1;
//	for(int i=1;i<=n;i++)cerr<<L[i]<<" "<<R[i]<<"@\n";
	s.insert({1,(int)1e9,0});
	for(int i=1;i<=n;i++)
	{
		S=&v[i];
		split(L[i]),split(R[i]+1);
		auto it=(--s.upper_bound({L[i],0,0})),ed=(s.upper_bound({R[i],0,0}));
		for(auto I=it;I!=ed;s.erase(I++))
			S->push_back({I->v,-1,I->r-I->l+1});
		s.insert({L[i],R[i],i});
		S->push_back({i,1,R[i]-L[i]+1});
	}/*
	for(int i=1;i<=n;i++)
	{
		for(auto it:v[i])
		{
			cout<<it.id<<" "<<it.op<<" "<<it.v<<"S\n";
		}
	}*/
	int l=1,r=1e9,ans=0;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid)>=m)ans=mid,l=mid+1;
		else r=mid-1;
	}
	//
	ll res=1ll*(m-check(ans))*ans;
	/*cout<<check(3)<<"@\n";
	cout<<check(4)<<"@\n";
	cout<<check(5)<<"@\n";
	cout<<check(6)<<"@\n";
	cerr<<ans<<"@@\n";
	cerr<<check(ans)<<"@\n";*/
	{//
		ll sum=0;
		tt[0]=1e9;
		//cg(0,1e9);
		for(int i=1;i<=n;i++)tt[i]=0;
		int lp=1;
		for(int i=1;i<=n;i++)
		{
			for(auto it:v[i])
			{
				tt[it.id]+=it.op*it.v;
				if(it.id)cg(it.id,it.op*it.v);
				if(lp<=it.id&&it.id<=i)sum+=it.op*it.v;
			}
			while(sum>=ans&&lp<i&&sum-tt[lp]>=ans)sum-=tt[lp++];
			//1lp
			if(sum>=ans)//
				res+=get(n+1-1)-get(n+1-(lp+1));//,cerr<<i<<" "<<get(n+1)<<" "<<lp<<" "<<get(n)<<" "<<sum<<"@#\n";
		}
	}
	cout<<res<<"\n";
	pc('1',1);
	return 0;
}