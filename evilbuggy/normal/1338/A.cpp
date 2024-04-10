#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 100005;
int a[N];

void solve(){
	int n;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	int ans = 0;
	for(int i = 1; i < n; i++){
		int tmp = max(0, a[i - 1] - a[i]);
		ans = max(ans, tmp);
		a[i] += tmp;
	}
	int x = 0;
	while(ans){
		ans >>= 1;
		x++;
	}
	cout<<x<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--)solve();

	return 0;
}