#include <bits/stdc++.h>

using namespace std;


int main() {
	int n;
	cin>>n;
	int sum=0; 
	int a[10000]; 
	for (int i=1;i<=n;i++) {
		int t;
		cin>>a[i];
		sum+=a[i];  
	}	
	sort(a+1,a+n+1);
	if (int(1.0*sum/n+0.5)==5) {
		cout<<0<<'\n'; 
		return 0; 
	} 
	for (int i=1;i<=n;i++) {
		sum-=a[i]; sum+=5;
		if (int(1.0*sum/n+0.5)==5) {
			cout<<i<<'\n'; 
			break ; 
		}
	}
	return 0; 
}