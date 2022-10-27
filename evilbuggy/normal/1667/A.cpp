#include <bits/stdc++.h>
using namespace std;

const int maxn = 5005;
long long a[maxn];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long ans = 1e18;
	for(int i = 1; i <= n; i++){
		long long p = 0;
		{
			long long prev = 0;
			for(int j = i + 1; j <= n; j++){
				prev = (prev/a[j] + 1)*a[j];
				p += prev/a[j];
			}
		}
		long long s = 0;
		{
			long long prev = 0;
			for(int j = i - 1; j >= 1; j--){
				prev = (prev/a[j] + 1)*a[j];
				s += prev/a[j];
			}
		}
		ans = min(ans, p + s);
	}
	cout << ans << '\n';

	return 0;
}