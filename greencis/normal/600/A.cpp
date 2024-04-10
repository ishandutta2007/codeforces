#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

char s[200005],a[200005],b[200005],cur[200005];
int ai,bi,idx;
int wasa, wasb;

int main()
{
    gets(s);
    for (int i = 0; ; ++i) {
        if (s[i] == ',' || s[i] == ';' || s[i] == 0) {
            bool isnum = true;
            for (int j = 0; j < idx; ++j) {
                if (cur[j] < '0' || cur[j] > '9') {
                    isnum = false;
                    break;
                }
            }
            isnum &= (idx >= 1 && (cur[0] != '0' || (cur[0] == '0' && idx == 1)));
            if (isnum) {
                if (wasa) a[ai++] = ',';
                for (int j = 0; j < idx; ++j)
                    a[ai++] = cur[j];
                wasa = 1;
            } else {
                if (wasb) b[bi++] = ',';
                for (int j = 0; j < idx; ++j)
                    b[bi++] = cur[j];
                wasb = 1;
            }
            idx = 0;
        } else {
            cur[idx++] = s[i];
        }

        if (s[i] == 0)
            break;
    }

    if (wasa)
        printf("\"%s\"\n",a);
    else
        printf("-\n");

    if (wasb)
        printf("\"%s\"\n",b);
    else
        printf("-\n");

    return 0;
}