#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;
const int N = 333333;
const int B = 550;
const int M = N/B;

int l[N], r[N], block[N], ind[N], off[N];
deque<int> f[M];

// Probably treaps can be used to solve this
// Now I have to learn treaps :weary:

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> l[i] >> r[i];
	}
	for(int i = 0; i <= n; i++){
		block[i] = i/B; ind[i] = i%B;
		if(i)f[block[i]].emplace_back(inf);
		else f[block[i]].emplace_back(0);
	}
	memset(off, 0, sizeof(off));
	for(int it = 1; it <= n; it++){
		int st, en;
		{
			int lo = 0, hi = n;
			while(lo < hi){
				int mi = (lo + hi + 1)/2;
				if(f[block[mi]][ind[mi]] + off[block[mi]] < l[it]){
					lo = mi;
				}else{
					hi = mi - 1;
				}
			}
			st = lo + 1;
		}
		{
			int lo = 0, hi = n;
			while(lo < hi){
				int mi = (lo + hi + 1)/2;
				if(f[block[mi]][ind[mi]] + off[block[mi]] < r[it]){
					lo = mi;
				}else{
					hi = mi - 1;
				}
			}
			en = lo + 1;
		}
		int val = l[it];
		int bls = block[st];
		int ble = block[en];
		for(int i = st; i <= en && block[i] == bls; i++){
			int tmp = f[bls][ind[i]] + off[bls] + 1;
			swap(tmp, val);
			f[bls][ind[i]] = tmp - off[bls];
		}
		if(bls == ble)continue;
		for(int i = bls + 1; i < ble; i++){
			off[i]++;
			f[i].emplace_front(val - off[i]);
			val = f[i].back() + off[i];
			f[i].pop_back();
		}
		for(int i = en, j = ind[en]; j > 0; i--, j--){
			int tmp = f[ble][j - 1] + 1;
			f[ble][j] = tmp;
		}
		f[ble][0] = val - off[ble];
	}
	for(int i = n; i >= 0; i--){
		if(f[block[i]][ind[i]] + off[ind[i]] < inf){
			cout << i << '\n';
			exit(0);
		}
	}
	assert(false);
	
	return 0;
}