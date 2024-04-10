#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000];
int cnt = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) if (a[i] == 0) ++cnt;
    if ((n == 1 && cnt != 0) || (n != 1 && cnt != 1)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}