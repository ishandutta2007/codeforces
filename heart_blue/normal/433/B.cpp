#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
long long a[N];
long long b[2][N];
int main()
{
    int n;
    cin >> n;
    memset(b,0,sizeof(0));
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) b[0][i] = a[i]+b[0][i-1];
    sort(a+1,a+1+n);
    for(int i = 1; i <= n; i++) b[1][i] = a[i]+b[1][i-1];
    int m;
    cin >> m;
    int t,l,r;
    while(m--)
    {
        cin >> t >> l >> r;
        t--;
        cout << b[t][r] - b[t][l-1] << endl;
    }
    return 0;
}