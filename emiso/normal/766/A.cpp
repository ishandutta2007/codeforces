#include <bits/stdc++.h>

#define MN 1000100
#define w1 while(1)

#define getstr(s) scanf("%s", s);

using namespace std;
typedef long long ll;

int n, a[MN], ans;
char s[MN];
string str, str2;

int main() {
    getstr(s);
    str = s;
    getstr(s);
    str2 = s;

    if(str == str2) printf("-1\n");

    else
    printf("%d\n", max(str.size(), str2.size()));

    return 0;
}