#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define LL long long
#define gc getchar
#define Pair pair<int,int>
#define fi first
#define mp make_pair
#define se second
#define ld long double
const int mxn=210;
const LL inf=1e18;
int n,fa[mxn],g[mxn][mxn];
LL res,a[mxn][mxn],f[mxn][mxn];
inline int rd(){
    int s=0,w=1,ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
LL S(int x1,int x2,int y1,int y2) {return a[x2][y2]-a[x2][y1-1]-a[x1-1][y2]+a[x1-1][y1-1];}
void dfs(int l,int r,int F)
{
	if(l>r) return ;
	fa[g[l][r]]=F;
	dfs(l,g[l][r]-1,g[l][r]);
	dfs(g[l][r]+1,r,g[l][r]);
}
int main(){
    n=rd();
    for(int x,i=1;i<=n;++i)
    	for(int j=1;j<=n;++j)
    	{
    		x=rd();
    		a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+x;
    	}
    for(int i=1;i<=n;++i)
    	for(int j=i;j<=n;++j)
    		g[i][j]=j;
    for(int i=2;i<=n;++i)
	    for(int l=1,r=i;r<=n;++l,++r)
	    {
	    	f[l][r]=inf;
	    	for(int k=l;k<=r;++k)
	    	{
	    		res=f[l][k-1]+f[k+1][r];
	    		res-=S(l,k,r+1,n)*(r-k)+S(k,r,1,l-1)*(k-l);
//	    		res-=S(1,l-1,r+1,n)*2;
	    		res+=S(l,k-1,1,l-1)+S(k+1,r,r+1,n);
	    		if(res<f[l][r]) f[l][r]=res,g[l][r]=k;
	    	}
	    }
	dfs(1,n,0);
	for(int i=1;i<=n;++i) printf("%d%c",fa[i]," \n"[i==n]);
	return 0;
}
/*
4
0 566 1 114514
566 0 239 30
1 239 0 1
114514 30 1 0
*/