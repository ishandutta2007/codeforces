#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll N = 1000000000;

map<int, map<ll, int> > f;
int ptr = 100;

inline void update(int x, ll t, int y){
	while(t <= N){
		f[x][t] += y;
		t += t&(-t);
	}
}

inline int query(int x, ll t){
	int ret = 0;
	while(t){
		ret += f[x][t];
		t &= (t - 1);
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<setprecision(32);

	int n; cin>>n;
	while(n--){
		int a, t, x;
		cin>>a>>t>>x;
		if(a == 1){
			update(x, t, 1);
		}else if(a == 2){
			update(x, t, -1);
		}else{
			cout<<query(x, t)<<'\n';
		}
	}

	return 0;
}