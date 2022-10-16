#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e6+5;
int T,n,k;
char s[xx];
int old[xx];
int rk[xx];
int sa[xx];
int t[xx];
int id[xx];
int h[xx];
int m,p;
void pre()
{
	m=500;
	for(int i=1;i<=n;i++)t[rk[i]=s[i]]++;
	for(int i=1;i<=m;i++)t[i]+=t[i-1];
	for(int i=1;i<=n;i++)sa[t[rk[i]]--]=i;
	for(int w=1;w<n;w<<=1,m=p)
	{
		p=0;
		for(int i=n-w+1;i<=n;i++)id[++p]=i;
		for(int i=1;i<=n;i++)if(sa[i]>w)id[++p]=sa[i]-w;
		for(int i=1;i<=m;i++)t[i]=0;
		for(int i=1;i<=n;i++)t[rk[i]]++;
		for(int i=1;i<=m;i++)t[i]+=t[i-1];
		for(int i=n;i>=1;i--)sa[t[rk[id[i]]]--]=id[i];
		for(int i=1;i<=n;i++)old[i]=rk[i];p=0;
		for(int i=1;i<=n;i++)rk[sa[i]]=(old[sa[i]]==old[sa[i-1]]&&old[sa[i]+w]==old[sa[i-1]+w])?p:++p;
		if(p==n)break;
	}
}
signed main(){
//	freopen("a.in","r",stdin);
//	T=read();
//	while(T--)
//	{
		n=read();
		k=read();
		scanf("%s",s+1);
		for(int i=n+1;i<=n+n;i++)s[i]=s[i-n];
		n=n+n;
		pre();
		n/=2;
		int tot=0;
		for(int i=2;i<=n;i++)
		{
//			cout<<i<<"\n";
			if(rk[1]<rk[i]){tot=i;break;}
//			int a=i,b=0;
//			while(s[a]==s[b])
//			{
//				a++;b++;
//				a%=n;b%=i;
//				if(a==i&&b==0)break;
//			}
////			cout<<i<<" "<<a<<" "<<b<<"\n";
//			if(s[b]<s[a]){tot=i;break;}
		}
//		cout<<tot<<"\n";
		if(tot==0)tot=n+1;
		tot--;
		for(int i=1;i<=k;i++)cout<<s[(i-1)%tot+1];
		puts("");
//	}
	
	return 0;
}