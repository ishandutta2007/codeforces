#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,a,cur;
char s[300005],z[9];

int main()
{
    scanf("%d%d%s",&n,&m,s+1);
    for (int i = 1; i <= n; ++i) cur += s[i] == s[i+1] && s[i] == '.';
    while (m--) {
        scanf("%d%s",&a,z);
        if (*z != '.') {
            if (s[a] == '.') {
                if (s[a-1] == '.') --cur;
                if (s[a+1] == '.') --cur;
            }
        } else {
            if (s[a] != '.') {
                if (s[a-1] == '.') ++cur;
                if (s[a+1] == '.') ++cur;
            }
        }
        s[a] = *z;
        printf("%d\n", cur);
    }

    return 0;
}