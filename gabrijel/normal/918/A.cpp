#include <bits/stdc++.h>
using namespace std;

int n;
bool fibo [10000];

int main()
{
    cin >> n;
    int a = 1;
    int b = 1;
    int c = a + b;
    fibo [1] = 1;
    while (c < 10000)
    {
        fibo [c] = 1;
        a = b;
        b = c;
        c = a + b;
    }
    for (int i = 0; i < n; i++)
    {
     if (fibo [i + 1]) cout << "O";
     else cout << "o";
    }
    return 0;
}