#include <iostream>
#define int long long
using namespace std;
signed main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int x,y,k;
        cin >> x >> y >> k;
        cout << k+(k+y*k-2)/(x-1)+1 << "\n";
    }
}