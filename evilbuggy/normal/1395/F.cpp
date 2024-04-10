#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 3e5 + 35;
const int M = 1e6 + 16;

inline int func(int x, int y, int mny, int mxy, int mnz, int mxz){
	int z = - y - x;
	return max({abs(y - mny), abs(y - mxy), abs(z - mnz), abs(z - mxz)});
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	vector<int> x, y, z;
	for(int i = 1; i <= n; i++){
		string s; cin>>s;
		int b = 0, n = 0;
		for(auto ch : s){
			if(ch == 'B')b++;
			else n++;
		}
		x.push_back(b);
		y.push_back(-n);
		z.push_back(n - b);
	}
	int mnx = *min_element(x.begin(), x.end());
	int mny = *min_element(y.begin(), y.end());
	int mnz = *min_element(z.begin(), z.end());
	int mxx = *max_element(x.begin(), x.end());
	int mxy = *max_element(y.begin(), y.end());
	int mxz = *max_element(z.begin(), z.end());
	int ans = 1e9, ans_x = 0, ans_y = 0;
	for(int xx = 0; xx <= M; xx++){
		int tmp = max(abs(mnx - xx), abs(mxx - xx));
		int lo = 0, hi = M;
		while(lo < hi){
			int mi = lo + (hi - lo)/2;
			if(func(xx, -mi, mny, mxy, mnz, mxz) < func(xx, -mi - 1, mny, mxy, mnz, mxz))hi = mi;
			else lo = mi + 1;
		}
		int val = max(tmp, func(xx, -lo, mny, mxy, mnz, mxz));
		if(ans > val && xx + lo > 0){
			ans = val;
			ans_x = xx;
			ans_y = lo;
		}
	}
	cout<<ans<<'\n';
	while(ans_x--){
		cout<<'B';
	}
	while(ans_y--){
		cout<<'N';
	}

	return 0;
}