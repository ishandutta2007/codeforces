#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[400005],b[400005],ans=0;
ll C(int x){
	ll ret=0;
	for(int i=1;i<=n;i++)b[i]=a[i]&((1<<x+1)-1);
	sort(b+1,b+n+1);
	for(int i=1,j=n+1;i<=n;i++){
		while(j>i+1&&b[i]+b[j-1]>=(1<<x))j--;
		j=max(j,i+1);
		ret+=n-j+1;
	}
	for(int i=1,j=n+1;i<=n;i++){
		while(j>i+1&&b[i]+b[j-1]>=(1<<x+1))j--;
		j=max(j,i+1);
		ret-=n-j+1;
	}
	for(int i=1,j=n+1;i<=n;i++){
		while(j>i+1&&b[i]+b[j-1]>=((1<<x+1)+(1<<x)))j--;
		j=max(j,i+1);
		ret+=n-j+1;
	}
	return ret;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<=25;i++)if(C(i)&1)ans^=(1<<i);
	cout<<ans;
    return 0;
}