#include <iostream>

using namespace std;

int n,q,t,a[100100];

int main()
{
    cin >> n;
    int r = 0;
    while(n--) {
        cin >> q >> t;
        ++a[q*60+t];
        r = max(r,a[q*60+t]);
    }
    cout << r;
    return 0;
}