#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

const int nax = 5e5 + 5;
vector<pair<int,int>> edges[nax];
bool forbidden[nax];
int subtree[nax];
const ll INF = 1e18L + 5;
ll depth[nax];

const ll base = 512 * 1024;
ll tree[2*base];
vector<int> here;
bool is_here[nax];
int N;

long long Z;

void dfs_subtree(int a, int parent) {
    here.push_back(a);
    is_here[a] = true;
    subtree[a] = 1;
    for(const pair<int,int>& edge : edges[a]) {
        int b = edge.first;
        if(forbidden[b] || b == parent) {
            continue;
        }
        dfs_subtree(b, a);
        subtree[a] += subtree[b];
    }
}

int group[nax];
ll answer[nax];
struct Q {
    int id, v, L, R;
    void read(int _id) {
        id = _id;
        //~ v = id;
        //~ L = 1 + rand() % N;
        //~ R = 1 + rand() % N;
        //~ if(L > R) {
            //~ swap(L, R);
        //~ }
        scanf("%d%d%d", &v, &L, &R);
    }
};
vector<Q> his_queries[nax];

vector<int> leaves;
void dfs_depth(int a, int parent) {
    subtree[a] = 1;
    for(const pair<int,int>& edge : edges[a]) {
        int b = edge.first;
        if(forbidden[b] || b == parent) {
            continue;
        }
        depth[b] = depth[a] + edge.second;
        if(parent == -1) {
            group[b] = b;
        }
        else {
            group[b] = group[a];
        }
        dfs_depth(b, a);
    }
    if((int) edges[a].size() == 1) {
        leaves.push_back(a);
        tree[base+a] = depth[a];
        for(int i = (base + a) / 2; i >= 1; i /= 2) {
            tree[i] = min(tree[2*i], tree[2*i+1]);
        }
    }
}

void dfs_centroid(int a, vector<Q> queries) {
    Z += queries.size();
    //~ int memo_a = a;
    //debug() << imie(a);
    
    
    dfs_subtree(a, -1);
    //~ vector<Q> new_queries;
    //~ for(Q q : queries) {
        //~ if(is_here[q.v]) {
           //~ new_queries.push_back(q);
       //~ }
   //~ }
   //~ swap(queries, new_queries);
   //~ Z += here.size();
    
    for(int x : here) {
        is_here[x] = false;
    }
    here.clear();
    
    int total_size = subtree[a];
    while(true) {
        bool moved = false;
        for(const pair<int,int>& edge : edges[a]) {
            int b = edge.first;
            if(forbidden[b]) {
                continue;
            }
            if(subtree[b] < subtree[a] && subtree[b] >= total_size / 2) {
                a = b;
                moved = true;
                break;
            }
        }
        if(!moved) {
            break;
        }
    }
    // now 'a' is a centroid
    debug() << imie(a);// imie(memo_a);
    
    depth[a] = 0;
    dfs_depth(a, -1);
    
    for(const Q& query : queries) {
        // best depth of leaf in interval [query.L, query.R]
        int low = base + query.L;
        int high = base + query.R;
        ll tmp = min(tree[low], tree[high]);
        while(low < high - 1) {
            if(low % 2 == 0) {
                tmp = min(tmp, tree[low+1]);
            }
            if(high % 2 == 1) {
                tmp = min(tmp, tree[high-1]);
            }
            low /= 2;
            high /= 2;
        }
        answer[query.id] = min(answer[query.id], tmp + depth[query.v]);
    }
    for(int x : leaves) {
        tree[base+x] = INF;
        for(int i = (base + x) / 2; i >= 1; i /= 2) {
            tree[i] = min(tree[2*i], tree[2*i+1]);
        }
    }
    leaves.clear();
    
    
    // split queries
    for(Q q : queries) {
        if(q.v != a) {
            his_queries[group[q.v]].push_back(q);
        }
    }
    
    
    forbidden[a] = true;
    for(pair<int,int> edge : edges[a]) {
        int b = edge.first;
        if(!forbidden[b]) {
            //~ debug() << imie(a) imie(b);
            auto whatever = his_queries[b];
            his_queries[b].clear();
            dfs_centroid(b, whatever);
        }
    }
}

int main() {
    for(int i = 0; i < 2 * base; ++i) {
        tree[i] = INF;
    }
    int n, q;
    scanf("%d%d", &n, &q);
    //~ n = q = 400 * 1000;
    //~ N = n;
    for(int b = 2; b <= n; ++b) {
        int a, c;
        //~ a = 1;
        //~ c = 5000;
        scanf("%d%d", &a, &c);
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }
    vector<Q> queries;
    for(int i = 1; i <= q; ++i) {
        answer[i] = INF;
        Q query;
        query.read(i);
        queries.push_back(query);
    }
    dfs_centroid(1, queries);
    
    for(int i = 1; i <= q; ++i) {
        printf("%lld\n", answer[i]);
    }
    cerr << "Z = " << Z << endl;
}