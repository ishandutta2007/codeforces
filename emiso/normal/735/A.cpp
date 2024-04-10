#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

int main() {
    int n,k,g,flag = 0;
    char s[110];
    string str;
    scanf("%d %d %s",&n, &k, s);
    str = s;

    for(int i=0; i<n; i++) {
        if(str[i] == 'G') {
            g = i;
            break;
        }
    }

    for(int i=g;i<n;i+=k) {
        if(str[i] == '#') break;
        if(str[i] == 'T') flag = 1;
    }

    for(int i=g;i>=0;i-=k) {
        if(str[i] == '#') break;
        if(str[i] == 'T') flag = 1;
    }

    printf("%s\n",flag ? "YES" : "NO");
    return 0;
}