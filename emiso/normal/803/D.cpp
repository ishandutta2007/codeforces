#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n;
char s[MN]; string str;

int ok(int w) {
    int l = 1, i = 0, sz = 0;
    while(i < str.size()) {
        string word = "";
        while(i < str.size() && str[i] != ' ' && str[i] != '-') {
            word += str[i];
            i++;
        }
        if(i < str.size() && (str[i] == ' ' || str[i] == '-')) word += str[i], i++;

        if(sz + word.size() > w) {
            l++;
            sz = 0;
        }
        sz += word.size();
        if(sz > w) return 9999999;
    }

    return l;
}

int main() {
    scanf("%d ", &n);
    getline(cin, str);

    int l=1, r=str.size();
    while(l < r) {
        int m = (l + r)/2;
        if(ok(m) <= n) r = m;
        else l = m + 1;
    }

    printf("%d\n", l);
    return 0;
}