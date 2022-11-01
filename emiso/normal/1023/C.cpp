#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, k, ans, forbid[MN], con = 2;
char s[MN]; string str;

int main() {
    scanf("%lld %lld %s", &n, &k, s);
    str = s;

    stack<int> lft;
    for(int i = 0; i < n; i++) {
        if(str[i] == '(') lft.push(i);
        else {
            int x = lft.top(); lft.pop();
            forbid[x] = con;
            forbid[i] = con;
            con += 2;
        }
    }

    int quant = k;
    for(int i = 0; i < n; i++) {
        if(forbid[i] <= quant)
            printf("%c", str[i]);
    }
    puts("");
    return 0;
}