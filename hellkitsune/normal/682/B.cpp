#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000];

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    sort(a, a + n);
    int cur = 1;
    REP(i, n) {
        if (a[i] >= cur) {
            ++cur;
        }
    }
    cout << cur << endl;
    return 0;
}