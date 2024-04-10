#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;



int main(){

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    stack<char> S;
    for (int i=0;i<s.size();++i){
        if (!S.empty() && S.top() == s[i]){
            S.pop();
        }
        else{
            S.push(s[i]);
        }
    }
    puts(S.empty() ? "Yes" : "No");
}