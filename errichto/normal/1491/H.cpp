#include <bits/stdc++.h>
using namespace std;

// #warning TODO, test various BLOCK SIZE and submit with 300
const int BLOCK_SIZE = 300;
const int MAX_N = 1e5 + 5;
// 0 1 2 3 4 | 5 6 7 8 9 | 10 ...
int plb[MAX_N];
int parent[MAX_N];
const int COUNT_BLOCKS = MAX_N/BLOCK_SIZE+1;
int offset[COUNT_BLOCKS];
set<int> with_parent_inside[COUNT_BLOCKS];

int get_block(int i) {
	return i / BLOCK_SIZE;
}
bool same_block(int i, int j) {
	return get_block(i) == get_block(j);
}

int get_parent(int i) {
	return max(1, parent[i] - offset[get_block(i)]);
}
bool parent_in_same_block(int i) {
	return same_block(i, get_parent(i));
}
int get_plb(int i) {
	if(parent_in_same_block(i)) {
		return plb[i];
	}
	else {
		return get_parent(i);
	}
}

int main() {
	int n, q;
	cin >> n >> q;
	// #warning TODO, pomysl o pozycji 0
	parent[1] = 0;
	for(int i = 2; i <= n; ++i) {
		cin >> parent[i];
		if(parent_in_same_block(i)) {
			plb[i] = get_plb(parent[i]);
		}
	}
	for(int i = 1; i <= n; ++i) {
		with_parent_inside[get_block(i)].insert(i);
	}
	// for(int i = 1; i <= n; ++i) {
		// cerr << get_plb(i) << " ";
	// }
	// cerr << endl;
	while(q--) {
		int type;
		cin >> type;
		if(type == 1) {
			// decrease
			int L, R, diff;
			cin >> L >> R >> diff;
			// 1) zielony
			if(!same_block(L, R)) {
				for(int i = L; i <= R && same_block(i, L); ++i) {
					parent[i] -= diff;
					parent[i] = max(parent[i], -100);
					if(parent_in_same_block(i)) {
						plb[i] = get_plb(get_parent(i));
					}
				}
			}
			// 2) zolte pelne
			for(int b = get_block(L) + 1; b < get_block(R); b++) {
				offset[b] += diff;
				offset[b] = min(offset[b], n);
				vector<int> to_erase;
				for(int i : with_parent_inside[b]) {
				// #warning TODO, zmien na seta
				// for(int i = b * BLOCK_SIZE; i < (b + 1) * BLOCK_SIZE; ++i) {
					if(get_parent(i) >= b * BLOCK_SIZE) {
						plb[i] = get_plb(get_parent(i));
					}
					else {
						to_erase.push_back(i);
					}
				}
				for(int i : to_erase) {
					with_parent_inside[b].erase(i);
				}
			}
			// 3) czerwony
			// if(!same_block(L, R)) {
			for(int i = max(L, R / BLOCK_SIZE * BLOCK_SIZE);
					i <= n && same_block(i, R); ++i) {
				if(i <= R) {
					parent[i] -= diff;
					parent[i] = max(parent[i], -100);
				}
				if(parent_in_same_block(i)) {
					plb[i] = get_plb(get_parent(i));
				}
			}
			// }
		}
		else {
			// LCA
			int x, y;
			cin >> x >> y;
			// for(int i = 1; i <= n; ++i) {
				// cerr << get_parent(i) << " ";
			// }
			// cerr << endl;
			// for(int i = 1; i <= n; ++i) {
				// cerr << get_plb(i) << " ";
			// }
			// cerr << endl;
			while(get_plb(x) != get_plb(y)) {
				if(x > y) {
					swap(x, y);
				}
				y = get_plb(y);
			}
			// cerr << x << " vs. " << y << endl;
			while(x != y) { // O(sqrt(N))
				if(x > y) {
					swap(x, y);
				}
				y = get_parent(y);
			}
			cout << x << "\n";
		}
		// #warning TODO, usun to przy submicie
		// for(int i = 0; i < BLOCK_SIZE; ++i) {
			// assert(plb[i] == 0);
			// assert(get_plb(i) == 0);
		// }
	}
}