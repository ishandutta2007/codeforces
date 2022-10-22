#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 5001
int N,M,a[MAXN],b[MAXN],cnt[MAXN],ans[MAXN];
int turn(int x){int ans=x>0?1:-1;x*=ans;for(int i=2;i*i<=x;i++)if(x%i==0){while(x%(i*i)==0)x/=i*i;if(x%i==0)ans*=i,x/=i;}if(x>1)ans*=x;return ans;}
int main()
{
	cin>>N;For(i,1,N)cin>>a[i],a[i]?b[++M]=a[i]=turn(a[i]):0;sort(b+1,b+M+1);M=unique(b+1,b+M+1)-b-1;For(i,1,N)if(a[i])a[i]=lower_bound(b+1,b+M+1,a[i])-b;
	For(i,1,N){int sum=0;For(j,i,N){if(a[j])cnt[a[j]]++,sum+=cnt[a[j]]==1;ans[max(sum,1)]++;}For(j,i,N)if(a[j])cnt[a[j]]--;}For(i,1,N)cout<<ans[i]<<' ';return 0;
}