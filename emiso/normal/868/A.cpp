#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MN], flag = 0, f1[26], f2[26];
//char s[MN]; string str;
string pass, st;

int main() {
    cin >> pass;
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        cin >> st;
        if(st == pass) flag = 1;
        f1[st[0] - 'a']++;
        f2[st[1] - 'a']++;
    }

    if(f1[pass[1] - 'a'] && f2[pass[0] - 'a']) flag = 1;

    if(flag) printf("YES\n");
    else printf("NO\n");
    return 0;
}