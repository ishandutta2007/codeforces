//Author: Heltion
//Date: 08-07-2019
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
template<typename T>void no(T s){cout << s; exit(0);}
void no(){cout << "NO"; exit(0);}
constexpr int maxn = 240000;
string s[maxn];
const int K = 26;

struct Vertex {
    int next[K];
    int leaf = false;
    int p = -1;
    char pch;
    int link = -1;
    int go[K];
    int ok = false;
    Vertex(int p=-1, char ch='$') : p(p), pch(ch) {
        fill(begin(next), end(next), -1);
        fill(begin(go), end(go), -1);
    }
};

vector<Vertex> t(1);

void add_string(string const& s) {
    int v = 0;
    for (char ch : s) {
        int c = ch - 'a';
        if (t[v].next[c] == -1) {
            t[v].next[c] = t.size();
            t.emplace_back(v, ch);
        }
        v = t[v].next[c];
    }
    t[v].leaf += 1;
}

int go(int v, char ch);

int get_link(int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go(get_link(t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go(int v, char ch) {
    int c = ch - 'a';
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v == 0 ? 0 : go(get_link(v), ch);
    }
    return t[v].go[c];
}
int query(int p){
	if(p == 0) return 0;
	if(t[p].ok == true) return t[p].leaf;
	t[p].leaf += query(get_link(p));
	t[p].ok = true;
	return t[p].leaf;
}
LL pre[maxn], suf[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cout << fixed << setprecision(20);
	string tt;
	cin >> tt;
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1){
		cin >> s[i];
		add_string(s[i]);
	}
	int p = 0;
	for(int i = 0; i <(int)tt.size(); i += 1){
		p = go(p, tt[i]);
		pre[i] = query(p);
	}
	t.clear();
	t.push_back(Vertex());
	for(int i = 0; i < n; i += 1){
		reverse(s[i].begin(), s[i].end());
		add_string(s[i]);
	}
	p = 0;
	for(int i = (int)tt.size() - 1; ~i; i -= 1){
		p = go(p, tt[i]);
		suf[i] = query(p);
	}
	LL ans = 0;
	for(int i = 0; i < (int)tt.size(); i += 1){
		ans += pre[i] * suf[i + 1];
	}
	cout << ans;
	return 0;
}