#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int p[1000];
int deg[1000];
bool leaf[1000];

int main() {
    scanf("%d", &n);
    forn(i, n - 1) {
        scanf("%d", p + 1 + i);
        --p[i + 1];
    }
    forn(i, n) leaf[i] = true;
    forn(i, n) leaf[p[i]] = false;
    forn(i, n) if (leaf[i]) {
        ++deg[p[i]];
    }
    forn(i, n) if (!leaf[i] && deg[i] < 3) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}