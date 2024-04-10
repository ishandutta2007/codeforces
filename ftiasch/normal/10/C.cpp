// Codeforces Beta Round #10
// Problem C -- Digital Root
#include <cstring>
#include <iostream>
#include <algorithm>

#define maxN 1000001

using namespace std;

int n, s[maxN], d[maxN];
long long c[10];

int main()
{
    cin >> n;
    s[0] = 0;
    for(int i = 1; i != maxN; ++ i)
        s[i] = s[i / 10] + i % 10;
    for(int i = 1; i != maxN; ++ i)
        d[i] = s[i] < 10? s[i]: d[s[i]];
    memset(c, 0, sizeof(c));
    for(int i = 1; i <= n; ++ i)
        c[d[i]] ++;
    long long a = 0;
    for(int i = 0; i != 10; ++ i)
        for(int j = 0; j != 10; ++ j)
            a += c[i] * c[j] * c[d[i * j]];
    for(int i = 1; i <= n; ++ i)
        for(int j = 1; i * j <= n; ++ j)
            if(d[d[i] * d[j]] == d[i * j])
                a --;
    cout << a << "\n";
    return 0;
}