#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n;
string str;
char s[100100];
map<char,int> f;

int main() {
    scanf("%s",s);
    str = s;

    for(int i=0; i<str.size(); i++) {
        f[str[i]]++;
    }

    int ans = f['B'];
    ans = min(ans, f['u'] / 2);
    ans = min(ans, f['l']);
    ans = min(ans, f['b']);
    ans = min(ans, f['a'] / 2);
    ans = min(ans, f['s']);
    ans = min(ans, f['r']);

    printf("%d\n", ans);
    return 0;
}