
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[1005],sum=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i+=2){
		ll sl=1,sr=a[i];
		for(int j=i+1;j<=n;j++){
			if(j%2==0){
				if(sl>a[j]){
					sl-=a[j],sr-=a[j];
					continue;
				}
				sum+=min(a[j],sr)-sl+1;
				sl=0,sr-=a[j];
				if(sl>sr)break;
			}
			else sl+=a[j],sr+=a[j];
		}
	}
	cout<<sum;
}