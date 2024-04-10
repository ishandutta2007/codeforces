#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    long double l=0, a=0, b;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> b;
        a+=(2*l+1)*b;
        l=b*(l+1);
    }
    cout << fixed << setprecision(6) << a;
    return 0;
}