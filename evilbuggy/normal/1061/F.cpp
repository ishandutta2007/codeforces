#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int query(int a, int b, int c){
	if(b == a || b == c)return true;
	cout << "? " << a << " " << b << " " << c << endl;
	string s;
	cin >> s;
	return s == "Yes";
}

int get(int n, int k){
	int d = 1, cur = 1, add = k;
	while(cur + add <= n){
		cur += add;
		add *= k;
		d += 1;
	}
	return d;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	int leaf = 2;
	for(int b = 3; b <= n; b++){
		if(query(1, leaf, b)){
			leaf = b;
		}
	}
	vector<int> perm;
	for(int i = 1; i <= n; i++){
		if(i != leaf){
			perm.emplace_back(i);
		}
	}
	vector<int> path;
	int d = get(n, k);
	shuffle(perm.begin(), perm.end(), rng);
	for(int i = 0; i < n - 1; i++){
		int nleaf = perm[i];
		for(int a = 1; a <= n; a++){
			if(query(leaf, nleaf, a)){
				nleaf = a;
			}
		}
		path.clear();
		for(int a = 1; a <= n; a++){
			if(query(leaf, a, nleaf)){
				path.emplace_back(a);
			}
		}
		if((int)path.size() == 2*d - 1)break;
	}
	assert((int)path.size() == 2*d - 1);
	sort(path.begin(), path.end(), [&](int x, int y){
		return query(leaf, x, y);
	});
	cout << "! " << path[d - 1] << '\n';

	return 0;
}