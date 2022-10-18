#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a,b,x,u[105];

int main()
{
    cin >> n >> a >> b;
    for (int i = 0; i < a; ++i) {
        cin >> x;
        u[x] = 1;
    }
    for (int i = 1; i <= n; ++i) {
        cout << 2 - u[i] << " ";
    }

    return 0;
}