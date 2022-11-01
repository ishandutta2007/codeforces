#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;

int freq[28], flag = 0;
int n, l=0, r=-1, q=0,rep=0;
string str;

void pf(int left, int right) {
    rep = 0;

    for(int i=left; i < right; i++) {
        if(str[i] == '?') {
            if(rep == 26) str[i] = 'A';
            else
                for(int j=0;j<26;j++)
                    if(freq[j] == 0) {
                        str[i] = 'A' + j;
                        freq[j] = 1;
                        rep++;
                        break;
                    }
            }
    }

    for(int i=0;i<str.size();i++) {
        if(str[i] == '?') printf("A");
        else printf("%c",str[i]);
    }
    printf("\n");
}

int main() {
    char s[100100];

    scanf("%s",s);
    str = s;

    if(str.size() < 26) {
        printf("-1\n");
        return 0;
    }

    for(r=0; r<26; r++) {
        if(str[r] == '?') q++;
        else {
            if(freq[str[r] - 'A'] == 0)
                rep++;
            freq[str[r] - 'A']++;
        }
    }

    //printf("%d %d\n", 26 - rep, q);
    // ABCDEFGHIJKLMNOPQRSTUVWXYZ

    if(26 - rep <= q) {
        pf(l,r);
        return 0;
    }

    for(;r < str.size(); r++, l++) {
        if(str[r] == '?') q++;
        else {
            if(freq[str[r] - 'A'] == 0)
                rep++;
            freq[str[r] - 'A']++;
        }

        if(str[l] == '?') q--;
        else {
            if(freq[str[l] - 'A'] == 1)
                rep--;
            freq[str[l] - 'A']--;
        }

        if(26 - rep <= q) {
            pf(l+1,r+1);
            return 0;
        }
    }

    printf("-1\n");
    return 0;
}