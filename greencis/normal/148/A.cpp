#include <iostream>

using namespace std;

int k,l,m,n,d,a[100100];

int main()
{
    cin>>k>>l>>m>>n>>d;
    for (int i = k-1; i < d; i+=k)
        a[i] = 1;
    for (int i = l-1; i < d; i+=l)
        a[i] = 1;
    for (int i = m-1; i < d; i+=m)
        a[i] = 1;
    for (int i = n-1; i < d; i+=n)
        a[i] = 1;
    int r = 0;
    for (int i = 0; i < d; ++i)
        r += a[i];
    cout << r;
    return 0;
}