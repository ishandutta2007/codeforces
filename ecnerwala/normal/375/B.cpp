#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int MAXN = 10000;
const int MAXM = 10000;
int N, M;
char C[MAXN][MAXM];

int nxt0[MAXN];

int go() {
	for(int i = 0; i < N; i++) C[i][M] = '0';

	memset(nxt0, -1, sizeof(nxt0));
	int res = 0;

	for(int a = 0; a < M; a++) {
		vector<int> lens;
		for(int i = 0; i < N; i++) {
			if(nxt0[i] < a) {
				nxt0[i] = a;
				while(C[i][nxt0[i]] != '0') nxt0[i] ++;
			}
			lens.push_back(nxt0[i] - a);
		}

		sort(lens.begin(), lens.end());

		for(int i = 0; i < N; i++) {
			int v = lens[i] * (N - i);
			if(v > res) res = v;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 0; i < N; i++) cin >> C[i];
	
	cout << go() << '\n';
}