#include <iostream>

using namespace std;
int n,x,y,q;
int main()
{
    cin>>n>>x>>y;
    if (y*n % 100)
        q=y*n/100 + 1;
    else q=y*n/100;
    if (q > x) cout << q-x;
    else cout << 0;

    return 0;
}