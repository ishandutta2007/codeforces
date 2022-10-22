#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int N,M,Q,out[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),M=get();For(i,1,M){int u=get(),v=get();if(u>v)swap(u,v);out[u]++;}int cnt=0;For(i,1,N)cnt+=!out[i];
	Q=get();while(Q--){int opt=get();if(opt==3)cout<<cnt<<'\n';else{int u=get(),v=get();if(u>v)swap(u,v);if(opt&1)out[u]++,cnt-=out[u]==1;else out[u]--,cnt+=!out[u];}}return 0;
}