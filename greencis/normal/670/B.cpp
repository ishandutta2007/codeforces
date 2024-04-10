#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

int n, k;
int a[100105];

int main()
{
    cin >> n >> k;
    --k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int cur = 0;
    int len = 0;
    while (1) {
        int nxt = cur + ++len;
        if (nxt > k) {
            cout << a[len - (nxt - k)];
            break;
        }
        cur = nxt;
    }
}