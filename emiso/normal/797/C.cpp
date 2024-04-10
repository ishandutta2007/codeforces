#include <bits/stdc++.h>

using namespace std;

int co[30];
vector<char> ans;

int main() {
    char s[100100];
    string str;

    scanf("%s", s); str = s;
    for(int i = 0; i < str.size(); i++) {
        co[str[i] - 'a']++;
    }

    int cur = 0;
    stack<char> t;
    for(int i = 0; i < str.size(); i++) {
        while(!co[cur] && cur < 26) cur++;

        while(!t.empty() && t.top() - 'a' <= cur) {
            ans.push_back(t.top());
            t.pop();
        }

        if(str[i] - 'a' == cur)
            ans.push_back(str[i]);

        else t.push(str[i]);

        co[str[i] - 'a']--;
    }

    while(!t.empty()) {
        ans.push_back(t.top());
        t.pop();
    }

    for(char c : ans) printf("%c", c);
    puts("");
    return 0;
}