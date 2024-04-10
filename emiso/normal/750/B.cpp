#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int main() {
    int n, pos = 20000, flag = 1, d;
    char s[40];
    string str;

    scanf("%d",&n);

    for(int i=0; i<n; i++) {
        scanf(" %d %s", &d, s);
        str = s;

        if(pos == 0 && str != "North") flag = 0;
        if(pos == 20000 && str != "South") flag = 0;

        if(str == "North") pos += d;
        if(str == "South") pos -= d;

        if(pos < 0 || pos > 20000) flag = 0;

    }

    if(pos != 20000) flag = 0;

    printf("%s\n", (flag) ? "YES" : "NO");
    return 0;
}