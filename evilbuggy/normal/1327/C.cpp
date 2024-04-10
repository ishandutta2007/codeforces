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

	int x, y, n, m, k;
	cin>>n>>m>>k;
	for(int i = 0; i < 2*k; i++){
		cin>>x>>y;
	}
	string ret = "";
	for(int i = 1; i < n; i++){
		ret += 'U';
	}
	for(int i = 1; i < m; i++){
		ret += 'L';
	}
	for(int i = 0; i < n; i++){
		for(int j = 1; j < m; j++){
			if(i&1)ret += 'L';
			else ret += 'R';
		}
		if(i != n - 1)ret += 'D';
	}
	assert(ret.size() <= 2*n*m);
	cout<<ret.size()<<endl;
	cout<<ret<<endl;

	return 0;
}