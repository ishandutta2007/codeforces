#include<iostream>
#include<algorithm>
using namespace std;
int n;
int c[200001],t[200001],a[200001],b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> c[i];
		if(i!=1) a[i-1]=c[i]-c[i-1]; 
	}
	for(int i=1; i<=n ;i++){
		cin >> t[i];
		if(i!=1) b[i-1]=t[i]-t[i-1];
	}
	if(c[1]!=t[1] || c[n]!=t[n]){
		cout << "No\n";return 0;
	}
	sort(a+1,a+n);sort(b+1,b+n);
	for(int i=1; i<n ;i++){
		if(a[i]!=b[i]){
			cout << "No\n";return 0;
		}
	}
	cout << "Yes\n";
}