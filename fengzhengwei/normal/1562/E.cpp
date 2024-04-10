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
const int xx=5005;
char s[xx];
int T;
vector<pair<int,int> >v[xx];
int rk[xx],sa[xx],t[xx],old[xx<<1],id[xx],h[xx],mn[xx][14],lg[xx],p,n,m;
void pre()
{
	n=strlen(s+1);
	m=500;
	memset(sa,0,sizeof(sa));
	memset(t,0,sizeof(t));
	memset(old,0,sizeof(old));
	for(int i=1;i<=n;i++)t[rk[i]=s[i]]++;
	for(int i=1;i<=m;i++)t[i]+=t[i-1];
	for(int i=1;i<=n;i++)sa[t[rk[i]]--]=i;
	for(int l=1;l<=n;l<<=1,m=p)
	{
		p=0;
		for(int i=n-l+1;i<=n;i++)id[++p]=i;
		for(int i=1;i<=n;i++)if(sa[i]>l)id[++p]=sa[i]-l;
		for(int i=1;i<=m;i++)t[i]=0;
		for(int i=1;i<=n;i++)t[rk[i]]++;
		for(int i=1;i<=m;i++)t[i]+=t[i-1];
		for(int i=n;i>=1;i--)sa[t[rk[id[i]]]--]=id[i];
		for(int i=1;i<=n;i++)old[i]=rk[i];p=0;
		for(int i=1;i<=n;i++)rk[sa[i]]=(old[sa[i]]==old[sa[i-1]]&&old[sa[i]+l]==old[sa[i-1]+l])?p:++p;
		if(p==n)break;
	}
	p=0;
	memset(mn,0x3f,sizeof(mn));
	for(int i=1;i<=n;i++)
	{
		if(p)p--;
		while(s[i+p]==s[sa[rk[i]-1]+p])p++;
		h[rk[i]]=p;
		mn[rk[i]][0]=p;
	}
	for(int j=1;j<=13;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(i+(1<<j-1)<=n)mn[i][j]=min(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
			else mn[i][j]=mn[i][j-1];
		}
	}
}
int lcp(int a,int b)
{
	if(a==b)return n-sa[a]+1;
//	a=rk[a],b=rk[b];
	if(a>b)swap(a,b);a++;
	int k=lg[b-a+1];
	return min(mn[a][k],mn[b-(1<<k)+1][k]);
}
int f[xx][xx];
int main(){
//	cout<<sizeof(f)/1024/1024<<'\n';
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	int T=read();
	while(T--)
	{
		n=read();
		scanf("%s",s+1);
		pre();
//		return 0;
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n-sa[i]+1;j++)f[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			int now=1,len=0,res=0,p=rk[i];
			for(int j=1;j<=n-i+1;j++)
			{
				while(lcp(p,now)<j)res=max(res,f[now][n-sa[now]+1]),now++;
				// 
				res=max(res,f[p][j-1]);
				f[p][j]=res+1;
//				cout<<i<<" "<<j<<" "<<res+1<<"\n";
			}
		}
		for(int i=1;i<=n;i++)ans=max(ans,f[i][n-sa[i]+1]);
		cout<<ans<<'\n';
	}
	return 0;
}