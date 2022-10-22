#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define INF 0x3fffffffffffffff
#define MAXN 600001
int N,M,a[MAXN];ll K,b[MAXN];
bool check(ll x){For(i,1,N)b[i]=0;For(i,1,N)b[max(1,i-M)]+=a[i],b[min(N+1,i+M+1)]-=a[i];ll sum=0,tmp=K;For(i,1,N){sum+=b[i];if(sum<x){if(tmp<x-sum)return 0;b[i]+=x-sum,b[min(N+1,i+2*M+1)]-=x-sum,tmp-=x-sum,sum=x;}}return 1;}
int main(){cin>>N>>M>>K;For(i,1,N)cin>>a[i];ll l=0,r=INF,ans=0;while(l<=r){ll mid=l+r>>1;check(mid)?ans=mid,l=mid+1:r=mid-1;}cout<<ans<<endl;return 0;}