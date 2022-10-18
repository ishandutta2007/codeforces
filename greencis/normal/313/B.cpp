#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

char s[200005];
int n,m,l,r,a[200005];

int main()
{
    scanf("%s",s);
    n = strlen(s);
    for (int i = 1; i < n; ++i) {
        a[i] = a[i-1];
        if (s[i] == s[i-1]) ++a[i];
    }
    scanf("%d",&m);
    while (m--) {
        scanf("%d%d",&l,&r);
        --l; --r;
        printf("%d\n",a[r]-a[l]);
    }
    return 0;
}