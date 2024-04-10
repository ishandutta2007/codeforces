#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[100005];

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    if (n == 1) { cout << "yes\n1 1"; return 0; }
    if (n == 2) {
        if (a[0] <= a[1]) { cout << "yes\n1 1"; return 0; }
        else { cout << "yes\n1 2"; return 0; }
    }

    bool reversed = false;
    int ansl = 1, ansr = 1;
    int st, taking = 0;
    for (int i = 0; i < n-1; ++i) {
        if (taking) {
            if (a[i] < a[i + 1]) {
                taking = 0;
                if (a[i] == a[st]) continue;
                if (reversed) { cout << "no"; return 0; }
                reversed = true;
                reverse(a + st, a + i + 1);
                ansl = st + 1;
                ansr = i + 1;
            }
        } else {
            if (a[i] >= a[i + 1]) {
                taking = 1;
                st = i;
            }
        }
    }
    if (taking) {
        if (a[st] != a[n-1]) {
            if (reversed) { cout << "no"; return 0; }
            reverse(a + st, a + n);
            ansl = st + 1;
            ansr = n;
        }
    }

    for (int i = 0; i < n-1; ++i) {
        if (a[i] > a[i+1]) { cout << "no"; return 0; }
    }
    cout << "yes\n" << ansl << " " << ansr;

    return 0;
}