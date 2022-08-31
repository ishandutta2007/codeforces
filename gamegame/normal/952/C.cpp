#include<iostream>
using namespace std;
int a[11];
int main(){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int maxi=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		maxi=max(maxi,a[i]);
	}
	bool ok=true;
	for(int i=1; i<n ;i++){
		if(abs(a[i]-a[i+1])<2) continue;
		ok=false; 
	}
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}