#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans, qa, na, tna, ta;
char s[MN]; string str;

int main() {
    scanf("%s", s); str = s;

    for(int i = 0; i < str.size(); i++) {
        qa += (str[i] == 'a');
        na += (str[i] != 'a');
    }

    for(int i = 0; i < str.size(); i++) {
        ta += (str[i] == 'a');
        tna += (str[i] != 'a');

        if(ta == qa && 2*tna == na) {
            string p, q, r;

            for(int j = 0; j <= i; j++)
                if(str[j] != 'a') p += str[j];
            for(int j = i+1; j < str.size(); j++)
                q += str[j];

            if(p == q) {
                for(int j = 0; j <= i; j++)
                    r += str[j];
                printf("%s\n", r.c_str());
                return 0;
            }
        }
    }

    puts(":(");
    return 0;
}