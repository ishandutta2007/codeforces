#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100;
int l[maxn], r[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n;
	for(int i = 0; i < n; i += 1) cin >> l[i] >> r[i];
	cin >> k;
	for(int i = 0; i < n; i += 1) if(k <= r[i]){
		cout << n - i;
		break;
	}
}