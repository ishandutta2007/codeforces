#include <bits/stdc++.h>

#define ll long long

using namespace std;
int main(){
	int n, a[99], even=0, odd=0; cin>>n; for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n; i++) {
		if(a[i]%2==0) even++; else odd++;
	}
	cout<<min(even, odd);
}