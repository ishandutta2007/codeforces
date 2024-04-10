#include <bits/stdc++.h>
using namespace std;

int n, kin, x = 0, y = 0, rj = 0;
string s;

int main()
{
    scanf("%d", &n);
    cin >> s;
    if (s [0] == 'U') kin = 0;
    else kin = 1;
    for (int i = 0; i < n; i++)
    {
        if (s [i] == 'U') y++;
        else x++;
        if (x > y && kin == 0) {kin = 1; rj++;}
        else if (x < y && kin == 1) {kin = 0; rj++;}
    }
    printf("%d", rj);
    return 0;
}