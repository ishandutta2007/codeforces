#include <iostream>

using namespace std;

int main()
{
    int n,k,r=0;
    cin>>n>>k;
    while (n--) {
        int t;
        cin >> t;
        int s = 0;
        while (t) {
            if (t%10 == 7 || t%10 == 4) ++s;
            t/=10;
        }
        r += s <= k;
    }
    cout << r;
    return 0;
}