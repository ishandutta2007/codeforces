#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,a,b,x;
char s[1001005];

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&a,&b);
        if (x + a <= 500 && x + a >= -500) s[i] = 'A', x += a;
        else s[i] = 'G', x -= b;
    }
    puts(s);

    return 0;
}