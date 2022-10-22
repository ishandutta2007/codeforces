#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 500001
#define MAXM 1000001
int N,M,c[MAXM];vector<int>a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get();For(i,1,N){int K=get();while(K--)a[i].push_back(get()-1);}
	For(i,2,N)
	{
		int x=0,k=min(a[i-1].size(),a[i].size());while(x<k&&a[i-1][x]==a[i][x])x++;
		if(x==k){if(a[i-1].size()>k){cout<<"-1\n";return 0;}continue;}
		if(a[i-1][x]<a[i][x])c[M-a[i][x]]++,c[M-a[i-1][x]]--;else c[0]++,c[M-a[i-1][x]]--,c[M-a[i][x]]++;
	}
	For(i,1,M-1)c[i]+=c[i-1];For(i,0,M-1)if(!c[i]){cout<<i<<'\n';return 0;}cout<<"-1\n";return 0;
}