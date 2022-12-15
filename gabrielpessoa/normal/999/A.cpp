#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef long long ll;

const int ms = 1e3+5, sigma = 26;
const int inf = 0x3f3f3f3f;
const ll mod = 1e9+7;
typedef vector<int> vi;

int a[ms];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int x = inf, y = 0;
	for(int i = 0; i < n; i++) {
		int h;
		cin >> h;
		if(h > k) {
			x = min(x, i);
			y = i;
		}
	}
	cout << n - max(0, 1 + y - x) << endl;
	return 0;
}