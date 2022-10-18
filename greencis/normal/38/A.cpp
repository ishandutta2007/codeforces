#include <iostream>

using namespace std;

int n,a[100005],x,y,res;

int main()
{
    cin>>n;
    for (int i = 1; i < n; ++i)
        cin>>a[i];
    cin>>x>>y;
    for (int i = x; i < y; ++i)
        res+=a[i];
    cout << res;
    return 0;
}