#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int a,b,n,x,y;
vector<int> v;

int main()
{
    cin >> a >> b >> n;
    a = gcd(a, b);
    for (int i = 1; i * i <= a; ++i) {
        if (a % i == 0) {
            v.push_back(i);
            if (i * i != a)
                v.push_back(a / i);
        }
    }
    sort(v.begin(), v.end());
    while (n--) {
        cin >> x >> y;
        int L = 0, R = (int)v.size() - 1;
        while (L < R) {
            int mid = (L + R + 1) >> 1;
            if (v[mid] <= y) L = mid;
            else R = mid - 1;
        }
        if (v[R] >= x && v[R] <= y)
            cout << v[R] << "\n";
        else cout << "-1\n";
    }

    return 0;
}