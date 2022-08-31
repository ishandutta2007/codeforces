#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define LL long long

using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> a(100001, 0);
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    LL d1 = 0, d2 = 0;
    for (int i = 1; i < 100001; i++){
        LL dd = d2;
        d2 = d1;
        d1 = max(d1, dd + 1ll * a[i] * i);
    }
    cout << d1 << "\n";

    return 0;
}