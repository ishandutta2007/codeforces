#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
#define MAXB 1001
int N,M,B,K,l[MAXB],r[MAXB],pos[MAXN],a[MAXN],v[MAXB][MAXB];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int ask(int l,int r,int x,int y)
{
	int lB=(l-1)/B+1,rB=(r-1)/B+1;if(lB==rB){int ans=0;For(i,l,r)ans+=a[i]>=x&&a[i]<=y;return ans;}
	int ans=0;For(i,l,::r[lB])ans+=a[i]>=x&&a[i]<=y;For(i,::l[rB],r)ans+=a[i]>=x&&a[i]<=y;
	For(i,lB+1,rB-1)ans+=upper_bound(v[i],v[i]+::r[i]-::l[i]+1,y)-lower_bound(v[i],v[i]+::r[i]-::l[i]+1,x);return ans;
}
void ssh(int x,int y)
{
	swap(a[x],a[y]);int xB=(x-1)/B+1,yB=(y-1)/B+1;
	For(i,l[xB],r[xB])v[xB][i-l[xB]]=a[i];sort(v[xB],v[xB]+r[xB]-l[xB]+1);
	For(i,l[yB],r[yB])v[yB][i-l[yB]]=a[i];sort(v[yB],v[yB]+r[yB]-l[yB]+1);
}
int main()
{
	N=get(),M=get();B=sqrt(N);For(i,1,N)pos[get()]=i;For(i,1,N)a[i]=pos[get()];
	while(r[K]<N)K++,l[K]=r[K-1]+1,r[K]=min(K*B,N);For(i,1,K){For(j,l[i],r[i])v[i][j-l[i]]=a[j];sort(v[i],v[i]+r[i]-l[i]+1);}
	For(i,1,M){int opt=get(),x=get(),y=get();if(opt==1){int l=get(),r=get();cout<<ask(l,r,x,y)<<'\n';}else ssh(x,y);}return 0;
}