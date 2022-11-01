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

int main() {
    scanf("%s", s);
    str = s;
    str2 = s;
    reverse(str2.begin(), str2.end());

    printf("%s\n", (str + str2).c_str());
    return 0;
}