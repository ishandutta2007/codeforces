#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

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
		vector<int> g[n];
		vector<int> a(n, -1), b(n, -1);
		for(int i = 0; i < n; i++){
			int k, x;
			cin>>k;
			while(k--){
				cin>>x; x--;
				g[i].push_back(x);
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(auto x : g[i]){
				if(b[x] == -1){
					a[i] = x;
					b[x] = i;
					cnt++;
					break;
				}
			}
		}
		if(cnt == n){
			cout<<"OPTIMAL"<<'\n';
		}else{
			cout<<"IMPROVE"<<'\n';
			for(int i = 0; i < n; i++){
				if(a[i] == -1){
					cout<<i + 1<<" ";
					break;
				}
			}
			for(int i = 0; i < n; i++){
				if(b[i] == -1){
					cout<<i + 1<<'\n';
					break;
				}
			}
		}
	}

	return 0;
}