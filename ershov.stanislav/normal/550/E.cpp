#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

int n, a[111111];

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    if (n == 1 && a[0] == 0) {
        cout << "YES\n0\n";
    } else {
        if (n == 1) {
            cout << "NO";
        } else if (n == 2) {
            if (a[0] != 1 || a[1] != 0) {
                cout << "NO";
            } else {
                cout << "YES" << endl << "1->0";
            }
        } else {
            bool flag = false;
            if (a[n - 1] != 0) {
                cout << "NO";
            } else {
                if (a[n - 2] == 1) {
                    printf("YES\n");
                    printf("((");
                    for (int i = 0; i < n - 3; i++) {
                        printf("%d->", a[i]);
                    }
                    printf("%d", a[n - 3]);
                    printf(")->1)->0");
                } else if (a[n - 2] == 0) {
                    for (int i = 0; i < n - 2; i++) {
                        if (a[i] == 0) {
                            flag = true;
                        }
                    }
                    if (!flag) {
                        cout << "NO";
                    } else {
                        printf("YES\n");
                        printf("(");
                        for (int i = 0; i < n - 2; i++) {
                            bool flag2 = false;
                            if (a[i] == 0 && flag) {
                                printf("(");
                                flag = false;
                                flag2 = true;
                            }
                            printf("%d->", a[i]);
                            if (flag2) {
                                printf("(");
                            }
                        }
                        printf("%d", a[n - 2]);
                        printf("))");
                        printf(")->0");
                    }
                }
            }
        }
    }
    return 0;
}