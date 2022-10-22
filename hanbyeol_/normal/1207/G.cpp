#include<bits/stdc++.h>
using namespace std;

struct Node
{
    // used in aho-corasik
    Node* nxt[26];
    Node* cache[26];
    Node* fail;

    // used in ETT
    vector<Node*> failchild;
    int L, R;
    Node() {
        memset(nxt, 0, sizeof nxt);
        memset(cache, 0, sizeof cache);
        fail = nullptr; L = 0, R = 0;
    }
};

struct Seg
{
    Seg* L; Seg* R; int v;
    Seg() : L(nullptr), R(nullptr), v(0) {}
};

Seg* addv(Seg* a, int s, int e, int i)
{
    Seg* r = new Seg();
    if(a){ r->L = a->L, r->R = a->R, r->v = a->v;}
    r->v++;
    if(s == i && i == e) return r;
    int m = (s+e)/2;
    if(i <= m) r->L = addv(r->L, s, m, i);
    else r->R = addv(r->R, m+1, e, i);
    return r;
}

int getv(Seg* a, int s, int e, int l, int r)
{
    if(!a) return 0;
    if(e<l || r<s) return 0;
    if(l<=s&&e<=r) return a->v;
    int m = (s+e)/2;
    return getv(a->L, s, m, l, r) + getv(a->R, m+1, e, l, r);
}

struct State
{
    Node* node;
    Seg* seg;
};

Node* get_nxt(Node* a, char c, Node* r)
{
    if(!a) return r;
    if(a->cache[c-'a']) return a->cache[c-'a'];

    return a->cache[c-'a'] = a->nxt[c-'a'] ? a->nxt[c-'a'] : get_nxt(a->fail, c, r);
}

State nxt(State a, char c, Node* r)
{
    State ret; ret.node = get_nxt(a.node, c, r);
    if(ret.node != r) ret.seg = addv(a.seg, 0, r->R, ret.node->L);
    else ret.seg = a.seg;
    return ret;
}



/*void dbg(string s, Node* r)
{
    cout << "===" << endl;
    cout << '"' << s << '"' << (void*)r << endl;
    for(int i=0; i<26; ++i) if(r->nxt[i]) cout << (char)('a'+i) << " " << (void*)r->nxt[i] << endl;
    cout << "FAIL " << r->fail << endl;
    cout << r->L << " " << r->R << endl;
    cout << "===" << endl;
    for(int i=0; i<26; ++i) if(r->nxt[i]) dbg(s+(char)('a'+i), r->nxt[i]);
}*/

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<pair<int, char>> V; V.emplace_back(0, 0);
    for(int i=1; i<=N; ++i)
    {
        int t; cin >> t;
        if(t == 1)
        {
            char c; cin >> c; V.emplace_back(0, c);
        }
        else
        {
            int a; char c; cin >> a >> c; V.emplace_back(a, c);
        }
    }
    int T; cin >> T;
    vector<pair<int, string>> Qu(T);
    for(auto& [a, b]: Qu) cin >> a >> b;
    Node* r = new Node();
    vector<Node*> nodes;
    for(const auto& [a, b]: Qu)
    {
        Node* cur = r;
        for(auto c: b)
        {
            if(!(cur->nxt[c-'a'])) cur->nxt[c-'a'] = new Node();
            cur = cur->nxt[c-'a'];
        }
        nodes.push_back(cur);
    }
    queue<Node*> Q; Q.emplace(r);
    while(!Q.empty())
    {
        Node* n = Q.front(); Q.pop();
        for(int i=0; i<26; ++i) if(n->nxt[i])
        {
            Node* nn = n->nxt[i]; Q.emplace(nn);
            Node* f = n->fail;
            while(f)
            {
                if(f->nxt[i])
                {
                    nn->fail = f->nxt[i];
                    f->nxt[i]->failchild.push_back(nn);
                    break;
                }
                f = f->fail;
            }
            if(!f)
            {
                nn->fail = r;
                r->failchild.push_back(nn);
            }
        }
    }

    int tp = 0;
    function<void(Node*)> dfs = [&](Node* n)
    {
        n->L = tp++;
        for(Node* x: n->failchild) dfs(x);
        n->R = tp;
    };
    dfs(r);
    // dbg("", r);
    vector<State> ST(N+1); ST[0].node = r; ST[0].seg = nullptr;
    for(int i=1; i<=N; ++i) ST[i] = nxt(ST[V[i].first], V[i].second, r);
    for(int i=0; i<T; ++i)
    {
        State s = ST[Qu[i].first];
        Node* n = nodes[i];
        cout << getv(s.seg, 0, r->R, n->L, n->R-1) << '\n';
    }
    return 0;
}