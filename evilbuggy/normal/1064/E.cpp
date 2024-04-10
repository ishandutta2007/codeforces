#include <bits/stdc++.h>
using namespace std;

const int lim = 1000*1000*1000;

int query(int x, int y){
	cout << x << " " << y << endl;
	string s; cin >> s; return s == "white";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int lo = 0, hi = lim;
	int flg = query(lo, lim/2);
	for(int i = 2; i <= n; i++){
		assert(hi - lo + 1 >= 3);
		int mi = (lo + hi)/2;
		if(query(mi, lim/2) == flg){
			lo = mi;
		}else{
			hi = mi;
		}
	}
	cout << lo << " " << (lim/2) + 1 << " " << hi << " " << (lim/2) -1 << endl;

	return 0;
}