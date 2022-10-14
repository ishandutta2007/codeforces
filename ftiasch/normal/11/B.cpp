// Codeforces Beta Round #10
// Problem B -- Jumping Back
#include <iostream>

using namespace std;

int main()
{
    long long x;
    cin >> x;
    if(x < 0)
        x = -x;
    long long s = 0, i = 0;
    for(; s < x || (s - x) & 1; s += ++ i);
    cout << i << "\n";
    return 0;
}