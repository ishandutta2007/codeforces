#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
auto read = [](){LL x; cin >> x; return x;};
auto no = [](){cout << "NO"; exit(0);};
#define maxn 20
map<int, int> mp;
priority_queue<pair<int, int> > q;
int a[maxn][maxn];
int main(){
	ios::sync_with_stdio(false);
	int n = read();
	for(int i = 0; i < n * n; i += 1)
		mp[read()] += 1;
	for(const auto &p : mp) q.push(make_pair(p.second, p.first));
	for(int i = 0; i < n / 2; i += 1) for(int j = 0; j < n / 2; j += 1){
		auto p = q.top();
		q.pop();
		if(p.first < 4) no();
		a[i][j] = p.second;
		q.push(make_pair(p.first - 4, p.second));
	}
	if(n % 2){
		for(int i = 0; i < n / 2; i += 1){
			auto p = q.top();
			q.pop();
			if(p.first < 2) no();
			a[n / 2][i] = p.second;
			q.push(make_pair(p.first - 2, p.second));
		}
		for(int i = 0; i < n / 2; i += 1){
			auto p = q.top();
			q.pop();
			if(p.first < 2) no();
			a[i][n / 2] = p.second;
			q.push(make_pair(p.first - 2, p.second));
		}
		a[n / 2][n / 2] = q.top().second; 
	}
	for(int i = 0; i < n / 2; i += 1) for(int j = 0; j < n / 2; j += 1)
		a[n - 1 - i][j] = a[i][n - 1 - j] = a[n - 1 - i][n - 1 - j] = a[i][j];
	if(n % 2){
		for(int i = 0; i < n / 2; i += 1){
			a[n / 2][n - 1 - i] = a[n / 2][i];
			a[n - 1 - i][n / 2] = a[i][n / 2];
		}
	}
	cout << "YES" << endl;
	for(int i = 0; i < n; i += 1){
		for(int j = 0; j < n; j += 1) cout << a[i][j] << " ";
		cout << endl;
	}
}