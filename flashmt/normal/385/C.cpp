#include <bits/stdc++.h>
using namespace std;
const int MAX_A = int(1e7);

int n, a[1000100], smallestPrimeFactor[MAX_A + 10];
long long cnt[MAX_A + 10];

int main()
{
    ios::sync_with_stdio(0);
    int x, y, m;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    for (int i = 2; i <= MAX_A; i++) smallestPrimeFactor[i] = i;
    
    for (int i = 2; i * i <= MAX_A; i++)
        if (smallestPrimeFactor[i] == i)
            for (int j = i * i; j <= MAX_A; j += i)
                if (smallestPrimeFactor[j] == j)
                    smallestPrimeFactor[j] = i;
                
    for (int i = 0; i < n; i++) 
        while (a[i] > 1)
        {
            int factor = smallestPrimeFactor[a[i]];
            cnt[factor]++;
            while (a[i] % factor == 0) a[i] /= factor;
        }
    
    for (int i = 2; i <= MAX_A; i++) cnt[i] += cnt[i - 1];
            
    cin >> m;
    while (m--)
    {
        cin >> x >> y;
        if (x > MAX_A) cout << 0 << endl;
        else cout << cnt[min(y, MAX_A)] - cnt[x - 1] << endl;
    }
}