// Codeforces Beta Round #10
// Poblem E -- Greedy Change
#include <iostream>

#define maxN 400

using namespace std;

int n, a[maxN];

int main()
{
    cin >> n;
    for(int i = 0; i != n; ++ i)
        cin >> a[i];
    int r = -1;
    for(int i = 1; i != n; ++ i)
        for(int j = i; j != n; ++ j)
        {
            int m = a[i - 1] - 1, c = 0;
            for(int k = i; k <= j; ++ k)
                c += m / a[k], m %= a[k];
            int l = m = a[i - 1] - 1 - m + a[j], t = 0;
            for(int k = 0; k != n; ++ k)
                t += m / a[k], m %= a[k];
            if(c + 1 < t && (r == -1 || l < r))
                r = l;
        }
    cout << r << "\n";
    return 0;
}