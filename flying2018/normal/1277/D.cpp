#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<cmath>
#define MP make_pair
#define ll long long
#define P pair<ll,ll>
#define fi first
#define se second
#define N 200010
using namespace std;
string s[N];
P operator +(P a,int b){return MP(a.fi+b,a.se+b);}
P operator *(P a,P b){return MP(a.fi*b.fi,a.se*b.se);}
P operator %(P a,ll b){return MP(a.fi%b,a.se%b);}
const P base=MP(233,677);
const ll mod=1000000007;
set<P >st;
P make_hash(string &s)
{
	int len=s.length();
	P u=MP(0,0);
	for(int i=0;i<len;i++)
	u=(u+(s[i]-'0'+1))*base%mod;
	return u;
}
P make_rev_hash(string &s)
{
	int len=s.length();
	P u=MP(0,0);
	for(int i=len-1;i>=0;i--)
	u=(u+(s[i]-'0'+1))*base%mod;
	return u;
}
int tot[4],opt[N];
int id[N],cnt;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(tot,0,sizeof(tot));
		st.clear();
		cnt=0;
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) cin>>s[i];
		for(int i=1;i<=n;i++)
		{
			int o=0;
			if(s[i][0]=='1') o+=2;
			if(s[i][s[i].length()-1]=='1') o+=1;
			opt[i]=o;
			tot[o]++;
		}
		if(!tot[1] && !tot[2])
		{
			if(tot[0] && tot[3]) puts("-1");
			else puts("0\n");
			continue;
		}
//		if((tot[1]+tot[2])&1){puts("-1");continue;}
		if(abs(tot[1]-tot[2])<2)
		{
//			if(!tot[2] && tot[3])
//			{
//				puts("1");
//				for(int i=1;i<=n;i++)
//				if(opt[i]==1) printf("%d",i);
//				puts("");
//			}
//			else if(!tot[1] && tot[0])
//			{
//				puts("1");
//				for(int i=1;i<=n;i++)
//				if(opt[i]==2) printf("%d",i);
//				puts("");
//			}
//			else
			puts("0\n");
			continue;
		}
		int u=(tot[1]>tot[2])?2:1;
		for(int i=1;i<=n;i++)
		if(opt[i]==u) st.insert(make_hash(s[i]));
		for(int i=1;i<=n;i++)
		if(opt[i]+u==3)
		{
			if(!st.count(make_rev_hash(s[i])))
				id[++cnt]=i;
			if((tot[3-u]-tot[u])/2==cnt) break;
		}
		if((tot[3-u]-tot[u])/2!=cnt){puts("-1");continue;}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++) printf("%d ",id[i]);
		puts("");
	}
	return 0;
}