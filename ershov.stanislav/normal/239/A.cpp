#include <iostream>

using namespace std;

int main()
{
    int y, k, n, i, j;
    cin >> y >> k >> n;
    j = i = (y+1) + k - (y+1)%k;
    if ((y+1)%k == 0) {j-=k; i-=k;}
    for (; i<=n; i+=k) cout << i - y << ' ';
    if (j > n) cout << -1;
    return 0;
}