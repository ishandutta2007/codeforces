#include <bits/stdc++.h>
using namespace std;

int c(int n, int k)
{
    if (k > n) return 0;
    return !k || k == n ? 1 : c(n - 1, k) + c(n - 1, k - 1);
}

int main()
{
    string a, b;
    cin >> a >> b;
    int positionA = 0, positionB = 0, unknown = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '-') positionA--;
        else positionA++;
        if (b[i] == '-') positionB--;
        else if (b[i] == '+') positionB++;
        else unknown++;
    }
    
    int difference = abs(positionA - positionB);
    if (difference > unknown) cout << 0 << endl;
    else printf("%.9lf\n", c(unknown, (difference + unknown) / 2) * 1.0 / (1 << unknown));
}