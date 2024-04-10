#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

const int MAXN = 100010;
const int MAXF = 110;
long long a[MAXN];
bool isFat[MAXN];
int fatInd[MAXN];
int fatC = 0;
vector<int> sets[MAXN];
vector<int> fatSetsIn[MAXN];
int fatInter[MAXF][MAXN];
long long fatSum[MAXF], fatAdd[MAXF];

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int N, M, Q;
    cin >> N >> M >> Q;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    int fatThres = 1000;
    for (int i = 0; i < M; ++i) {
        int k;
        cin >> k;
        sets[i].resize(k);
        isFat[i] = k >= fatThres;
        if (isFat[i]) {
            fatInd[i] = fatC++;
        }
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            --x;
            sets[i][j] = x;
            if (isFat[i]) {
                fatSetsIn[x].pb(fatInd[i]);
                fatSum[fatInd[i]] += a[x];
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        int k = sets[i].size();
        for (int j = 0; j < k; ++j) {
            int x = sets[i][j];
            for (size_t q = 0; q < fatSetsIn[x].size(); ++q) {
                int f = fatSetsIn[x][q];
                ++fatInter[f][i];
            }
        }
    }

    for (int q = 0; q < Q; ++q) {
        string s;
        cin >> s;
        if (s == "?") {
            int k;
            cin >> k;
            --k;
            if (isFat[k]) {
                cout << fatSum[fatInd[k]] << '\n';
            } else {
                int l = sets[k].size();
                long long sum = 0;
                for (int i = 0; i < l; ++i) {
                    sum += a[sets[k][i]];
                }
                for (int i = 0; i < fatC; ++i) {
                    sum += fatAdd[i] * fatInter[i][k];
                }
                cout << sum << '\n';
            }
        } else {
            int k;
            long long x;
            cin >> k >> x;
            --k;
            for (int i = 0; i < fatC; ++i) {
                int inter = fatInter[i][k];
                fatSum[i] += inter * x;
            }
            if (!isFat[k]) {
                int l = sets[k].size();
                for (int i = 0; i < l; ++i) {
                    a[sets[k][i]] += x;
                }
            } else {
                fatAdd[fatInd[k]] += x;
            }
        }
    }
    
	return 0;
}