#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,R,r;

int main()
{
    cin >> n >> R >> r;
    if (n == 1) {
        if (r <= R) cout << "YES";
        else cout << "NO";
    }else if (n==2) {
        if (r+r <= R) cout << "YES";
        else cout << "NO";
    } else {
        ld newr = r * sqrtl(ld(2) / (ld(1) - cosl(2 * acosl((ld)-1) / ld(n)))) + r;
        if (newr <= R + ld(1e-9)) cout << "YES";
        else cout << "NO";
    }

    return 0;
}