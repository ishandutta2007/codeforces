#include <bits/stdc++.h>
using namespace std;

string s;
int A, sum[4444], cnt[40400];

int main()
{
    cin >> A >> s;
    int n = s.size();
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + s[i - 1] - '0';
    
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            cnt[sum[j] - sum[i]]++;
            
    long long ans = 0;
    
    if (!A)
    {
        long long nonZero = n * (n + 1LL) / 2 - cnt[0];
        cout << nonZero * cnt[0] * 2 + 1LL * cnt[0] * cnt[0] << endl;
        return 0;
    }
            
    for (int i = 1; i * i <= A; i++)
        if (A % i == 0)
        {
            int j = A / i;
            if (j > n * 9) continue;
            ans += 1LL * cnt[i] * cnt[j];
            if (i != j) ans += 1LL * cnt[i] * cnt[j];
        }
        
    cout << ans << endl;
}