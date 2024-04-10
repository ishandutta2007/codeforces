// LUOGU_RID: 91568359
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
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
int n;
map<pair<ll,ll> ,ll>mp;
set<ll>tl,tr;
void _wa(){puts("0");exit(0);}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
map<pair<ll,ll>,pair<ll,ll> >val;
int main(){
//	freopen("a.in","r",stdin);
	n=read();// 
	vector<vector<ll> >v;
	for(int i=1;i<=n;i++)
	{
		vector<ll>l(3);
		for(auto &it:l)it=read();
		tl.insert(l[0]),tr.insert(l[1]);
		v.push_back(l);
	}
	if(tl.size()>tr.size())
	{
		swap(tl,tr);
		for(auto &it:v)swap(it[0],it[1]);
	}
	for(auto &l:v)
		mp[{l[0],l[1]}]=l[2];
	
	for(auto l:tl)
		for(auto r:tr)
			if(!mp.count({l,r}))_wa();
	
//	ll d=0;
//	for(auto &it:v)d=gcd(it[2]);// 
	//check  
	
	ll id=*tl.begin();
	val[{id,0}]={1,1};
	vector<ll>ck;
	for(auto &to:tr)
		val[{to,1}]={mp[{id,to}],1};
	for(auto &to:tl)
	{
		ll al=mp[{to,*tr.begin()}],ar=mp[{id,*tr.begin()}],td=gcd(al,ar);
		al/=td,ar/=td;
		val[{to,0}]={al,ar};
		ck.push_back(ar);
	}
	for(auto l:tl)
		for(auto r:tr)
			if(mp[{l,r}]!=val[{r,1}].first/val[{l,0}].second*val[{l,0}].first)_wa();
	ll d=0;
	for(auto &to:tr)
		d=gcd(d,mp[{id,to}]);
	
	ll ans=0;
	for(ll i=1;i*i<=d;i++)
	{
		if(d%i==0)
		{
			int cr=1;
			for(auto it:ck)if(i%it!=0)cr=0;
			ans+=cr;
			if(d/i!=i)
			{
				cr=1;
				for(auto it:ck)if((d/i)%it!=0)cr=0;
				ans+=cr;
			}
		}
	}
	
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}



}signed main(){return ifzw::main();}