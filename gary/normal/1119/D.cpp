#include<bits/stdc++.h>
using namespace std;
long long  n,a[100001];
long long bad[100001];
long long sum[100001];
//int *cha[100001];
int main(){
//	freopen("Out.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	bad[1]=1e18;
	bad[1]++; 
	for(int i=2;i<=n;i++){
		bad[i]=a[i]-a[i-1];
	}
	sort(bad+1,bad+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+bad[i];
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		long long l,r;
		cin>>l>>r;
		long long cha=r-l+1;
		long long ans=0;
		long long j;
		long long L=-1,R=n;//(L,R]
		while(R-L>1){
			long long mid=(L+R)/2;
			if(bad[mid]<=cha) L=mid;
			else R=mid;
		}
		j=L+1;
//		for(j=1;j<=n;j++){//find the smallest j that bigger than cha
//			if(bad[j]<=cha){
////				ans+=bad[j];
//			}
//			else{
//				break;
//			}
//		}
		ans+=sum[j-1]+(n-j+1)*cha;
		cout<<ans<<" ";
	}
	return 0;
}