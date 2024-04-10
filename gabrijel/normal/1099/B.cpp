#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
#define REPN(i, a, b) for(int i = a; i >= b; i--)

int n;

int main()
{
    cin >> n;
    int s = sqrt(n);
    if(s * s == n)
    {
        cout << s + s << endl;
        return 0;
    }
    if(n <= s * s + s)
    {
        cout << s + s + 1 << endl;
    }
    else
    {
        cout << s + s + 2 << endl;
    }
    return 0;
}