#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <iostream>
using std::cin; using std::cout; using std::endl;
#include <algorithm>
using std::sort; using std::min; using std::max;
#include <vector>
using std::vector;
#include <set>
using std::set;
#include <queue>
using std::queue; using std::priority_queue;
#include <utility>
using std::pair;
typedef pair<int, int> pii;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;
#define pass printf("%s : Line.%d\n", __FUNCTION__, __LINE__);

const int maxN = 255;
const ULL P = 123456789987654321;
int n;
int max_depth = 0;

struct Strategy {
	int t, y, z, k;
	Strategy() {}
	Strategy(int t, int y, int z, int k) : t(t), y(y), z(z), k(k) {}
};
vector<Strategy> st;
int seq[26];
set<ULL> S;
ULL p[maxN];

void print() {
	printf("%d\n", (int)st.size());
	for(int i = 0; i < (int)st.size(); ++i) {
		Strategy s = st[i];
		if(st[i].t == 2) printf("lea e%cx, [e%cx + e%cx]\n", i + 'a' + 1,
			s.y + 'a', s.z + 'a');
		else if(st[i].t == 3) printf("lea e%cx, [%d*e%cx]\n", i + 'a' + 1,
			s.k, s.y + 'a');
		else if(st[i].t == 4) printf("lea e%cx, [e%cx + %d*e%cx]\n", i + 'a' + 1,
			s.y + 'a', s.k, s.z + 'a');
		else assert(false);
	}
}

bool DFS(int d, ULL h) {
	if(seq[d - 1] > 255) return false;
	if(seq[d - 1] == n) {
		print();
		return true;
	}
	if(d >= max_depth) return false;
	// t = 2
	for(int i = 0; i < d; ++i) for(int j = i; j < d; ++j) {
		int nv = seq[i] + seq[j];
		ULL nh = h + p[d] * nv;
		if(nv <= seq[d - 1]) continue;
		seq[d] = nv;
		if(S.count(nh)) continue;
		else S.insert(nh);
		st.push_back(Strategy(2, i, j, -1));
		if(DFS(d + 1, nh)) return true;
		st.pop_back();
	}
	// t = 3
	for(int i = 0; i < d; ++i) {
		for(int k = 2; k <= 8; k <<= 1) {
			int nv; ULL nh;
			for(int j = 0; j < d; ++j) {
				nv = seq[j] + k * seq[i];
				nh = h + p[d] * nv;
				if(nv <= seq[d - 1]) continue;
				seq[d] = nv;
				if(S.count(nh)) continue;
				else S.insert(nh);
				st.push_back(Strategy(4, j, i, k));
				if(DFS(d + 1, nh)) return true;
				st.pop_back();
			}
			
			nv = k * seq[i];
			nh = h + p[d] * nv;
			if(nv <= seq[d - 1]) continue;
			seq[d] = nv;
			if(S.count(nh)) continue;
			else S.insert(nh);
			st.push_back(Strategy(3, i, -1, k));
			if(DFS(d + 1, nh)) return true;
			st.pop_back();

		}
	}
	return false;
}

int main() {
	p[0] = 1;
	for(int i = 1; i < maxN; ++i) p[i] = p[i - 1] * P;
	cin >> n;
//for(n = 1; n <= 255; ++n) {
//	cout << "n = " << n << endl;

	for(max_depth = 1; max_depth <= 26; ++max_depth) {
//		printf("maxd = %d\n", max_depth);
		S.clear();
		memset(seq, 0, sizeof(seq));
		seq[0] = 1;
		S.insert(1); st.clear();
		if(DFS(1, 1)) break;
	} // }
	return 0;
}