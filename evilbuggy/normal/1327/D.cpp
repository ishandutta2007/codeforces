#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int N = 200005;
int p[N], c[N], vis[N];

inline int compute(vector<int> &v){
	int n = v.size();
	for(int k = 1; k <= n; k++){
		if(n%k)continue;
		for(int i = 0; i < k; i++){
			int flg = true;
			for(int j = i + k; j < n; j += k){
				if(c[v[j]] != c[v[j-k]]){
					flg = false;
					break;
				}
			}
			if(flg)return k;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i = 1; i <= n; i++){
			cin>>p[i];
			vis[i] = 0;
		}
		for(int i = 1; i <= n; i++){
			cin>>c[i];
		}
		int ans = -1;
		for(int i = 1; i <= n; i++){
			if(!vis[i]){
				vector<int> cycle;
				int v = i;
				while(p[v] != i){
					cycle.push_back(v);
					vis[v] = 1;
					v = p[v];
				}
				cycle.push_back(v);
				vis[v] = 1;
				int tmp = compute(cycle);
				if(ans == -1 || ans > tmp)ans = tmp;
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}