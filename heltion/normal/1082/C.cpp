#include<bits/stdc++.h>
#define maxn 120000
using namespace std;
typedef long long LL;
vector<int> v[maxn];
int ans[maxn];
int main(){
	ios::sync_with_stdio(false);
	int n, m; 
	cin >> n >> m;
	for(int i = 0; i < n; i += 1){
		int s, r;
		cin >> s >> r;
		v[s].push_back(r);
	}
	for(int i = 1; i <= m; i += 1){
		sort(v[i].begin(), v[i].end(), greater<int>());
		int p = 0;
		for(int j = 0; j < v[i].size(); j += 1){
			p += v[i][j];
			if(p >= 0) ans[j] += p;
		}
	}
	int an = 0;
	for(int i = 0; i < n; i += 1) an = max(an, ans[i]);
	cout << an;
}