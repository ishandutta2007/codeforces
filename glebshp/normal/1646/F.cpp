#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
 
const int maxn = 101;
 
int n;
int c[maxn][maxn];
bool used[maxn];
bool givesown[maxn];
int waitsfor[maxn];
int cycle[maxn];
 
bool stopGreed() {
    int mincnt = n;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += c[i][j] != i;
        }
        mincnt = min(mincnt, cnt);
    }
    if (mincnt > 0) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            cnt += c[i][j] != i;
        }
 
        if (cnt > 1) {
            return false;
        }
    }
 
    return true;
}
 
int togo(int x, int y) {
    if (y >= x) {
        return y - x;
    } else {
        return y + n - x;
    }
}
 
int getWorst(int p) {
    int best = -1;
    int bestval = -1;
 
    for (int i = 0; i < n; i++) {
        int val = togo(p, c[p][i]);
 
        if (val > bestval) {
            bestval = val;
            best = c[p][i];
        }
    }
 
    return best;
}
 
void applyMove(vector <int> step) {
    for (int i = 0; i < n; i++) {
        int prevval = step[(i + n - 1) % n];
        for (int j = 0; j < n; j++) {
            if (c[i][j] == step[i]) {
                c[i][j] = prevval;
                break;
            }
        }
    }
}
 
void oneShift(vector <vector <int> >& steps) {
    vector <int> step;
    for (int i = 0; i < n; i++) {
        step.pb(c[i][0]);
    }
    steps.pb(step);
 
    for (int i = 0; i < n; i++) {
        c[i][0] = step[(i + n - 1) % n];
    }
}
 
void solveLast(vector <vector <int> >& steps) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (c[i][j] != i) {
                swap(c[i][0], c[i][j]);
            }
        }
    }
 
    int ccnt = 0;
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            continue;
        }
        ccnt++;
        int p = i;
        int cyclelen = 0;
        int cycleelems = 0;
        while (!used[p]) {
            cycleelems++;
            cyclelen += togo(p, c[p][0]);
            used[p] = true;
            cycle[p] = ccnt;
            p = c[p][0];
        }
 
        int t = (cycleelems * n - cyclelen) / n;
        vector <pair <int, int> > help;
        for (int j = 0; j < n; j++) {
            if (cycle[j] == cycle[i]) {
                help.pb(mp(togo(j, c[j][0]), j));
            }
        }
        sort(help.begin(), help.end());
        for (int j = 0; j < n; j++) {
            if (t > 0) {
                givesown[help[j].sc] = true;                
                t--;
            }
        }
    }
 
    for (int i = 0; i < n; i++) {
        if (givesown[i]) {
            swap(c[i][0], c[i][1]);
        }
    }
    oneShift(steps);
 
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            if (!givesown[j]) {
                continue;
            }
            if (cycle[c[j][0]] == cycle[j]) {
                if (togo(j, c[j][0]) < togo(j, c[j][1])) {
                    swap(c[j][0], c[j][1]);
                }
            }
        }
        oneShift(steps);
    }
}

bool checkOK() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (c[i][j] != i) {
                return false;
            }
        }
    }

    return true;
}
 
int main() {
//    freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
 
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &c[i][j]);
            c[i][j]--;
        }
    }
 
    vector <vector <int> > steps;
 
    while (!stopGreed()) {
 //       cerr << "go greed" << endl;
        vector <int> step;
        for (int i = 0; i < n; i++) {
            step.pb(getWorst(i));
        }        
        applyMove(step);
        steps.pb(step);
    }
 
    if (!checkOK()) {
        solveLast(steps);
    }
 
    printf("%d\n", (int) steps.size());
    for (int i = 0; i < (int) steps.size(); i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", steps[i][j] + 1);
        }
        printf("\n");
    }
 
    return 0;
}