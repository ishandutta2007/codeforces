#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;

#define forn(i, n) for (int i = 0; i < int(n); i++)

#define N 

int main() {
    ll n, m;
    scanf("%lld%lld", &n, &m);
    if(m > n) {cout << n; return 0;}

    ll low = 0, high = 2e9, mid;

    // n - sum(0, k-1) <= 0
    while(low+1 < high) {
        // cout << low << " " << high << endl;
        mid = (high+low)>>1;
        // cout << "F("<<mid<<") = " << n - mid*(mid-1)/2 << endl;
        if(n - mid*(mid-1)/2 <= m+mid) high = mid;
        else low = mid;
    }
    if(n - low*(low-1)/2 <= m+low) cout << low+m << endl;
    else cout << high+m << endl;
    return 0;
}