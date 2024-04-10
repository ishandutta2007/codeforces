#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int na,nb,k,m;
int a[100005], b[100005];

int main()
{
    scanf("%d%d%d%d",&na,&nb,&k,&m);
    for (int i = 0; i < na; ++i) scanf("%d", a + i);
    for (int i = 0; i < nb; ++i) scanf("%d", b + i);
    sort(a, a + na);
    sort(b, b + nb);
    if (a[k - 1] < b[nb - m]) puts("YES");
    else puts("NO");
    return 0;
}