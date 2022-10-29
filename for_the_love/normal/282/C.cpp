#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string s, t;
int i, res, ans;
int main(){
    cin >> s;
    cin >> t;
    for (i = 0; i < s.size(); i++)
    if (s[i] == '1') ans = 1;
    for (i = 0; i < t.size(); i++)
    if (t[i] == '1') res = 1;
    if (s.size() != t.size()) printf("NO");
    else if (res != ans) printf("NO");
    else printf("YES");
}