#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int a[200005];

int main(){
	int l = 0, r = 0, mx = 0;
	int n; cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	while(l < n && a[l + 1] == 1){
		l++;
	}
	while(a[n - r] == 1 && r < n){
		r++;
	}
	a[0] = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] == 1)a[i] = a[i-1] + 1;
		mx = max(mx, a[i]);
	}
	cout<<max(mx, l + r)<<endl;
}