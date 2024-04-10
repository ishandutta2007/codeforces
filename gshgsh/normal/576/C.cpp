#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define getchar() In[pos++]
#define MAXN 1000001
#define B 1000
int N,x[MAXN],y[MAXN],p[MAXN];char In[18000100];int pos;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool cmp(const int&a,const int&b){return x[a]/B==x[b]/B?x[a]/B&1?y[a]<y[b]:y[a]>y[b]:x[a]<x[b];}
int main()
{
	fread(In,1,18000000,stdin);N=get();For(i,1,N)x[i]=get(),y[i]=get(),p[i]=i;
	stable_sort(p+1,p+N+1,cmp);For(i,1,N)cout<<p[i]<<" \n"[i==N];return 0;
}