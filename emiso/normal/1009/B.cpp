#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll os, f;
char s[MN]; string str;
vector<int> ans;

int main() {
    scanf("%s", s); str = s;

    for(int i = 0; i < str.size(); i++) {
        if(str[i] == '0') ans.push_back(0);
        else if(str[i] == '2') ans.push_back(2);
        else os++;
    }

    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] == 2) {
            while(os) {
                os--;
                printf("1");
            }
            printf("2");
        }
        else printf("0");
    }
    while(os) {
        os--;
        printf("1");
    }
    puts("");
    return 0;
}