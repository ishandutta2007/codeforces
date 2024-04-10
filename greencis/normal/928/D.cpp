#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int states = 0;
int words = 0;
vector<int> p;
vector<vector<int>> g;
vector<int> wordcnt;
vector<int> fin;

int add(string& s){
    vector<int> gone;
    int minTabPos = -1;
    int wordFin = -1;
    int cur = 0;
    for(int i = 0; i < s.length(); ++i){
        if(g[cur][s[i] - 'a'] == -1){
            p.push_back(states);
            g.push_back(vector<int>(26, -1));
            g[cur][s[i] - 'a'] = states;
            wordcnt.push_back(0);
            fin.push_back(0);
            cur = states++;
        }else{
            cur = g[cur][s[i] - 'a'];
        }
        gone.push_back(cur);
        if(minTabPos == -1 && wordcnt[cur] == 1){
            minTabPos = i;
        }
        if(wordcnt[cur] == 1 && fin[cur] == 1){
            wordFin = i;
        }
    }
    int res = s.length();
    if(wordFin != -1 && minTabPos != -1){
        res = s.length() + min(0, -wordFin + minTabPos + 1);
    }
    if(!fin[gone.back()]){
        for(auto u: gone){
            ++wordcnt[u];
        }
        ++words;
        fin[gone.back()] = 1;
    }
    //cerr << s << " " << minTabPos << " " << wordFin << " " << res << endl;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    states = 1;
    p.resize(1, -1);
    g.resize(1, vector<int>(26, -1));
    wordcnt.resize(1, 100);
    fin.resize(1, 0);
    char c;
    string text = "";
    string s = "";
    int ans = 0;
    string str;
    while(getline(cin, str)){
        text += str;
        text += "\n";
    }
    for(int i = 0; i < text.size(); ++i){
        if(text[i] >= 'a' && text[i] <= 'z'){
            s += text[i];
        }else{
            if(!s.empty()){
                ans += add(s);
                s = "";
            }
            ++ans;
        }
    }
    if(!s.empty()){
        ans += add(s);
        s = "";
    }
    cout << ans << endl;
}