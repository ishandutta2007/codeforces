#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int a,b,c;

int main()
{
    cin >> a >> b >> c;
    for (int i = 0; i <= a && i <= b; ++i) {
        if (b - i + a - i == c) {
            cout << i << " " << b - i << " " << a - i;
            return 0;
        }
    }
    cout << "Impossible";
    return 0;
}