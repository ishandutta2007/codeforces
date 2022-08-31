#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k;
int a[200001],b[200001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	if(n%2==1){
		cout << "Conan\n";
		return 0;
	}
	int maxi=0;
	for(int i=0; i<n ;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0; i<n ;i++){
		if(a[i]!=a[i^1]){
			cout << "Conan\n";
			return 0;
		}
	}
	cout << "Agasa\n";
	
}