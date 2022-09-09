//Author: Heltion
//Date: 2019-06-01
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(const T& s){cout << s; exit(0);}
constexpr int maxn = 360000;
LL s[maxn], t[maxn], si[maxn], ti[maxn];
struct node{
	LL i, j, d;
};
vector<node> ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin >> n;
	LL sum = 0;
	for(int i = 1; i <= n; i += 1) {
		cin >> s[i];
		sum += s[i];
		si[i] = i;
	}
	for(int i = 1; i <= n; i += 1){
		cin >> t[i];
		sum -= t[i];
		ti[i] = i;
	}
	if(sum) no("NO");
	sort(si + 1, si + n + 1, [&](const int &a, const int &b){
		return s[a] < s[b];
	});
	sort(ti + 1, ti + n + 1, [&](const int &a, const int &b){
		return t[a] < t[b];
	});
	sort(s + 1, s + n + 1);
	sort(t + 1, t + n + 1);
	for(int L = 1, R = 1; L <= n;){
		if(s[L] == t[L]){
			L += 1;
			continue;
		}
		if(s[L] > t[L]) no("NO");
		while(s[L] < t[L]){
			while(R <= n and s[R] <= t[R]) R += 1;
			if(R > n) no("NO");
			LL h = min(abs(s[L] - t[L]), abs(s[R] - t[R]));
			s[L] += h;
			s[R] -= h;
			ans.push_back({si[L], si[R], h});
		}
	}
	cout << "YES\n";
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.i << " " << p.j << " " << p.d << "\n";
	}
	return 0;
}