#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

/* qwertyuiop
   asdfghjkl;
   zxcvbnm,./ */
string s1="qwertyuiop", s2 = "asdfghjkl;", s3="zxcvbnm,./";

char d[9],s[999];

int main()
{
    cin >> d >> s;
    for (int i = 0; s[i]; ++i) {
        if (s1.find(s[i]) != -1) {
            int idx = s1.find(s[i]);
            if (*d == 'R') --idx;
            else ++idx;
            putc(s1[idx], stdout);
        }
        else if (s2.find(s[i])  != -1) {
            int idx = s2.find(s[i]);
            if (*d == 'R') --idx;
            else ++idx;
            putc(s2[idx], stdout);
        }
        else {
            int idx = s3.find(s[i]);
            if (*d == 'R') --idx;
            else ++idx;
            putc(s3[idx], stdout);
        }
    }

    return 0;
}