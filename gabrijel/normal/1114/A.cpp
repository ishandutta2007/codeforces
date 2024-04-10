#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

int x, y, z, a, b, c;

int main()
{
    cin >> x >> y >> z >> a >> b >> c;
    if(x > a)
    {
        cout << "NO" << endl;
        exit(0);
    }
    else
    {
        a -= x;
    }
    if(y > a + b)
    {
        cout << "NO" << endl;
        exit(0);
    }
    else
    {
        a -= y;
    }
    if(a + b + c >= z)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}