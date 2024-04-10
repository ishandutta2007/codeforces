#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int mod=998244353;
int n,m,k;
ll ksm(ll a,ll b)
{
//	cout<<a<<" sss "<<b<<"\n";
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
const int xx=1e6+5;
int op[xx][2],sm[xx],ct;
// 
int ct1,oph[xx][2],u[2];
map<pair<int,int> ,int>mp;
signed main(){
	n=read(),m=read(),k=read();
	ll emp=m;
	ll emp1=n;
	for(int i=1;i<=k;i++)
	{
		int x=read(),y=read(),z=read();
		if(z==-1)
		{
			if(mp.find(make_pair(x,y))!=mp.end())
			{
				ct-=(op[y][0]&&op[y][1]);
				ct1-=(oph[x][0]&&oph[x][1]);
				u[0^((y-1)&1)]-=op[y][0];
				u[1^((y-1)&1)]-=op[y][1];
				op[y][mp[make_pair(x,y)]^((x-1)&1)]--;
				oph[x][mp[make_pair(x,y)]^((y-1)&1)]--;
				if(!op[y][0]&&!op[y][1])emp++;
				if(!oph[x][0]&&!oph[x][1])emp1++;
				mp.erase(mp.find(make_pair(x,y)));
				u[0^((y-1)&1)]+=op[y][0];
				u[1^((y-1)&1)]+=op[y][1];
				ct+=(op[y][0]&&op[y][1]);
				ct1+=(oph[x][0]&&oph[x][1]);
			}
		}
		else 
		{
			ct-=(op[y][0]&&op[y][1]);
			ct1-=(oph[x][0]&&oph[x][1]);
			u[0^((y-1)&1)]-=op[y][0];
			u[1^((y-1)&1)]-=op[y][1];
			if(mp.find(make_pair(x,y))!=mp.end())op[y][mp[make_pair(x,y)]^((x-1)&1)]--,oph[x][mp[make_pair(x,y)]^((y-1)&1)]--;
			else 
			{
				if(!op[y][0]&&!op[y][1])emp--;
				if(!oph[x][0]&&!oph[x][1])emp1--;
			}
			mp[make_pair(x,y)]=z;
			op[y][mp[make_pair(x,y)]^((x-1)&1)]++;
			oph[x][mp[make_pair(x,y)]^((y-1)&1)]++;
			ct+=(op[y][0]&&op[y][1]);
			ct1+=(oph[x][0]&&oph[x][1]);
			u[0^((y-1)&1)]+=op[y][0];
			u[1^((y-1)&1)]+=op[y][1];
		}
//		cout<<ct<<" "<<ct1<<"\n";
		ll ans=0;
		if(!ct)ans+=ksm(2,emp);
		if(!ct1)
		{
			ans-=(ct==0&&((u[0]>0)^(u[1]>0)));
//			ans-=(ct==0);// 
			ans-=(emp==m)*2;
			ans+=ksm(2,emp1);
		}
		cout<<ans%mod<<"\n";
	}
    return 0;
}