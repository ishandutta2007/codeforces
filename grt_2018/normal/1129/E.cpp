#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 510;
int n;
vector<pi>tree;
int siz[nax];

void getn() {
	cin >> n;
}

int ask_query(vi S, vi T, int v) {
	cout << (int)S.size() << "\n";
	for(auto x : S) cout << x << " ";
	cout << "\n" << (int)T.size() << "\n";
	for(auto x : T) cout << x << " ";
	cout << "\n" << v << "\n";
	fflush(stdout);
	int ans;
	cin >> ans;
	return ans;
}

pi ord[nax];
			

int main() {
	getn();
	int root = 1;
	vi all = {};
	for(int i = 2; i <= n; ++i) all.PB(i);
	for(int i = 2; i <= n; ++i) {
		ord[i] = {ask_query(all,{root},i),i};
		siz[i] = ord[i].ST;
	}
	sort(ord + 2, ord + n + 1);
	for(int i = 2; i <= n; ++i) {
		ord[i].ST--;
		while(ord[i].ST > 0) {
			vi ver = {};
			for(int j = 0; j < (int)all.size(); ++j) {
				if(all[j] != ord[i].ND) ver.PB(all[j]);
			}
			int l = 0, r = (int)ver.size(), mid;
			while(l <= r) {
				mid = (l + r) / 2;
				vi tmp = {};
				for(int j = 0; j <= mid; ++j) tmp.PB(ver[j]);
				if(ask_query(tmp, {root}, ord[i].ND) > 0) {
					r = mid - 1;
				} else {
					l = mid + 1;
				}
			}
			r++;
			int id = -1;
			for(int j = 0; j < (int)all.size(); ++j) {
				if(all[j] == ver[r]) {
					id = j;
					break;
				}
			}
			ord[i].ST -= siz[all[id]];
			tree.emplace_back(ord[i].ND, ver[r]);
			swap(all[id], all.back());
			all.pop_back();
		}
	}
	for(auto x : all) tree.emplace_back(root, x);
	cout << "ANSWER\n";
	for(auto edge : tree) {
		cout << edge.ST << " " << edge.ND << "\n";
	}
	fflush(stdout);
}