#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P1 998244853
#define P2 100000007
#define B 300
#define base 29
#define MAXN 1000001
int N,M,K,len[MAXN],l[MAXN],pw1[MAXN],pw2[MAXN],hash1[MAXN],hash2[MAXN],tot=1,son[MAXN][26],val[MAXN],id[MAXN],mx[MAXN];multiset<int>v[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int insert(string s){int u=1;for(auto i:s){int x=i-'a';if(!son[u][x])son[u][x]=++tot;u=son[u][x];}v[u].insert(0);return u;}
void calc(string s){int h1=0,h2=0;for(auto i:s){int x=i-'a'+1;h1=(1ll*h1*base+x)%P1,h2=(1ll*h2*base+x)%P2;}hash1[K]=h1,hash2[K]=h2;}
int main()
{
	N=get(),M=get();pw1[0]=pw2[0]=1;For(i,1,MAXN-1)pw1[i]=1ll*pw1[i-1]*base%P1,pw2[i]=1ll*pw2[i-1]*base%P2;
	For(i,1,N){string s;cin>>s;if((len[i]=s.length())<=B)id[i]=insert(s);else id[i]=++K,l[K]=len[i],calc(s);}For(i,1,tot)mx[i]=-1;For(i,1,N)if(len[i]<=B)mx[id[i]]=0;
	while(M--)
	{
		int opt=get();
		if(opt==1){int x=get(),a=get();if(len[x]<=B){int y=id[x];v[y].erase(v[y].find(val[x]));v[y].insert(a);mx[y]=*--v[y].end();}val[x]=a;}
		else
		{
			string s;cin>>s;int L=s.length();vector<int>h1(L+1),h2(L+1);For(i,1,L){int x=s[i-1]-'a'+1;h1[i]=(1ll*h1[i-1]*base+x)%P1,h2[i]=(1ll*h2[i-1]*base+x)%P2;}
			auto H1=[&](int l,int r){return (h1[r]-1ll*h1[l-1]*pw1[r-l+1]%P1+P1)%P1;};
			auto H2=[&](int l,int r){return (h2[r]-1ll*h2[l-1]*pw2[r-l+1]%P2+P2)%P2;};
			int ans=-1;For(i,1,K)For(j,1,L-l[i]+1)if(H1(j,j+l[i]-1)==hash1[i]&&H2(j,j+l[i]-1)==hash2[i])ans=max(ans,val[id[i]]);
			For(i,0,L-1){int u=1;For(j,i,min(L-1,i+B-1)){u=son[u][s[j]-'a'];if(!u)break;ans=max(ans,mx[u]);}}cout<<ans<<'\n';
		}
	}
}