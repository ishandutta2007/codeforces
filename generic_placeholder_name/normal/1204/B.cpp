#include <bits/stdc++.h>

#define ll long long

using namespace std;
int main () {
	int n, l, r; ll min, max;
	cin>>n>>l>>r;
	min=n-l+1; for (int i=1; i<l; i++) min+=1<<i;
	max=(1<<(r-1))*(n-r+1); for (int i=1; i<r; i++) max+=1<<(i-1);
	cout<<min<<" "<<max;
}