#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int k;
string s;

bool check(int x) {
    int rows = 1, col = 0;
    int curidx = 0;
    while (curidx < (int)s.size()) {
        int nextidx = curidx;
        while (isalpha(s[nextidx]))
            ++nextidx;
        int nextcol = col + nextidx - curidx + (nextidx + 1 < (int)s.size());
        if (nextcol > x) {
            if (col == 0)
                return false;
            col = 0;
            ++rows;
            continue;
        }
        col = nextcol;
        curidx = nextidx + 1;
    }
    return rows <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> k;
    getline(cin, s);
    getline(cin, s);
    s += " ";

    int L = 0, R = 1000000;
    while (L < R) {
        int mid = (L + R) >> 1;
        if (check(mid))
            R = mid;
        else
            L = mid + 1;
    }
    cout << L << endl;

    return 0;
}