#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string s, ans;
int opt, i;
int main(){
    getline(cin, s);
    opt = 0; ans = "";
    for (i = 0; i < s.size(); i++){
        if (s[i] == ' '){
            if (opt == 1){
                cout << '<' << ans << '>' << endl;
                ans = "";
                opt = 0;
            }
            if (opt == 2) ans += " ";
        }else if (s[i] == '\"'){
            if (!opt) opt = 2;
            else if (opt == 2){
                cout << '<' << ans << '>' << endl;
                ans = "";
                opt = 0;
            }
        }else{
            ans += s[i];
            if (!opt) opt = 1;
        }
    }
    if (ans != "") cout << '<' << ans << '>' << endl;
}