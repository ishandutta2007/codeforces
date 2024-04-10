#include <iostream>

using namespace std;

long long n,m,a,res=0,b=1;

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a;
        res += a - b;
        if (b>a) res += n;
        b = a;
    }
    cout << res;

    return 0;
}