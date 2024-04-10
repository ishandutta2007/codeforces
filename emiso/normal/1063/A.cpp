#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ans;
char s[MN]; string str;
map <char, int> f;

int main() {
    scanf("%lld", &n);    
    scanf("%s", s); str = s;
    for(char c : str) f[c]++;

    for(auto p : f)
        for(int i = 0; i < p.second; i++)
            printf("%c", p.first);
    puts("");
    return 0;
}