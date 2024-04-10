#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n;
char s[MN]; string str;

int main() {
    scanf("%s",s);
    str = s;

    n = str.size();
    if(n == 1) {
        puts("YES");
        return 0;
    }
    for(int i=0; i<n; i++) {
        int flag = 1;

        for(int j=0;j<n;j++) {
            if(j == n - j - 1) continue;

            if(j == i || n - j - 1 == i) {
                if(str[j] != str[n - j - 1]) continue;
                else flag = 0;
            }
            if(str[j] != str[n - j - 1]) flag = 0;
        }

        if(flag) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");
    return 0;
}