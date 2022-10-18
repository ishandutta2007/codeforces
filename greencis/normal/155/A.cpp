#include <iostream>

using namespace std;

int n,a,b,c,r=0;

int main()
{
    cin >> n >> b;
    int mn = b, mx = b;
    while (--n) {
        a=b;
        cin>>b;
        if (b < mn) {
            mn = b;
            ++r;
        }
        if (b > mx) {
            mx = b;
            ++r;
        }
    }
    cout << r;
    return 0;
}