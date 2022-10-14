// Codeforces Beta Round #6
// Problem A -- Triangle
#include <iostream>
#include <algorithm>

using namespace std;

int l[4];

int main()
{
    for(int i = 0; i < 4; ++ i)
        cin >> l[i];
    sort(l, l + 4);
    int t = -1;
    for(int i = 0; i < 4; ++ i)
        for(int j = i + 1; j < 4; ++ j)
            for(int k = j + 1; k < 4; ++ k)
              t = max(t, l[i] + l[j] - l[k]);
    if(t > 0)
        cout << "TRIANGLE\n";
    else
    if(t < 0)
        cout << "IMPOSSIBLE\n";
    else
        cout << "SEGMENT\n";
    return 0;
}