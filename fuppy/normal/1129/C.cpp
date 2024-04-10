//*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/
 
#include <bits/stdc++.h>
 
// #include <atcoder/all>
 
using namespace std;
// using namespace atcoder;
 
#define DEBUG(x) cerr<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cerr<<#v<<":";for(int i=0;i<v.size();i++) cerr<<" "<<v[i]; cerr<<endl;
#define DEBUG_MAT(v) cerr<<#v<<endl;for(int i=0;i<v.size();i++){for(int j=0;j<v[i].size();j++) {cerr<<v[i][j]<<" ";}cerr<<endl;}
typedef long long ll;
// #define int ll
 
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
template<class S, class T> pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first + t.first, s.second + t.second); }
template<class S, class T> pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template<class S, class T> ostream& operator<<(ostream& os, pair<S, T> p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
#define X first
#define Y second
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define rrep1(i,n) for(int i=(int)(n);i>0;i--)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(),c.end()
void YES(bool t=true) {cout<<(t?"YES":"NO")<<endl;}
void Yes(bool t=true) {cout<<(t?"Yes":"No")<<endl;}
void yes(bool t=true) {cout<<(t?"yes":"no")<<endl;}
void NO(bool t=true) {cout<<(t?"NO":"YES")<<endl;}
void No(bool t=true) {cout<<(t?"No":"Yes")<<endl;}
void no(bool t=true) {cout<<(t?"no":"yes")<<endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
int popcount(ll t) { return __builtin_popcountll(t); }
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
// vi dx2 = { 1,1,0,-1,-1,-1,0,1 }, dy2 = { 0,1,1,1,0,-1,-1,-1 };
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'



template<int char_size>
struct TrieNode {
    // 

    // 
    int next_idx[char_size]; // Trie-1
    vector<int> exist_char; // 
    vector<int> state_idx; // 
    int sub_num = 0; // != 

    TrieNode() {
        for (int i = 0; i < char_size; i++) next_idx[i] = -1;
    }
};

template<int char_size, int initial_char>
struct Trie {
    using Node = TrieNode<char_size>;

    vector<Node> nodes;
    int str_num=0; // != 
    vector<string> strs; // ididunordered_map
    Trie() {
        nodes.push_back(Node());
    }

    void add(string& s, int str_idx, int node_idx, int id) {
        // s
        if (str_idx == s.size()) {
            nodes[node_idx].state_idx.push_back(id);
            nodes[node_idx].sub_num++;
            return;
        }
        // s
        if (nodes[node_idx].next_idx[s[str_idx] - initial_char] == -1) {
            nodes[node_idx].next_idx[s[str_idx] - initial_char] = nodes.size();
            nodes[node_idx].exist_char.push_back(s[str_idx] - initial_char);
            nodes.push_back(Node());
        }
        add(s, str_idx+1, nodes[node_idx].next_idx[s[str_idx] - initial_char], id);
        nodes[node_idx].sub_num++;
    }

    void add(string& s, int id=-1) {
        if (id == -1) id = str_num;
        add(s, 0, 0, id);
        str_num++;
        strs.push_back(s);
    }

    // MLE
    int sub(string& s, int str_idx, int node_idx) {
        // s
        if (str_idx == s.size()) {
            assert(nodes[node_idx].state_idx.size() > 0);
            // id
            int id = nodes[node_idx].state_idx.back();
            nodes[node_idx].state_idx.pop_back();
            nodes[node_idx].sub_num--;
            return id;
        }

        int next_node_idx = nodes[node_idx].next_idx[s[str_idx] - initial_char];
        int id = sub(s, str_idx+1, next_node_idx);
        nodes[node_idx].sub_num--;
        assert(nodes[node_idx].sub_num >= 0);

        // s or 
        if (nodes[next_node_idx].sub_num == 0 and (nodes[node_idx].sub_num > 0 or node_idx == 0)) {
            nodes[node_idx].next_idx[s[str_idx] - initial_char] = -1;
            rep (i, nodes[node_idx].exist_char.size()) {
                if (nodes[node_idx].exist_char[i] == s[str_idx] - initial_char) {
                    nodes[node_idx].exist_char.erase(nodes[node_idx].exist_char.begin() + i);
                    break;
                }
            }
        }
        return id;
    }
    
    // id
    int sub(string& s) {
        int id = sub(s, 0, 0);
        str_num--;
        strs[id].clear();
        strs[id].shrink_to_fit();
        return id;
    }

    void query(string& s, int str_idx, int node_idx) {
        for (int id: nodes[node_idx].state_idx) {
            // s[0, str_idx)
        }
        if (str_idx == s.size()) {
            // s
            return;
        }

        if (nodes[node_idx].next_idx[s[str_idx] - initial_char] == -1) {
            // sprefix
            return;
        }
        return query(s, str_idx + 1, nodes[node_idx].next_idx[s[str_idx] - initial_char]);
    }

    // sprefix
    void query(string s) {
        query(s, 0, 0);
    }
    
    void dfs(int node_idx, int depth) {
        // 
        // 

        for (int c: nodes[node_idx].exist_char) {
            assert(nodes[node_idx].next_idx[c] != -1);
            dfs(nodes[node_idx].next_idx[c], depth + 1);
        }
    }

    // dfs
    void dfs() {
        dfs(0, 0);
    }

    string xor_min(string& s, int str_idx, int node_idx, string& t) {
        if (str_idx == s.size()) {
            // s
            return t;
        }

        if (nodes[node_idx].next_idx[s[str_idx] - initial_char] != -1) {
            t += s[str_idx];
            return xor_min(s, str_idx + 1, nodes[node_idx].next_idx[s[str_idx] - initial_char], t);
        }
        else {
            char c = '0' + ('1' - s[str_idx]);
            t += c;
            return xor_min(s, str_idx + 1, nodes[node_idx].next_idx[c - initial_char], t);
        }
    }

    // sxor
    string xor_min(string& s) {
        assert(initial_char == '0' and char_size == 2);
        assert(str_num > 0);
        string res;
        return xor_min(s, 0, 0, res);
    }

    // != 
    int size() {
        return nodes.size();
    }

    // node_idxc
    int move(int node_idx, int c) {
        return this->nodes[node_idx].next_idx[c - initial_char];
    }
};

struct dice {
  mt19937 mt;
  dice() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}
  // [0, x)
  ll operator()(ll x) { return this->operator()(0, x); }
  // [x, y)
  ll operator()(ll x, ll y) {
    uniform_int_distribution<ll> dist(x, y - 1);
    return dist(mt);
  }
  vl operator()(int n, ll x, ll y) {
    vl res(n);
    for (int i = 0; i < n; i++) res[i] = this->operator()(x, y);
    return res;
  }
} rnd;


using ull = unsigned long long;
const ull MASK30 = (1ULL << 30) - 1;
const ull MASK31 = (1ULL << 31) - 1;
const ull M = (1ULL << 61) - 1;
const ull B = rnd(129, M);
const ull POSITIVIZER = M * ((1ULL << 3) - 1);

class RollingHash {
public:
  
  vector<ull> hash;
  vector<ull> Bpower;

  RollingHash(string s) {
    int n = s.size();
    hash.resize(n + 1); Bpower.resize(n + 1);
    Bpower[0] = 1;
    hash[0] = 0;
    
    for (int i = 0; i < n; i++) {
      hash[i + 1] = _calc_mod(_mul(hash[i], B) + (ull)s[i]);
      Bpower[i + 1] = _calc_mod(_mul(Bpower[i], B));
    }
  }

  //S[l, r)
  ull part(int l, int r) {
    return _calc_mod(hash[r] + POSITIVIZER - _mul(hash[l], Bpower[r - l]));
  }

  ull _mul(ull a, ull b) {
    ull au = a >> 31;
    ull ad = a & MASK31;
    ull bu = b >> 31;
    ull bd = b & MASK31;
    ull mid = ad * bu + au * bd;
    ull midu = mid >> 30;
    ull midd = mid & MASK30;
    return au * bu * 2 + midu + (midd << 31) + ad * bd;
  }

  ull _calc_mod(ull val) {
    val = (val & M) + (val >> 61);
    if (val >= M) val -= M;
    return val;
  }
};


unordered_set<ull> used[3011];
ll dp[3011][40];

signed main() {
    int m;
    cin >> m;
    string s;
    rep (i, m) {
        char c;
        cin >> c;
        s += c;
    }
    RollingHash rh(s);

    Trie<2, '0'> trie;
    rep1 (keta, 4) {
        rep (i, 1 << keta) {
            string temp;
            rep (j, keta) {
                if (i & (1 << j)) temp += '1';
                else temp += '0';
            }
            if (temp == "0011" or temp == "0101" or temp == "1110" or temp == "1111") {
                continue;
            }
            trie.add(temp);
        }
    }

    vii possible_state(m + 1, vi(1, 0));
    rep (i, m) {
        int j = 0;
        rep (k, 3) {
            if (i + k >= m) break;
            j = trie.move(j, s[i + k]);
            possible_state[i + k + 1].push_back(j);
        }
    }

    vl ans(m);
    rep (l, m) {
        for (int i = 0; l + i <= m; i++) {
            rep (j, trie.size()) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;

        for (int i = 0; l + i < m; i++) {
            int r = l + i + 1;
            for (int j: possible_state[l + i]) {
                if (dp[i][j] == 0) continue;

                int nj = trie.move(j, s[l + i]);
                if (nj == -1) continue;
                (dp[i + 1][nj] += dp[i][j]) %= MOD;
                (dp[i + 1][0] += dp[i][j]) %= MOD;
            }

            ull hash = rh.part(l, r);
            if (used[r - l].count(hash) == 0) {
                used[r - l].insert(hash);
                ans[r - 1] += dp[i + 1][0];
            }
        }
        // DEBUG_VEC(ans);
    }
    vl sum(m + 1);
    rep (i, m) {
        sum[i + 1] = (sum[i] + ans[i]) % MOD;
        cout << sum[i + 1] << endl;
    }

}