#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n;
ll ans, a[MN];
char s[MN]; string str, str2;

bool vow(char a) {
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' || a == 'y';
}

int main() {
    scanf("%d", &n);
    scanf("%s", &s);
    str = s;
    str2 = "";

    for(int i=0; i<str.size(); i++) {
        if(i && vow(str[i]) && vow(str[i-1])) continue;
        str2 += str[i];
    }

    printf("%s\n", str2.c_str());
    return 0;
}