#include <iostream>

using namespace std;

int n,m,res,a[999];
char p[999][999];

int main()
{
    cin >>n >>m;
    for (int i = 0; i < n; ++i)cin>>p[i];

    for (int i = 0; i < n; ++i) {
        for (int j = 0 ; j <m;++j) {
            a[j] = max(a[j],p[i][j] - '0');
        }
    }

    for (int i = 0; i < n; ++i) {
        bool good = false;
        for (int j = 0; j < m; ++j) {
            if (p[i][j] - '0' == a[j]) {
                good = true;
            }
        }
        res += good;
    }
    cout<<res;
    return 0;
}