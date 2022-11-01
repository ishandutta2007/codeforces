#include <bits/stdc++.h>

#define MN 100100

using namespace std;
typedef long long ll;

int n, x, y, z;
char s[MN]; string a, b, c;

int score(string &s) {
    map<char, int> freq;
    int maxi = 0;

    for(char c : s) {
        freq[c]++;
        maxi = max(maxi, freq[c]);
    }

    if(n == 0) return maxi;
    if(n == 1 && maxi == s.size()) return maxi - 1;
    return min(maxi + n, (int) s.size());
}

int main() {
    scanf("%d", &n);
    scanf("%s", s); a = s;
    scanf("%s", s); b = s;
    scanf("%s", s); c = s;

    x = score(a);
    y = score(b);
    z = score(c);

    if(x > y && x > z) printf("Kuro\n");
    else if(y > x && y > z) printf("Shiro\n");
    else if(z > x && z > y) printf("Katie\n");
    else printf("Draw\n");

    return 0;
}