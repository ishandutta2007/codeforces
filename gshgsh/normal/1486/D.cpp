#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int N,K,a[MAXN],b[MAXN],s[MAXN];
bool check(int x){For(i,1,N)b[i]=a[i]>=x?1:-1,s[i]=s[i-1]+b[i];int mn=0;For(i,K,N){mn=min(mn,s[i-K]);if(s[i]-mn>0)return 1;}return 0;}
int main()
{
	cin>>N>>K;For(i,1,N)cin>>a[i];
	int l=1,r=N,ans=1;while(l<=r){int mid=l+r>>1;check(mid)?ans=mid,l=mid+1:r=mid-1;}cout<<ans<<endl;return 0;
}