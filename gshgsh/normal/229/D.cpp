#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 5001
int N,a[MAXN],f[MAXN][MAXN],ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
    N=get();For(i,1,N)For(j,0,i)f[i][j]=N+1;For(i,1,N)a[i]=get()+a[i-1],f[i][0]=i-1;
    For(j,1,N-1){int k=j,mn=N+1;For(i,j+1,N){while(k&&a[i]-a[j]>=a[j]-a[k-1])mn=min(mn,f[j][--k]);f[i][j]=mn+i-j-1;}}
    ans=N+1;For(i,0,N-1)ans=min(ans,f[N][i]);cout<<ans<<endl;return 0;
}