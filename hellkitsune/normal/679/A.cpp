#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int pr[15] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

int main() {
    int cnt = 0;
    REP(i, 15) {
        cout << pr[i] << endl;
        string s;
        cin >> s;
        if (s[0] == 'y') {
            ++cnt;
            if (pr[i] * pr[i] <= 100) {
                cout << pr[i] * pr[i] << endl;
                cin >> s;
                if (s[0] == 'y') {
                    ++cnt;
                    break;
                }
            }
        }
    }
    if (cnt > 1) {
        cout << "composite" << endl;
    } else {
        cout << "prime" << endl;
    }
    return 0;
}