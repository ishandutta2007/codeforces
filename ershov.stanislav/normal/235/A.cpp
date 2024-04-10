#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n<3) cout << n;
    else {
        if (n%2==1) cout << n*(n-1)*(n-2);
        else {
            long long a = max(n*(n-1)*(n-2)/2, (n-1)*(n-2)*(n-3));
            if (n%3!=0) a = max(a, n*(n-1)*(n-3));
            cout << a;
        }
    }
    return 0;
}