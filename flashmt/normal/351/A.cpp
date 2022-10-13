#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cntZero = 0, sum = 0;
    string s;
    
    cin >> n;
    for (int i = 1; i <= n * 2; i++) 
    {
        cin >> s;
        int x = 0;
        for (int j = 0; j < int(s.size()); j++)
            if (s[j] != '.') x = x * 10 + s[j] - '0';
        x %= 1000;
        if (x == 0) cntZero++;
        else sum += x;
    }
    
    int ans = 1LL << 27;
    for (int i = max(0, n - cntZero); i <= n; i++) ans = min(ans, abs(sum - i * 1000));
    
    printf("%.3lf\n", ans * 0.001);
}