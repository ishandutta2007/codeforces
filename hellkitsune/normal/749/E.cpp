#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef long double Double;

int n;
int a[100005];
int pos[100005];

LL fen[100005] = {}, fen2[100005] = {};

void fenInc(LL *fen, int pos, int val) {
    for (; pos < n; pos |= pos + 1) {
        fen[pos] += val;
    }
}

LL fenGet(LL *fen, int pos) {
    LL res = 0;
    for (; pos >= 0; pos = (pos & (pos + 1)) - 1) {
        res += fen[pos];
    }
    return res;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
        --a[i];
    }
    forn(i, n) {
        pos[a[i]] = i;
    }
    Double ans = 0;
    LL tot = (LL)n * (n + 1) / 2;
    forn(num, n) {
        int ind = pos[num];

        Double p = (Double)fenGet(fen, ind) * (n - ind) / tot;
        ans += 0.5 * p;
        ans += ind - fenGet(fen2, ind);
        //cerr << (LL)ind * (ind + 1) / 2 << ' ' << fenGet(fen, ind) << ' ' << (n - ind) << ' ' << tot << endl;
        p = (Double)((LL)ind * (ind + 1) / 2 - fenGet(fen, ind)) * (n - ind) / tot;
        ans -= 0.5 * p;

        fenInc(fen, ind, ind + 1);
        fenInc(fen2, ind, 1);
    }
    printf("%.22f\n", (double)ans);
    return 0;
}