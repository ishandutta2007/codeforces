#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1001
int N,K,ans[MAXN][MAXN],mul[MAXN];
int main()
{
	cin>>N>>K;mul[0]=1;int tot=0;while(mul[tot]<N)mul[tot+1]=mul[tot]*K,tot++;
	cout<<tot<<'\n';For(i,0,N-1)For(j,i+1,N-1){int id=0;while(i/mul[id]!=j/mul[id])id++;cout<<id<<' ';}cout<<'\n';return 0;
}