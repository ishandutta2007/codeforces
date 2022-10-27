#include <bits/stdc++.h>
using namespace std;

const int K = 18;
const int N = 100005;
int a[N], lipz[N], lo[N], hi[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, q;
	cin >> n >> q;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	lipz[1] = 0;
	for(int i = 2; i <= n; i++){
		lipz[i] = abs(a[i] - a[i - 1]);
	}
	for(int i = 1; i <= q; i++){
		int l, r;
		cin >> l >> r;
		if(l == r){
			cout << 0 << '\n';
			continue;
		}
		l++;
		lo[l] = l;
		for(int i = l + 1; i <= r; i++){
			lo[i] = i;
			while(lo[i] > l && lipz[lo[i] - 1] < lipz[i]){
				lo[i] = lo[lo[i] - 1];
			}
		}
		hi[r] = r;
		for(int i = r - 1; i >= l; i--){
			hi[i] = i;
			while(hi[i] < r && lipz[hi[i] + 1] <= lipz[i]){
				hi[i] = hi[hi[i] + 1];
			}
		}
		long long ans = 0;
		for(int i = l; i <= r; i++){
			ans += 1LL*(i - lo[i] + 1)*(hi[i] - i + 1)*lipz[i];
		}
		cout << ans << '\n';
	}

	return 0;
}