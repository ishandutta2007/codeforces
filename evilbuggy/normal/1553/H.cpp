#include <bits/stdc++.h>
using namespace std;

struct Data{
	int cnt;
	vector<int> difval, minval, maxval;
};

const int N = 1 << 19;
const int inf = (int)1e9;
int a[N];

Data f(int d, int l, int r){
	if(d == 0){
		Data ret;
		ret.minval.emplace_back(+inf);
		ret.maxval.emplace_back(-inf);
		ret.difval.emplace_back(+inf);
		if(a[l])ret.minval[0] = 0;
		if(a[l])ret.maxval[0] = 0;
		ret.cnt = a[l];
		return ret;
	}
	Data ret;
	int m = (l + r)/2;
	Data lo = f(d - 1, l, m);
	Data hi = f(d - 1, m + 1, r);
	ret.cnt = lo.cnt + hi.cnt;
	ret.minval.resize(1 << d);
	ret.maxval.resize(1 << d);
	ret.difval.resize(1 << d);

	int x = 1 << (d - 1);
	for(int i = 0; i < x; i++){
		if(lo.cnt == 0 && hi.cnt == 0){
			ret.minval[i] = inf;
			ret.maxval[i] = inf;
			ret.difval[i] = inf;
			ret.minval[i^x] = inf;
			ret.maxval[i^x] = inf;
			ret.difval[i^x] = inf;
		}else if(lo.cnt == 0){
			ret.minval[i] = hi.minval[i]^x;
			ret.maxval[i] = hi.maxval[i]^x;
			ret.difval[i] = hi.difval[i];
			ret.minval[i^x] = hi.minval[i];
			ret.maxval[i^x] = hi.maxval[i];
			ret.difval[i^x] = hi.difval[i];
		}else if(hi.cnt == 0){
			ret.minval[i] = lo.minval[i];
			ret.maxval[i] = lo.maxval[i];
			ret.difval[i] = lo.difval[i];
			ret.minval[i^x] = lo.minval[i]^x;
			ret.maxval[i^x] = lo.maxval[i]^x;
			ret.difval[i^x] = lo.difval[i];
		}else{
			ret.minval[i] = lo.minval[i];
			ret.maxval[i] = hi.maxval[i]^x;
			ret.minval[i^x] = hi.minval[i];
			ret.maxval[i^x] = lo.maxval[i]^x;
			ret.difval[i] = min({lo.difval[i], hi.difval[i], (hi.minval[i]^x) - lo.maxval[i]});
			ret.difval[i^x] = min({lo.difval[i], hi.difval[i], (lo.minval[i]^x) - hi.maxval[i]});
		}
	}
	// cout << d << " " << l << " " << r << endl;
	// cout << "difval : ";
	// for(auto x : ret.difval){
	// 	cout << x << " ";
	// }
	// cout << endl;
	// cout << "maxval : ";
	// for(auto x : ret.maxval){
	// 	cout << x << " ";
	// }
	// cout << endl;
	// cout << "minval : ";
	// for(auto x : ret.minval){
	// 	cout << x << " ";
	// }
	// cout << endl;
	// cout << endl;
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	memset(a, 0, sizeof(a));
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		a[x] = 1;
	}
	Data uwu = f(k, 0, (1 << k) - 1);
	for(int i = 0; i < (1 << k); i++){
		cout << uwu.difval[i] << " ";
	}
	cout << '\n';
	// for(int x = 0; x < (1 << k); x++){
	// 	int ans = -inf;
	// 	for(int i = 0; i < (1 << k); i++){
	// 		if(a[i])ans = max(ans, i^x);
	// 	}
	// 	cout << ans << " ";
	// }
	// cout << '\n';

	return 0;
}