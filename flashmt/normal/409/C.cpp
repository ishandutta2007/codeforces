#include <bits/stdc++.h>
using namespace std;
const int NEED[] = {1, 1, 2, 7, 4};

int main()
{
    int a[5], ans = 100;
    for (int i = 0; i < 5; i++) 
    {
        cin >> a[i];
        ans = min(ans, a[i] / NEED[i]);
    }
    cout << ans << endl;
}