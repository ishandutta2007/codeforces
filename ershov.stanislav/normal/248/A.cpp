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
    int n, l, r, k=0, m=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> l >> r;
        if (l) k++;
        if (r) m++;
    }
    cout << min(k, n-k)+min(m, n-m);
    return 0;
}