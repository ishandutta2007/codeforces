#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 2001
int N,M,K,ans1[MAXN],ans;struct A{int l,r;bool operator<(A a)const{return l+r<a.l+a.r;};}a[MAXN];
int main()
{
	cin>>N>>M>>K;For(i,1,M)cin>>a[i].l>>a[i].r;sort(a+1,a+M+1);For(i,1,N-K+1){int j=i+K-1,sum=0;For(k,1,M)ans1[k]=max(ans1[k],sum+=max(min(j,a[k].r)-max(i,a[k].l)+1,0));}
	For(i,1,N-K+1){int j=i+K-1,sum=0;FOR(k,M,1)ans=max(ans,ans1[k-1]+(sum+=max(min(j,a[k].r)-max(i,a[k].l)+1,0)));}cout<<ans<<endl;return 0;
}