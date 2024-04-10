#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

int n, a[2005], cnt1, cnt2, cnt2_i;
int pr1 = -1, pr2 = -1;
char u[2001005];

int main()
{
    for (int i = 2; i < 2001005; ++i)
        u[i] = 1;
    for (int i = 2; i < 2001005; ++i) {
        if (u[i]) {
            for (int j = i + i; j < 2001005; j += i)
                u[j] = 0;
        }
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) ++cnt1;
    }

    if (cnt1) {
        for (int i = 0; i < n; ++i) {
            if (a[i] != 1 && u[a[i] + 1]) {
                cnt2 = 1;
                cnt2_i = a[i];
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (u[a[i] + a[j]]) {
                pr1 = a[i];
                pr2 = a[j];
            }
        }
    }

    int cnt_12 = cnt1 + min(cnt2, 1);
    int cnt_2pr = (pr1 != -1 && pr2 != -1 ? 2 : 0);
    int cnt_stupid = 1;

    if (cnt_12 >= cnt_stupid && cnt_12 >= cnt_2pr) {
        cout << cnt_12 << endl;
        if (cnt2) cout << cnt2_i << " ";
        while (cnt1--) cout << "1 ";
        cout << endl;
        return 0;
    }

    if (cnt_2pr >= cnt_stupid && cnt_2pr >= cnt_12) {
        cout << "2" << endl << pr1 << " " << pr2 << endl;
        return 0;
    }

    cout << "1" << endl << a[0] << endl;

    return 0;
}