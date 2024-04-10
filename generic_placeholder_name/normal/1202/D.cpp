#include <bits/stdc++.h>

#define ll long long

using namespace std;
int main() {
	int q; cin>>q;
	for(int l=1; l<=q; l++) {
		int n; cin>>n; int k=2; while(k*(k-1)/2<=n) k++; k--;
		cout<<133; for(int i=1; i<=n-k*(k-1)/2; i++) cout<<7; for(int i=1; i<=k-2; i++) cout<<3; cout<<7<<endl;
	}
}