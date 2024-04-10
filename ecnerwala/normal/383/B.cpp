#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 1e9 + 7;
const int MAXM = 2e5;

ll N;
int M;
pii P[MAXM];

bool isPath() {
	sort(P, P + M);
	if(P[M - 1] == pii(N, N)) return false;
	int curRow = 0;
	vector<pii> ranges; // [A, B]
	ranges.push_back(pii(1, 1)); 
	for(int i = 0; i < M; ) {
		if(P[i].A > curRow + 1) {
			int st = ranges[0].A;
			ranges.clear();
			ranges.push_back(pii(st, N));
		}
		vector<pii> nranges;
		curRow = P[i].A;
		//cerr << curRow << '\n';
		if(ranges[0].A <= P[i].B - 1) nranges.push_back(pii(ranges[0].A, P[i].B - 1));
		int j = 0;
		while(i < M && P[i].A == curRow) {
			int st = P[i].B + 1;
			int end;
			if(i + 1 == M || P[i + 1].A != curRow) end = N;
			else end = P[i + 1].B - 1;
			i++;
			if(st > end) continue;
			while(j < ranges.size() && ranges[j].B < st) {
				j++;
			}
			if(j == ranges.size()) continue;
			if(ranges[j].A <= end) nranges.push_back(pii(max(st, ranges[j].A), end));
		}
		//for(int i = 0; i < nranges.size(); i++) {
			//cerr << nranges[i].A << ' ' << nranges[i].B << '\n';
		//}
		ranges = nranges;
		if(nranges.empty()) return false;
	}
	if(curRow != N) return !ranges.empty();
	return ranges.back().B == N;
}

ll go() {
	return isPath() ? (2 * N - 2) : -1;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		cin >> P[i].A >> P[i].B;
	}

	cout << go() << '\n';
}