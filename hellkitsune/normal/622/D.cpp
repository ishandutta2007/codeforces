#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;

int main() {
    scanf("%d", &n), --n;
    int e = n - n % 2;
    int o = n - (n % 2 == 0);
    ++n;
    for (int i = e; i >= 0; i -= 2) printf("%d ", n - i);
    for (int i = 2; i <= e; i += 2) printf("%d ", n - i);
    printf("%d ", n);
    for (int i = o; i >= 1; i -= 2) printf("%d ", n - i);
    for (int i = 1; i <= o; i += 2) printf("%d ", n - i);
    return 0;
}