#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 500001
int T,N,a[MAXN];map<int,int>tot[MAXN];int GCD(int a,int b){return b?GCD(b,a%b):a;}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;For(i,1,N){char c;cin>>c;a[i]=c=='D';}For(i,0,N)tot[i].clear();
		int cnt[2]={0,0};For(i,1,N){cnt[a[i]]++;int x=GCD(cnt[0],cnt[1]);cout<<tot[cnt[0]/x][cnt[1]/x]+1<<' ';tot[cnt[0]/x][cnt[1]/x]++;}cout<<endl;
	}
	return 0;
}