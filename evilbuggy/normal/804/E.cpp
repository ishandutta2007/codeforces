#include <bits/stdc++.h>
using namespace std;

inline void cross4(int a, int b, vector<pair<int, int> > &ans){
	for(int d : {0, 2, 1, 3}){
		for(int i = 0; i < 4; i++){
			int j = (d + i) & 3;
			ans.emplace_back(a + i, b + j);
		}
	}
}

inline void solve4(int a, vector<pair<int, int> > &ans){
	ans.emplace_back(a + 0, a + 1);
	ans.emplace_back(a + 2, a + 3);
	ans.emplace_back(a + 0, a + 2);
	ans.emplace_back(a + 1, a + 3);
	ans.emplace_back(a + 0, a + 3);
	ans.emplace_back(a + 1, a + 2);
}

inline void solve5(int a, int b, int c, int d, int e, vector<pair<int, int> > &ans){
	ans.emplace_back(a, c);
	ans.emplace_back(a, d);
	ans.emplace_back(b, c);
	ans.emplace_back(b, e);
	ans.emplace_back(c, e);
	ans.emplace_back(a, e);
	ans.emplace_back(c, d);
	ans.emplace_back(b, d);
	ans.emplace_back(d, e);
	ans.emplace_back(a, b);
}

inline int solve(int n, vector<pair<int, int> > &ans){
	if(n == 1)return 1;
	if(n%4 == 0){
		for(int i = 1; i <= n; i += 4){
			solve4(i, ans);
		}
		for(int i = 1; i <= n; i += 4){
			for(int j = i + 4; j <= n; j += 4){
				cross4(i, j, ans);
			}
		}
		return 1;
	}else if(n%4 == 1){
		for(int i = 2; i <= n; i += 4){
			solve5(1, i + 0, i + 1, i + 2, i + 3, ans);
		}
		for(int i = 2; i <= n; i += 4){
			for(int j = i + 4; j <= n; j += 4){
				cross4(i, j, ans);
			}
		}
		return 1;
	}
	return 0;
}

inline bool check(int n, vector<pair<int, int> > &ans){
	if(ans.size() != n*(n - 1)/2)return false;
	vector<int> perm(n);
	iota(perm.begin(), perm.end(), 0);
	for(auto x : ans){
		swap(perm[x.first - 1], perm[x.second - 1]);
	}
	for(int i = 0; i < n; i++){
		if(perm[i] != i)return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int> > ans;
	if(solve(n, ans)){
		cout << "YES" << '\n';
		for(auto x : ans){
			cout << x.first << " " << x.second << '\n';
		}
	}else{
		cout << "NO" << '\n';
	}

	return 0;
}