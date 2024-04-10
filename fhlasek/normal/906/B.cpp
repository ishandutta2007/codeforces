/* Written by Filip Hlasek 2017 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define REP(i, b) for (int i = 0; i < (b); i++)

using namespace std;

void doit(vector<int>& v, bool p) {
    vector<int> ans;
    ans.reserve(v.size());
    if (v.size() % 2) {
        if (p) {
            for (int i = 5; i < (int)v.size(); i += 2) {
                ans.push_back(v[i]);
            }
            ans.push_back(v[1]);
            ans.push_back(v[3]);
            ans.push_back(v[0]);
            ans.push_back(v[2]);
            ans.push_back(v[4]);
            for (int i = 6; i < (int)v.size(); i += 2) {
                ans.push_back(v[i]);
            }
        } else {
            for (int i = 6; i < (int)v.size(); i += 2) {
                ans.push_back(v[i]);
            }
            ans.push_back(v[3]);
            ans.push_back(v[1]);
            ans.push_back(v[4]);
            ans.push_back(v[0]);
            ans.push_back(v[2]);
            for (int i = 5; i < (int)v.size(); i += 2) {
                ans.push_back(v[i]);
            }
        }
    } else {
        if (p) {
            for (int i = 4; i < (int)v.size(); i += 2) {
                ans.push_back(v[i]);
            }
            ans.push_back(v[2]);
            ans.push_back(v[0]);
            ans.push_back(v[3]);
            ans.push_back(v[1]);
            for (int i = 5; i < (int)v.size(); i += 2) {
                ans.push_back(v[i]);
            }
        } else {
            for (int i = 5; i < (int)v.size(); i += 2) {
                ans.push_back(v[i]);
            }
            ans.push_back(v[1]);
            ans.push_back(v[3]);
            ans.push_back(v[0]);
            ans.push_back(v[2]);
            for (int i = 4; i < (int)v.size(); i += 2) {
                ans.push_back(v[i]);
            }
        }
    }
    REP(i, ans.size()) v[i] = ans[i];
}

int main(int argc, char* argv[]) {
    int N, M;
    scanf("%d%d", &N, &M);
    if (N == 1 && M == 1) {
        printf("YES\n1\n");
        return 0;
    }
    if (N == 3 && M == 3) {
        printf("YES\n");
        printf("5 3 8\n");
        printf("7 1 6\n");
        printf("2 9 4\n");
        return 0;
    }
    if (N <= 3 && M <= 3) {
        printf("NO\n");
        return 0;
    }
    vector<vector<int> > ans(N);
    REP(i, N) ans[i].resize(M);
    if (M >= 4) {
        REP(i, N) {
            vector<int> row;
            REP(j, M) row.push_back(M * i + j + 1);
            doit(row, i % 2);
            REP(j, M) ans[i][j] = row[j];
        }
    } else {
        REP(j, M) {
            vector<int> col;
            REP(i, N) col.push_back(M * i + j + 1);
            doit(col, j % 2);
            REP(i, N) ans[i][j] = col[i];
        }
    }
    printf("YES\n");
    REP(i, N) {
        REP(j, M) {
            if (j)
                printf(" ");
            printf("%d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}