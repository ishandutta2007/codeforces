#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

map<char, int> freq;
int best = 0;

int main() {
    int n;
    char s[290];
    string st;

    scanf("%d %s",&n, s);
    st = s;

    for(int i=0;i<st.size();i++) {
        freq[st[i]]++;
        if(st[i] != '?') best = max(best, freq[st[i]]);
    }

    for(int i=0;i<st.size();i++) {
        if(st[i] == '?') {
            if(freq['A'] < best) {
                //printf("%d %d\n", freq['A'], best);
                st[i] = 'A';
                freq['A']++;
                best = max(best, freq[st[i]]);
                freq['?']--;
            }
            else if(freq['G'] < best) {
                st[i] = 'G';
                freq['G']++;
                best = max(best, freq[st[i]]);
                freq['?']--;
            }
            else if(freq['C'] < best) {
                st[i] = 'C';
                freq['C']++;
                best = max(best, freq[st[i]]);
                freq['?']--;
            }
            else {
                st[i] = 'T';
                freq['T']++;
                best = max(best, freq[st[i]]);
                freq['?']--;
            }
        }
    }

    if(freq['A'] != best || freq['G'] != best || freq['C'] != best || freq['T'] != best || freq['?'] != 0) {
        printf("===\n");
        return 0;
    }

    printf("%s\n",st.c_str());
    return 0;
}