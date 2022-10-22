// Problem: D. Cut
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
vector<int> d[100003];
int st[100003][18];
bool f[100003];
int a[100003];
bool C[100003];
bool can_insert(int x)
{
	for(int i:d[x]) if(C[i]) return 0;
	return 1;
}
void insert(int x)
{
	for(int i:d[x]) C[i]=1;
	return ;
}
void erase(int x)
{
	for(int i:d[x]) C[i]=0;
	return ;
}
signed main()
{
    int n=read(),m=read();
    for(int i=1; i<=n; ++i) a[i]=read();
    for(int j=2; j<=100000; ++j) if(!f[j])
    {
    	for(int i=1; i*j<=100000; ++i) 
    	d[i*j].push_back(j),f[i*j]=1;
    }
    insert(a[1]);
    for(int i=1,r=1; i<=n; ++i)
    {
    	while(r<n&&can_insert(a[r+1])) insert(a[r+1]),++r;
    	st[i][0]=r;
    	erase(a[i]);
    }
    for(int j=0; j<18; ++j) st[n+1][j]=n;
    for(int i=n; i>=1; --i)
    for(int j=1; j<18; ++j)
    st[i][j]=st[st[i][j-1]+1][j-1];
    for(int i=1; i<=m; ++i)
    {
    	int l=read(),r=read();
    	int ans=1;
    	for(int i=17,j=1<<17; i>=0; --i,j>>=1)
    	{
    		if(st[l][i]<r) l=st[l][i]+1,ans+=j;
    	}
    	printf("%lld\n",ans);
    }
	return 0;
}