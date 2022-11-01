#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, q, freq[26], freq2[26];
char s[MN]; string str, str2;

bool ok(ll suit) {
    long long desired, quest = q;
    for(int i=0; i<26; i++) {
        desired = freq2[i] * suit;
        quest -= max(0LL, (desired - freq[i]));
    }

    return quest >= 0;
}

void fillq(ll suit) {
    ll letter = 0;
    for(char &c : str) {
        if(c != '?') continue;
        while(letter < 26 && freq[letter] >= freq2[letter] * suit) {
            letter++;
        }

        if(letter < 26) {
            c = 'a' + letter;
            freq[letter]++;
        }

        else {
            c = 'a';
            freq[0]++;
        }
    }
}

int main() {
    scanf("%s", s);
    str = s;

    scanf("%s", s);
    str2 = s;

    for(char c : str) {
        if(c == '?') q++;
        else freq[c - 'a']++;
    }

    for(char c : str2) {
        freq2[c - 'a']++;
    }

    int l = 0, r = 1000000;
    while(l < r) {
        int m = (l + r + 1) / 2;
        if(ok(m)) l = m;
        else r = m - 1;
    }

    fillq(l);
    printf("%s\n", str.c_str());
    return 0;
}