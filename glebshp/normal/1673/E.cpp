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

const int maxn = (1 << 20) + 10;
const int maxdeg = 23;

int n;
int k;

int b[maxn];
int cnkhelp[maxdeg + 1][maxn];
int ans[maxn];
int temp[maxn];

int calcParity(int hn, int hk) {
    int curp = 2;
    while (curp <= hn) {
        if (hn / curp > hk / curp + (hn - hk) / curp) {
            return 0;
        }
        curp *= 2;
    }

    return 1;
}

void fillTmpForNK(int hn) {
    for (int j = 0; j <= hn; j++) {
        temp[j] = calcParity(hn, j);
    }
    for (int j = hn + 1; j < maxn; j++) {
        temp[j] = 0;
    }
}

void precalc() {
    for (int i = max(0, n - maxdeg); i <= n; i++) {
        fillTmpForNK(i);
        int parity = 0;
        for (int j = maxn - 1; j >= 0; j--) {
            parity ^= temp[j];
            cnkhelp[n - i][j] = parity;
        }    
    }
}

int getCnkSumParity(int hn, int hk) {
    return cnkhelp[n - hn][hk];
}

int main() {
    /*
    freopen("input.txt", "w", stdout);
    cout << 1000 * 1000 << ' ' << 1000 * 1000 / 2 << endl;
    for (int i = 0; i < 1000 * 1000; i++) {
        cout << 1 << ' ';
    }
    cout << endl;
    return 0;
    */
    //double stime = clock();

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    precalc();

//    cerr << (clock() - stime) / CLOCKS_PER_SEC << endl;

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n; i++) {
        int j = i;

        int d = b[i];
        if (d >= (1 << 20)) {
            d = -1;
        }

        while (j < n) {
            if (j > i) {
                if (b[j] >= maxdeg) {
                    d = -1;        
                }
                int h = 1 << b[j];
                if (d != -1 && (d * 1ll * h >= (1 << 20) * 1ll)) {
                    d = -1;
                }
                if (d != -1) {
                    d *= h;
                }
            }

            if (d == -1) {
                break;
            }
            int hasleft = i > 0;
            int hasright = j < (n - 1);
            int hn = n - 1 - (j - i) - hasleft - hasright;
            int hk = max(0, k - hasleft - hasright);
//            printf("values: %d %d %d\n", hn, hk, getCnkSumParity(hn, hk));

            ans[d] ^= getCnkSumParity(hn, hk);
            j++;
        }
    }

    bool toprint = false;
    for (int i = (1 << 20) - 1; i >= 0; i--) {
        if (i == 0 || ans[i] == 1) {
            toprint = true;
        }
        if (toprint) {
            printf("%d", ans[i]);
        }
    }
    printf("\n");

  //  cerr << (clock() - stime) / CLOCKS_PER_SEC << endl;

    return 0;
}