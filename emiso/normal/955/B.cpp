#include <bits/stdc++.h>

#define MN 1001000
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, ans, a[MN], flag = 1;
char s[MN]; string str;
map<char, int> freq;

int main() {
    scanf("%s", s); str = s;

    for(int i = 0; i < str.size(); i++) {
        freq[str[i]]++;
    }

    if(freq.size() > 4) flag = 0;
    if(freq.size() == 1) flag = 0;
    if(freq.size() == 2) {
        flag = 1;
        for(pair<char, int> p : freq) {
            if(p.second < 2) flag = 0;
        }
    }
    if(freq.size() == 3) {
        flag = 0;
        for(pair<char, int> p : freq) {
            if(p.second > 1) flag = 1;
        }
    }

    printf("%s\n", flag ? "YES" : "NO");

    return 0;
}