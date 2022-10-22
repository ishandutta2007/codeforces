#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int N, M; cin >> N >> M;
	vector<int> d(2 * N + 2 * M + 1);
	int rez =  0;
	for (int i = 2; i <= N + M; ++i) 
		if (d[i] == 0) {
			++rez;
			queue< pair<int, int> > Q;
			Q.push(make_pair(i, 0));
			d[i] = 1;                         
			while (!Q.empty()) {
				int x = Q.front().first;
				int y = Q.front().second;
				Q.pop();
				if (y == 0) {
					int ne;
                	if (x <= N)
						ne = x - 2;
					else
						ne = 2 * N - x;
					ne += N + M + M;
					if (d[ne] != 1) {
					d[ne] = 1;
					Q.push(make_pair(ne, 1));
                               }
					if (x <= M)
						ne = 2 - x;
					else
						ne = x - 2 * M;
					ne += N + M + M;
					if (d[ne] == 1)
						continue;
					d[ne] = 1;
					Q.push(make_pair(ne, 1));
				}
				else {
					int ne;
					x -= N + M + M;
					if (x <= 0)
						ne = 2 - x;
					else
						ne = x + 2;
					if (d[ne] != 1) {
						d[ne] = 1;
						Q.push(make_pair(ne, 0));
					}
					if (x <= N - M)
						ne = x + 2 * M;
					else
						ne = 2 * N - x;
					if (d[ne] == 1)
						continue;
					d[ne] = 1;
					Q.push(make_pair(ne, 0));
			}
		}
	}
	cout << rez;
}