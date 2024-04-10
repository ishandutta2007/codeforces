#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    int n, k, x[111111], a=-1, b=-1, c, max=-1, m2=0, r;
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> c;
        if (c!=b&&a==c)x[b]++;
        if (c!=b) a=b, b=c, x[c]++;
        if (c>max) max=c;
    }
    for (int i=k; i>0; i--) if (m2<=x[i]) r=i, m2=x[i];
    cout << r;
    return 0;
}