#include <iostream>

using namespace std;

int main()
{
    int n,t;
    int p5=0,p0=0;
    cin >> n;
    while(n--){
        cin>>t;
        if (t == 5)
            ++p5;
        else ++p0;
    }

    int q = (p5 / 9) * 9;
    if (q == 0) {
        if (p0 == 0)
            cout << -1;
        else cout << 0;
    } else {
        if (p0 == 0)
        {
            cout << -1;
            return 0;
        }
        while (q--)
            cout << 5;
        while(p0--)
            cout << 0;
    }

    return 0;
}