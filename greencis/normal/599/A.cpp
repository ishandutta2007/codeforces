#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;


int main()
{
    ll d1, d2, d3;
    cin >> d1 >> d2 >> d3;
    cout << min(d1, d2 + d3) + min(d3, d1 + d2) + min(d2, d3 + d1) << endl;
}