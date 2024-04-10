#include<iostream>
using namespace std;
int s,n;
int a[1001],b[1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> s;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=n ;i++) cin >> b[i];
	if(a[1]==0){
		cout << "NO\n";
		return 0;
	}
	if(a[s]==1){
		cout << "YES\n";
		return 0;
	}
	if(b[s]==0){
		cout << "NO\n";
		return 0;	
	}
	for(int i=n; i>s ;i--){
		if(a[i]==1 && b[i]==1){
			cout << "YES\n";
			return 0;
		}
	}
	cout << "NO\n";
}