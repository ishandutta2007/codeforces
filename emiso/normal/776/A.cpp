#include <bits/stdc++.h>

#define MN 1000100
#define w1 while(1)

using namespace std;
typedef long long ll;

int n, a[MN], ans;
char s[110], s2[110];
string str, str2, tmp, tmp2;

int main() {
    scanf("%s %s", s, s2);
    str = s;
    str2 = s2;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("%s %s\n", str.c_str(), str2.c_str());
        scanf("%s %s", s, s2);
        tmp = s;
        tmp2 = s2;
        if(tmp == str)
            str = tmp2;
        else str2 = tmp2;
    } printf("%s %s\n", str.c_str(), str2.c_str());

    return 0;
}