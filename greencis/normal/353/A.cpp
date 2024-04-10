#include <iostream>
#include <map>
using namespace std;

int n,x[999],y[999],l,r;

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        if (x[i] & 1) l ^= 1;
        if (y[i] & 1) r ^= 1;
    }
    
    if (l == 0 && r == 0) cout << "0";
    else if (l * r == 0) cout << "-1";
    else {
        bool good = false;
        for (int i = 0; i < n; ++i) {
            if ((x[i] ^ y[i]) & 1) { good = true; break;}
        }
        if (good) cout << "1"; else cout << -1;
    }

    return 0;
}