#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, freq[3], tot;
char s[MN]; string str;

int main() {
    scanf("%s", &s);
    str = s;

    for(int i=0; i<str.size(); i++) {
        tot += str[i] - '0';
        freq[(str[i] - '0') % 3]++;
    }

    if(tot % 3 == 0)
        printf("%s\n", s);

    else if(tot % 3 == 1) {
        string str1, str2;
        string ans;

        if(freq[1]) {
            string cmp1; int flag = 1, flag2 = 1;
            for(int i= str.size()-1; i>=0; i--) {
                if(((str[i] - '0') % 3) == 1 && flag) flag--;
                else cmp1 += str[i];
            } reverse(cmp1.begin(), cmp1.end());
            for(int i=0; i<cmp1.size(); i++) {
                if(cmp1[i] == '0' && flag2);
                else {
                    flag2 = 0;
                    str1 += cmp1[i];
                }
            }
            if(str1 == "" && cmp1.size() > 0 && cmp1[0] == '0') str1 = "0";
            if(str1.size() > ans.size()) ans = str1;
        }
        if(freq[2] >= 2) {
            string cmp1; int flag = 2, flag2 = 1;
            for(int i= str.size()-1; i>=0; i--) {
                if((str[i] - '0') % 3 == 2 && flag) flag--;
                else cmp1 += str[i];
            } reverse(cmp1.begin(), cmp1.end());
            for(int i=0; i<cmp1.size(); i++) {
                if(cmp1[i] == '0' && flag2);
                else {
                    flag2 = 0;
                    str2 += cmp1[i];
                }
            }
            if(str2 == "" && cmp1.size() > 0 && cmp1[0] == '0') str2 = "0";
            if(str2.size() > ans.size()) ans = str2;
        }

        if(ans != "") printf("%s\n", ans.c_str());
        else puts("-1");
    }

    else {
        string str1, str2;
        string ans;

        if(freq[2]) {
            string cmp1; int flag = 1, flag2 = 1;
            for(int i= str.size()-1; i>=0; i--) {
                if((str[i] - '0') % 3 == 2 && flag) flag--;
                else cmp1 += str[i];
            } reverse(cmp1.begin(), cmp1.end());
            for(int i=0; i<cmp1.size(); i++) {
                if(cmp1[i] == '0' && flag2);
                else {
                    flag2 = 0;
                    str1 += cmp1[i];
                }
            }
            if(str1 == "" && cmp1.size() > 0 && cmp1[0] == '0') str1 = "0";
            if(str1.size() > ans.size()) ans = str1;
        }
        if(freq[1] >= 2) {
            string cmp1; int flag = 2, flag2 = 1;
            for(int i= str.size()-1; i>=0; i--) {
                if((str[i] - '0') % 3 == 1 && flag) flag--;
                else cmp1 += str[i];
            } reverse(cmp1.begin(), cmp1.end());
            for(int i=0; i<cmp1.size(); i++) {
                if(cmp1[i] == '0' && flag2);
                else {
                    flag2 = 0;
                    str2 += cmp1[i];
                }
            }
            if(str2 == "" && cmp1.size() > 0 && cmp1[0] == '0') str2 = "0";
            if(str2.size() > ans.size()) ans = str2;
        }

        if(ans != "") printf("%s\n", ans.c_str());
        else puts("-1");
    }

    return 0;
}