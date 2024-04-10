#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <complex>
#include <map>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))

typedef long long int64;

const long double pi = 3.1415926535897932384626433832795;
const int INF = (int)1E9;
const int MAXN = (int)11000;

using namespace std;

int bit(int x, int k) {
    return (x >> k) & 1;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m;
    string name, name2;
    bool fail, lad[20][20];
    map<string, int> Map;
    map<int, string> imap;
    vector<string> answer;

    cin >> n >> m;
    forn(i, n) {
        cin >> name;
        Map[name] = i;
        imap[i] = name;
    }

    memset(lad, 0, 20 * 20 * sizeof(bool));
    forn(i, m) {
        cin >> name >> name2;
        lad[Map[name]][Map[name2]] = 1;
        lad[Map[name2]][Map[name]] = 1;
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        fail = 0;
        forn(i, n)
            forn(j, n)
                if (bit(mask, i) == 1 && bit(mask, j) == 1 && lad[i][j])
                    fail = 1;

        if (fail)
            continue;

        int len = 0;
        forn(i, n)
            if (bit(mask, i) == 1)
                len++;
        if (len > answer.size()) {
            answer.clear();
            forn(i, n)
                if (bit(mask, i) == 1)
                    answer.push_back(imap[i]);
        }
    }

    sort(all(answer));
    cout << answer.size() << endl;
    forn(i, answer.size())
        cout << answer[i] << endl;

    return 0;
}