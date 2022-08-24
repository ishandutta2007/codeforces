#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long a[n+1],b[n+1];
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=n ;i++) cin >> b[i];
	long long ans=0;
	for(int i=1; i<=n ;i++){
		if(a[i]*2<b[i] || b[i]==1){
			ans--;
		}
		else{
			ans+=(b[i]/2)*(b[i]-b[i]/2);
		}
	}
	cout << ans << endl;
}