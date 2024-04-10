#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>
#include <map>

using namespace std;

int main()
{
    int n, r=1, i;
    cin >> n;
    if (n==3) {
        cout << "210"; return 0;
    }
    else if (n<3) {cout << "-1"; return 0;}
    for (i=n-1; i>=3; i-=3) r=(r*1000)%210;
    if (i==1) r=(r*10)%210;
    if (i==2) r=(r*100)%210;
    r=210-r;
    cout << '1';
    for (int i=1; i<n-3; i++) cout << '0';
    if (r<100) cout << '0';
    cout << r;
    return 0;
}