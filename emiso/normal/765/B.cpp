#include <bits/stdc++.h>

#define MN 1000100
#define w1 while(1)

using namespace std;
typedef long long ll;

int n, a[MN], ans;
char s[550];
string str;

int main() {
    scanf("%s", s);
    str = s;
    int let = 'a', flag = 1;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] > let) flag = 0;
        else if(str[i] == let) let++;
    }

    printf("%s\n", flag ? "YES" : "NO");

    return 0;
}