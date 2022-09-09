#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1200;
void no(){
	cout << "NO";
	exit(0);
}
LL a[maxn];
bool test(int n, LL h){
	LL s = 0;
	vector<LL> v;
	for(int i = 1; i <= n; i += 1) v.push_back(a[i]);
	sort(v.begin(), v.end(), greater<int>());
	for(int i = 0; i < v.size(); i += 2) s += v[i];
	return s <= h;
}
int main(){
	ios::sync_with_stdio(false);
	int n, ans = 0;
	LL h;
	cin >> n >> h;
	for(int i = 1; i <= n; i += 1) cin >> a[i];
	for(int i = 1; i <= n; i += 1) if(test(i, h)) ans = i;
	cout << ans;
}