#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 5e5 + 55;
int t[N], a[N], b[N];
vector<int> g[N], c[N];
bool arr[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a[i] >> b[i];
		g[a[i]].push_back(b[i]);
		g[b[i]].push_back(a[i]);
	}
	for(int i = 1; i <= n; i++){
		cin >> t[i];
		c[t[i]].push_back(i);
	}
	for(int i = 0; i < m; i++){
		if(t[a[i]] == t[b[i]]){
			cout << -1 << '\n';
			exit(0);
		}
	}
	memset(arr, false, sizeof(arr));
	for(int i = 1; i <= n; i++){
		for(int v : c[i]){
			set<int> st;
			for(int u : g[v]){
				if(t[u] < i)arr[t[u]] = true;
			}
			for(int j = 1; j < i; j++){
				if(!arr[j]){
					cout << -1 << '\n';
					exit(0);
				}
				arr[j] = false;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(auto x : c[i]){
			cout << x << " ";
		}
	}
	cout << '\n';


	return 0;
}