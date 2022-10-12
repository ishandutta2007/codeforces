#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const int N = 5005;

int bit1[N][N];
int bit2[N][2*N];
int bit3[N][2*N];

void ins1(int x, int y, int c) {
    x = min(x, N-1), y = min(y, N-1);
    x = max(x, 0), y = max(y, 0);
    for (int i = x; i < N; i += i&-i)
        for (int j = y; j < N; j += j&-j)
            bit1[i][j] += c;
}

void ins2(int x, int y, int c) {
    y += x;
    x = min(x, N-1), y = min(y, 2*N-1);
    x = max(x, 0), y = max(y, 0);
    for (int i = x; i < N; i += i&-i)
        for (int j = y; j < 2*N; j += j&-j)
            bit2[i][j] += c;
}

void ins3(int x, int y, int c) {
    y += N-x;
    x = min(x, N-1), y = min(y, 2*N-1);
    x = max(x, 0), y = max(y, 0);
    for (int i = x; i < N; i += i&-i)
        for (int j = y; j < 2*N; j += j&-j)
            bit3[i][j] += c;
}

int qry(int x, int y) {
    int ans = 0;
    for (int i = x; i > 0; i -= i&-i)
        for (int j = y; j > 0; j -= j&-j)
            ans += bit1[i][j];
    for (int i = x; i > 0; i -= i&-i)
        for (int j = y+x; j > 0; j -= j&-j)
            ans += bit2[i][j];
    for (int i = x; i > 0; i -= i&-i)
        for (int j = y+N-x; j > 0; j -= j&-j)
            ans += bit3[i][j];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, qq; cin >> n >> qq;
    for (int i = 0; i < qq; i++) {
        int t; cin >> t;
        if (t == 1) {
            int dir, x, y, len; cin >> dir >> x >> y >> len;
            if (dir == 1) {
                ins1(x, y, 1);
                ins2(x, y+len+1, -1);
                ins1(x+len+1, y, -1);
                ins2(x+len+1, y, 1);
            }
            if (dir == 2) {
                ins3(x, y-len, 1);
                ins3(x+len+1, y+1, -1);
                ins1(x, y+1, -1);
                ins1(x+len+1, y+1, 1);
            }
            if (dir == 3) {
                ins1(x-len, y, 1);
                ins3(x-len, y+1, -1);
                ins1(x+1, y, -1);
                ins3(x+1, y+len+2, 1);
            }
            if (dir == 4) {
                ins2(x-len, y, 1);
                ins2(x+1, y-len-1, -1);
                ins1(x-len, y+1, -1);
                ins1(x+1, y+1, 1);
            }
        } else {
            int x, y; cin >> x >> y;
            cout << qry(x, y) << "\n";
        }
    }
    int tmp[100][100];
    for (int i = 0; i < 20; i++)
        for (int j = 0; j < 20; j++)
            tmp[i][j] = qry(j, i);
    for (int i = 19; i >= 0; i--)
        debug(vector(tmp[i], tmp[i]+20));
}