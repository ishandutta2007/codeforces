#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)
typedef long long int ll;

const int inf = 1e9;

char a, b;
char c, d;

bool z = 0;

int main()
{
    cin >> a >> b;
    REP(i, 0, 5)
    {
        cin >> c >> d;
        if (z == 1) continue;
        if(c == a || d == b)
        {
            cout << "YES" << endl;
            z = 1;
        }
    }
    if(!z) cout << "NO" << endl;
    return 0;
}