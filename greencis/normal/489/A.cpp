#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a[3005];

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        int mni = 2e9, mn = 2e9;
        for (int j = i; j < n; ++j) {
            if (a[j] < mn) mn = a[j], mni = j;
        }
        cout << i << " " << mni << endl;
        swap(a[i], a[mni]);
    }

    return 0;
}