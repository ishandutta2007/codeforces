#include <iostream>
#include <iomanip>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <queue>
#include <string>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <ctime>

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define float long double
#define LL long long
#define itn int
#define mp make_pair
#define x first
#define y second

using namespace std;

int base = 1e9 + 7;

int main(){

//  freopen("combo.in", "r", stdin);
//  freopen("combo.out", "w", stdout);
    
    int t, k;
    cin >> t >> k;
    int n = 111111;
    vector<int> a(n, 0), s(n, 0);
    a[0] = 1;
    s[0] = 1;
    for (int i = 1; i < n; i++){
        if (i >= k) a[i] = s[i - k] + 1; else
        a[i] = 1;
        s[i] = (s[i - 1] + a[i]) % base;
    }
    while (t--){
        int x, y;
        cin >> x >> y;
        cout << (s[y] - s[x - 1] + base) % base << "\n";
    }

    return 0;
}