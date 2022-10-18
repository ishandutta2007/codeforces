#include <iostream>
#include <map>
#include <fstream>
using namespace std;

int n,m,a[1000005],b[1000005],res=0;
map<int,int> mp;
int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d",&b[i]);
    }

    int q = min(n,m);
    for (int i = q; i >= 0; --i) {
        bool good = true;
        for (int j = 0; j < i; ++j) {
            if (a[j] > b[m-i+j]) {
                good = false; break;
            }
        }
        if (good) {printf("%d",n-i);return 0;}
    }
    return 0;
}