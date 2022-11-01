#include <bits/stdc++.h>

using namespace std;

int n;
char s[500500];
string str[500500];

string order(int idx) {
    string ret = "";
    int sz = min(str[idx].size(), str[idx + 1].size());
    for(int i=0;i<sz;i++) {
        if(str[idx][i] == str[idx+1][i]) ret += str[idx][i];
        else if(str[idx][i] < str[idx+1][i]) return str[idx];
        else break;
    }

    return ret;
}

int main() {
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        scanf("%s", s);
        str[i] = s;
    }

    for(int i=n-2;i>=0;i--) {
        str[i] = order(i);
    }

    for(int i=0;i<n;i++) {
        printf("%s\n", str[i].c_str());
    }

    return 0;
}