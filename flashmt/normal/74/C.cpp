#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cin >> m >> n;
    m--; n--;
    while (m && n)
    {
        if (m>=n) m%=n;
        else n%=m;  
    }
    cout << m+n+1 << endl;
    return 0;
}