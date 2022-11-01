#include <bits/stdc++.h>

using namespace std;

char s[1000100];
string a, b;

int main() {
    scanf("%s", s); a = s;
    scanf("%s", s); b = s;
    if(a.size() < b.size()) {
        string to_add = "";
        for(int i = 0; i < (int)b.size() - (int)a.size(); i++)
            to_add += '0';
        a = to_add + a;
    } else {
        string to_add = "";
        for(int i = 0; i < (int)a.size() - (int)b.size(); i++)
            to_add += '0';
        b = to_add + b;
    }
    assert(a.size() == b.size());
    for(int i = 0; i < a.size(); i++) {
        if(a[i] < b[i]) {
            puts("<");
            return 0;
        }
        if(a[i] > b[i]) {
            puts(">");
            return 0;
        }
    }
    puts("=");
    return 0;
}