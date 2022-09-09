#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
auto no = [](){cout << "No"; exit(0);};
auto read = [](){int x; cin >> x; return x;};
#define maxn 120000
int a[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, ma = 0;
	cin >> n; 
	for(int i = 1; i <= n; i += 1){
		cin >> a[i];
		ma = max(ma, a[i]);
	}
	int ans = 0, pans = 0;
	for(int i = 1; i <= n; i += 1){
		if(a[i] == ma) pans += 1;
		else pans = 0;
		ans = max(pans, ans);
	}
	cout << ans;
}