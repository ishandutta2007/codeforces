#include <iostream>
#include <fstream>
using namespace std;

int n,a[20005],res=-2e9,s[20005];

int main()
{
    ios_base::sync_with_stdio(0);
    scanf("%d",&n);
    for (int i = 0; i < n; ++i)
        scanf("%d",&a[i]);
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0 && n / i >= 3) {
            for (int j = 0; j < i; ++j) s[j] = 0;
            for (int j = 0; j < n; ++j) s[j % i] += a[j];
            for (int j = 0; j < i; ++j)
                if (s[j] > res)
                    res = s[j];
        }
    }
    printf("%d",res);
    return 0;
}