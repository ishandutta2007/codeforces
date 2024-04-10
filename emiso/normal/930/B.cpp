#include <bits/stdc++.h>

#define MN 100100
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, in[26], cont;
char s[MN]; string str;
vector<int> occ[26];

void _add(int idx) {
    int i = idx % n;
    if(in[str[i]-'a'] == 0) cont++;
    if(in[str[i]-'a'] == 1) cont--;
    in[str[i]-'a']++;
}

void _rem(int idx) {
    int i = idx % n;
    if(in[str[i]-'a'] == 2) cont++;
    if(in[str[i]-'a'] == 1) cont--;
    in[str[i]-'a']--;
}

double ans;

int main() {
    scanf("%s", &s);
    str = s;
    n = str.size();

    for(int i = 0; i < n; i++) {
        occ[str[i]-'a'].push_back(i);
    }

    for(ll c = 0; c < 26; c++) {
        ll maxi = 0;

        if(occ[c].size() == 1) maxi = 1;
        else for(int i = 1; i < n; i++) {
            for(int j : occ[c]) _add(j + i);
            maxi = max(maxi, cont);
            for(int j : occ[c]) _rem(j + i);
        }
        ans += maxi * 1.0 / n;
    }

    printf("%.9f\n", ans);
    return 0;
}