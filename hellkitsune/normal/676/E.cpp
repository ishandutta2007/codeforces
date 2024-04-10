#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
int a[100001] = {};
bool em[100001];
char buf[111];

int main() {
    scanf("%d%d", &n, &k);
    ++n;
    REP(i, n) {
        scanf("%s", buf);
        em[i] = buf[0] == '?';
        if (!em[i]) {
            string z = string(buf);
            istringstream iss(z);
            iss >> a[i];
        }
    }
    int cntem = 0;
    REP(i, n) if (em[i]) ++cntem;
    if (cntem == 0) {
        LL cur = 0;
        for (int i = n - 1; i >= 0; --i) {
            cur = k * cur + a[i];
            if (abs(cur) > 1e12) {
                cout << "No" << endl;
                return 0;
            }
        }
        if (cur == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }
    if (k == 0) {
        bool human = (n + cntem) % 2 == 1;
        if (!em[0] && a[0] == 0) {
            cout << "Yes" << endl;
        } else if (em[0] && human) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return 0;
    }
    if (n % 2 == 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}