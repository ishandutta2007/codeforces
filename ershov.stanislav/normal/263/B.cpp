#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int n, k;
int main(){
	cin >> n >> k;
	v.resize(n);
	for (int i=0; i<n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	if (n<k) cout << -1;
	else if (n==1) cout << "0 0";
	else if (v[n-k]==v[n-k+1]) cout << -1;
	else cout << 0 << ' ' << v[n-k];
	return 0;
}