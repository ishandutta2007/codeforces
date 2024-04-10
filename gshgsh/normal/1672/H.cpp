#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,M,a[MAXN],s1[MAXN],s2[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c-'0';}
int main()
{
	N=get(),M=get();For(i,1,N)a[i]=getc();For(i,2,N)s1[i]=(a[i]==0&&a[i-1]==0)+s1[i-1],s2[i]=(a[i]==1&&a[i-1]==1)+s2[i-1];
	For(i,1,M){int l=get(),r=get();cout<<max(s1[r]-s1[l],s2[r]-s2[l])+1<<'\n';}
}