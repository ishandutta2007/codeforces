#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 5005;
const int mod = 998244353;

using namespace std;

void add(int &x, int y)
{
    x += y;
    if (x >= mod) {
        x -= mod;
    }
}

int n;
int k;
string s;
int c[N][N];

int main()
{
    ios_base::sync_with_stdio(0);

    for(int i = 0; i < N; i++){
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j++){
            c[i][j] = c[i - 1][j];
            add(c[i][j], c[i - 1][j - 1]);
        }
    }
    cin >> n >> k >> s;
    if(k == 0){
        cout << 1 << "\n";
        return 0;
    }
    int res = 1, pre = 0;
    for (int i = 0; i < n; i++) {
        int h = n - 1, cnt = 0;
        for (int j = i; j < n; j++) {
            if (s[j] == '1') {
                if (cnt == k) {
                    h = j - 1;
                    break;
                }
                cnt += 1;
            }
        }
        if (cnt + pre >= k && (cnt - (s[i] == '0' ? 1 : 0)) >= 0) {
            add(res, c[h - i][cnt - (s[i] == '0' ? 1 : 0)]);
        }
        pre += s[i] == '1';
    }

    cout << res << "\n";
};