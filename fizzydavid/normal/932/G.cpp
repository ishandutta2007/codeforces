//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
const int maxn=1000111;
char s[maxn];
int n,tot,go[maxn][26],fail[maxn],slink[maxn],len[maxn],dlen[maxn];
int st[maxn];
int append(int p,int l)
{
	int c=s[l]-'a';
	while(s[l-len[p]-1]!=s[l])p=fail[p];
	if(!go[p][c])
	{
		int np=++tot;
		len[np]=len[p]+2;
		int t=fail[p];
		while(s[l-len[t]-1]!=s[l])t=fail[t];
		fail[np]=go[t][c];
		dlen[np]=len[np]-len[fail[np]];
		slink[np]=dlen[np]==dlen[fail[np]]?slink[fail[np]]:fail[np];
		go[p][c]=np;
	}
	return go[p][c];
}
int dp[maxn],gdp[maxn];
void upd(int &x,int v){x=x+v>=mod?x+v-mod:x+v;}
int main()
{
	static char ss[maxn];
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n/2;i++)ss[i*2-1]=s[i];
	reverse(s+n/2+1,s+n+1);
	for(int i=1;i<=n/2;i++)ss[i*2]=s[i+n/2];
	swap(s,ss);
	int p=1;
	tot=1;
	len[1]=-1;fail[0]=1;st[0]=1;
	for(int i=1;i<=n;i++)
	{
		p=append(p,i);
		st[i]=p;
	}
	/*
	for(int i=1;i<=n;i++)cerr<<fail[i]<<" ";cerr<<endl;
	for(int i=1;i<=n;i++)cerr<<len[i]<<" ";cerr<<endl;
	for(int i=1;i<=n;i++)cerr<<slink[i]<<" ";cerr<<endl;
	for(int i=1;i<=n;i++)cerr<<dlen[i]<<" ";cerr<<endl;
	*/
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		//cerr<<"i="<<i<<endl;
		for(int p=st[i];p;p=slink[p])
		{
			int cur=dp[i-(len[slink[p]]+dlen[p])];
			//cerr<<p<<":"<<len[p]<<" "<<dlen[p]<<" "<<slink[p]<<" "<<cur<<endl;
			gdp[p]=cur;
			if(dlen[p]==dlen[fail[p]])
			{
				upd(gdp[p],gdp[fail[p]]);
			}
			if(i%2==0)upd(dp[i],gdp[p]);
		}
		//cerr<<dp[i]<<" ";cerr<<endl;
	}
	cout<<dp[n]<<endl;
	return 0;
}