#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

inline int compute(vector<int> p, int flag){
	int n = (p.size() >> 1);
	for(int i = 0; i <= (n << 1); i++){
		bool check = true;
		for(int j = 0; j < (n << 1); j++){
			if(p[j] != j + 1){
				check = false;
				break;
			}
		}
		if(check)return i;
		if(flag){
			for(int i = 0; i < (n << 1); i += 2){
				swap(p[i], p[i + 1]);
			}
		}else{
			for(int i = 0; i < n; i++){
				swap(p[i], p[n + i]);
			}
		}
		flag ^= 1;
	}
	return -1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n; cin >> n;
	vector<int> p(n << 1);
	for(auto &x : p){
		cin >> x;
	}
	int ans1 = compute(p, 0);
	int ans2 = compute(p, 1);
	if(ans1 == -1)cout << ans2;
	else if(ans2 == -1)cout << ans1;
	else cout << min(ans1, ans2);

	cout << '\n';

	return 0;
}