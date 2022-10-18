#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

string s;
char repl[999];
inline bool open(char c) { return c == '<' || c == '(' || c == '[' || c == '{'; }
inline bool close(char c) { return c == '>' || c == ')' || c == ']' || c == '}'; }

int main()
{
    cin >> s;
    int balance = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (open(s[i])) ++balance;
        else --balance;
        if (balance < 0) { cout << "Impossible"; return 0; }
    }
    if (balance > 0) { cout << "Impossible"; return 0; }
    repl['('] = ')'; repl[')'] = '(';
    repl['['] = ']'; repl[']'] = '[';
    repl['<'] = '>'; repl['>'] = '<';
    repl['{'] = '}'; repl['}'] = '{';

    vector<char> v;
    int ans = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (open(s[i])) v.push_back(s[i]);
        else {
            if (v.back() != repl[s[i]]) ++ans;
            v.pop_back();
        }
    }
    cout << ans;
    return 0;
}