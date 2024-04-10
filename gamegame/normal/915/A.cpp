#include<iostream>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	int a[101];
	int ans=k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(k%a[i]==0) ans=min(ans,k/a[i]);
	}
	cout << ans << endl;
}