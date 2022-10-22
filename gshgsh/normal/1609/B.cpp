#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,M,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c<'a'||c>'c')c=getchar();return c-'a';}
void upd(int&sum,int x,int v){if(x>1&&x<N)sum+=v*(a[x-1]==0&&a[x]==1&&a[x+1]==2);}
int main()
{
	N=get(),M=get();For(i,1,N)a[i]=getc();int ans=0;For(i,2,N-1)upd(ans,i,1);
	For(i,1,M){int x=get(),v=getc();For(j,-2,2)upd(ans,x+j,-1);a[x]=v;For(j,-2,2)upd(ans,x+j,1);cout<<ans<<'\n';}return 0;
}