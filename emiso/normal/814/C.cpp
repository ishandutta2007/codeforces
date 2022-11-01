#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], q, m;
char s[MN], c; string str;

int query(int m, char c) {
    int best = 0, atual = 0, used = 0, l = 0;
    for(int i=0; i<n; i++) {
        if(str[i] == c) {
            atual++;
        }

        else {
            while(used == m) {
                if(str[l] == c) {
                    atual--;
                }
                else {
                    atual--;
                    used--;
                }

                l++;
            }
            if(used < m) {
                atual++;
                used++;
            }
        }

        //printf("%d %d %d %d\n", l, i, used, atual);
        best = max(best, atual);
    }

    return best;
}

int main() {
    scanf("%d %s %d", &n, s, &q);
    str = s;

    for(int i=0; i<q; i++) {
        scanf("%d %c",&m, &c);
        printf("%d\n", query(m, c));
    }

    return 0;
}