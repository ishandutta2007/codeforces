// LOL
#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
const int N = 1e6 + 10, Mod = 1e9 + 7;
int n, m, q, r, t, a, b, c, d, A[N];
int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == 'a')
            cnt ++;
    printf("%d\n", min(cnt * 2 - 1, (int)s.size()));
    return (0);
}