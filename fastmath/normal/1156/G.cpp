#include<bits/stdc++.h>
using namespace std;
#define int long long
int getp(string s) {
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '$' || s[i] == '^' || s[i] == '#' || s[i] == '&') {
            return i;
        }
    }   
    return -1;
}   
const int N = 1e5 + 7;
vector <int> g[N];
char op_[N];
map <string, int> last;
bool used[N];
string mem[N];
set <string> us;
string my_name[N];
int par[N];
mt19937 rnd(228);
string name(int u) {
    if (my_name[u].empty()) {
        if (g[u].empty()) {
            my_name[u] = mem[u];
        }   
        else {
            while (1) {
                string nn;
                for (int i = 0; i < 4; ++i) {
                    nn += (rnd() % 26) + 'a';
                }   
                if (us.find(nn) == us.end()) {
                    us.insert(nn);
                    my_name[u] = nn;
                    break;
                }   
            }   
        }   
    }
    return my_name[u];
}   
vector <string> ans;
void jfs(int u, bool c) {
    if (g[u].empty() || used[u]) return;
    used[u] = 1;
    for (int v : g[u]) jfs(v, 0);
    if (c) {
        ans.push_back("res=" + name(g[u][0]) + op_[u] + name(g[u][1]));
    }   
    else {
        ans.push_back(name(u) + '=' + name(g[u][0]) + op_[u] + name(g[u][1]));
    }
    us.insert(name(u));
    us.insert(name(g[u][0]));
    us.insert(name(g[u][1]));
}   
int ptr = 0;
void check(string s) {
    if (last.find(s) == last.end()) {
        mem[ptr] = s;
        last[s] = ptr++;
    }   
}   
pair <string, string> split(string s) {
    int p = -1;
    for (int j = 0; j < (int)s.size(); ++j) {
        if (s[j] == '=') {
            p = j;
            break;
        }   
    }   
    return {s.substr(0, p), s.substr(p + 1, (int)s.size() - p - 1)};
}   
vector <string> form(vector <string> a) {
    vector <string> ans;
    for (auto e : a) {
        auto t = split(e);
        if (t.first != t.second) {
            ans.push_back(e);
        }   
    }   
    return ans;
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        auto t = split(s);
        string l = t.first, r = t.second;
        int p = getp(r);
        if (p != -1) {
            string op_l = r.substr(0, p);
            char op = r[p];
            string op_r = r.substr(p + 1, (int)r.size() - p - 1);
            check(op_l); check(op_r);
            g[ptr] = {last[op_l], last[op_r]};
            mem[ptr] = l;
            op_[ptr] = op;
            last[l] = ptr;
            ++ptr;
        }   
        else {
            if (l != r) {
                check(r);
                last[l] = last[r];
            }
        }   
    }   

    for (int i = 0; i < ptr; ++i) {
        for (auto &e : g[i]) e = par[e];
        par[i] = i;
        for (int j = 0; j < i; ++j) {
            if (par[j] == j && op_[i] == op_[j] && g[i].size() && g[i] == g[j]) {
                par[i] = j;
                break;
            }   
        }   
    }   

    if (last.find("res") == last.end()) {
        cout << "0\n";
    }   
    else if (g[last["res"]].empty()) {
        jfs(last["res"], 0);
        ans.push_back("res=" + name(last["res"]));
        ans = form(ans);
        cout << ans.size() << '\n';
        for (auto e : ans) cout << e << '\n';
    }   
    else {
        jfs(last["res"], 1);
        ans = form(ans);
        cout << ans.size() << '\n';
        for (auto e : ans) cout << e << '\n';
    }   
}