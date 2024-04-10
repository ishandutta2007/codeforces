#include <bits/stdc++.h>

#define MN 1001000
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll lin, per;
char s[MN]; string str;

int main() {
    scanf("%s", s); str = s;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == 'o') per++;
        else if(str[i] == '-') lin++;
    }

    if(per == 0 || lin % (per) == 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}