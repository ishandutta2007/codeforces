#include <bits/stdc++.h>

using namespace std;

char s[1010];
string str;
int ans[1010];

int main() {
    scanf("%s", s); str = s;

    for(int i = 0; i < str.size(); i++) {
        if(i + 1 < str.size() && str[i] != str[i+1]) {
            ans[i] = 1;
            for(int j = 0, k = i; j < k; j++, k--)
                swap(str[j], str[k]);
        }
        if(i + 1 == str.size() && str[0] == 'b') {
            ans[i] = 1;
            reverse(str.begin(), str.end());
        }
    }

    for(int i = 0; i < str.size(); i++)
        printf("%d ", ans[i]);
    return 0;
}