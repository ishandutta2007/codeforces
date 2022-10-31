#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;
int main()
{
    ll n; bool c=0;
    cin >> n;
    for (ll i=(int)sqrt(n)-100; i<=sqrt(n)+1; i++) {
        if (i<=0) continue;
        int a=0, b=i;
        while (b) a+=b%10, b/=10;
        if (i*(i+a)==n) cout << i, c=1;
    }
    if (!c) cout << -1;
    return 0;
}