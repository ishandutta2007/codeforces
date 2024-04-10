#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

int ssum[100000][10];
int curs[10];

int main() {
	fout.precision(10);
	fout << fixed;

    int N, Q;
    string s;
    fin >> N >> Q >> s;
    s = '#' + s + '#';
    vector<int> x(Q), y(Q);
    for (int i = 0; i < Q; ++i) {
        fin >> x[i] >> y[i];
    }
    vector< vector<int> > fenw(10, vector<int>(N + 2));
    vector<bool> visited(N + 2);
    vector< vector<int> > evs(N + 2);
    vector<int> cevs(N + 2);
    for (int i = 0; i < Q; ++i) {
        evs[x[i]].push_back(i);
    }
    vector<bool> act(Q);
    for (int i = 1; i < N + 1; ++i) {
        if (!visited[i]) {
            int cur = i;
            int dir = 1;
            int rem = -1;
            int acount = 0;
            while (true) {
                visited[cur] = true;
                while (cevs[cur] < evs[cur].size()) {
                    int c = evs[cur][cevs[cur]++];
                    if (c >= 0) {
                        if (act[c]) {
                            continue;
                        }
                        for (int d = 0; d < 10; ++d) {
                            ssum[c][d] = curs[d];
                        }
                        evs[x[c] - 1].push_back(-c - 1);
                        evs[y[c] + 1].push_back(-c - 1);
                        act[c] = true;
                        ++acount;
                    } else {
                        c = -c - 1;             
                        if (!act[c]) {
                            continue;
                        }
                        for (int d = 0; d < 10; ++d) {
                            ssum[c][d] = curs[d] - ssum[c][d];
                        }
                        act[c] = false;
                        --acount;
                    }
                }
                if (acount == 0) {
                    break;
                }
                if (s[cur] >= '0' && s[cur] <= '9') {
                    ++curs[s[cur] - '0'];
                    if (s[cur] == '0') {
                        s[cur] = '#';
                    } else {
                        s[cur]--;
                    }
                    rem = -1;
                } else {
                    if (s[cur] == '>') {
                        dir = 1;
                        if (rem >= 0) {
                            s[rem] = '#';
                        }
                        rem = cur;
                    } else {
                        if (s[cur] == '<') {
                            dir = -1;
                            if (rem >= 0) {
                                s[rem] = '#';
                            }
                            rem = cur;
                        }
                    }
                }
                cur += dir;
            }
        }
    }

    for (int i = 0; i < Q; ++i) {
        printf("%d %d %d %d %d %d %d %d %d %d\n", ssum[i][0], ssum[i][1], ssum[i][2], ssum[i][3], ssum[i][4], ssum[i][5], ssum[i][6], ssum[i][7], ssum[i][8], ssum[i][9]);
    }

	return 0;
}