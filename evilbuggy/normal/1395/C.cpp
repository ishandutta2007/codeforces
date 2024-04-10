#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n, m;
	cin>>n>>m;
	vector<int> a(n), b(m);
	for(auto &x : a){
		cin>>x;
	}
	for(auto &x : b){
		cin>>x;
	}
	vector<vector<int> > pos(n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			pos[i].push_back(a[i]&b[j]);
		}
		sort(pos[i].begin(), pos[i].end());
		pos[i].resize(unique(pos[i].begin(), pos[i].end()) - pos[i].begin());
	}
	for(int mask = 0; mask < 512; mask++){
		bool ok = true;
		for(int i = 0; i < n; i++){
			bool flg = false;
			for(auto x : pos[i]){
				if((x&mask) == x){
					flg = true;
					break;
				}
			}
			if(!flg){
				ok = false;
				break;
			}
		}
		if(ok){
			cout<<mask<<'\n';
			exit(0);
		}
	}


	return 0;
}