#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,K,a[MAXN],cnt1[MAXN],cnt2[MAXN];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>N;K=0;For(i,1,N)cnt1[i]=cnt2[i]=0;int mx=0;For(i,1,N)cin>>a[i],cnt1[a[i]]++,mx=max(mx,cnt1[a[i]]),a[i]==a[i-1]?K++,cnt2[a[i-1]]++,cnt2[a[i]]++:0;
		if(mx>(N+1)/2){cout<<-1<<endl;continue;}cnt2[a[1]]++,cnt2[a[N]]++;mx=0;For(i,1,N)mx=max(mx,cnt2[i]);cout<<K+max(mx-K-2,0)<<endl;
	}
	return 0;
}