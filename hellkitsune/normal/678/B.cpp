#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int y;

bool isLeap(int y) {
    return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0);
}

int main() {
    cin >> y;
    bool leap = isLeap(y);
    int cur = leap ? 2 : 1;
    for (int i = y + 1; ; ++i) {
        bool curLeap = isLeap(i);
        if (cur == 0 && curLeap == leap) {
            cout << i << endl;
            return 0;
        }
        cur = (cur + (curLeap ? 2 : 1)) % 7;
    }
    return 0;
}