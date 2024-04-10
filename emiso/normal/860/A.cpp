#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], cnt, eq;
char s[MN]; string st, ans;

bool isc(char c) {
    return !(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    scanf("%s", s); st = s;

    for(int i=0; i<st.size(); i++) {
        if(!isc(st[i])) cnt = eq = 0;
        else {
            if(cnt == 0) {
                cnt++;
                eq = 1;
            }

            else if(cnt == 1) {
                cnt++;
                if(s[i] != s[i-1]) eq = 0;
            }

            else {
                if(s[i] != s[i-1]) eq = 0;
                if(eq) {
                    cnt++;
                }

                else {
                    ans += " ";
                    cnt = eq = 1;
                }
            }
        }
        ans += st[i];
    }

    cout << ans << endl;
    return 0;
}