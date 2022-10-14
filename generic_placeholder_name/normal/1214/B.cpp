#include <bits/stdc++.h>

#define ll long long

using namespace std;
int main() {
	int b, g, n; cin>>b>>g>>n;
	cout<<min(max(b, g), n)-max(n-min(b, g), 0)+1;
}