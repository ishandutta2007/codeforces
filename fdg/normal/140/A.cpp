#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <memory.h>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    double R,r;
    cin >> n >> R >> r;
    if (R<r) {
        cout << "NO\n";
        return 0;
    }
    if (R-r<r) {
        if (n==1) cout << "YES\n";
        else cout << "NO\n";
        return 0;
    }
    double l=acos(sqrt((R-r)*(R-r)-r*r)/(R-r)),Pi=3.141592653589793238462;
    int cnt=Pi/l;
//  cout << cnt << endl;
    if (cnt>=n) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}