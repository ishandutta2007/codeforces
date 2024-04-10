#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

/// max(75*p, 250*p - p*t)

int main()
{

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int mi = max(75*a, 250*a - a*c);
    int va = max(75*b, 250*b - b*d);
    if (mi > va) cout << "Misha";
    else if (mi < va) cout << "Vasya";
    else cout << "Tie";

    return 0;
}