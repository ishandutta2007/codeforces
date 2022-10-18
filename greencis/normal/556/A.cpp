#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n, sti;
char s[200005], st[200005];

int main()
{
    scanf("%d%s", &n, s);
    for (int i = 0; i < n; ++i) {
        st[sti++] = s[i];
        if (sti > 1 && st[sti - 1] + st[sti - 2] == 97) sti -= 2;
    }
    printf("%d",sti);

    return 0;
}