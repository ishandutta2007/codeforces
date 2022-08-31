//Let's join Kaede Takagaki Fan Club !!
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>
#include <complex>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
#define int long long
//#define L __int128
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define a first
#define b second
#define fi first
#define sc second
#define rng(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
#define all(x) x.begin(),x.end()
#define si(x) int(x.size())
 
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif
 
template<class t,class u> bool chmax(t&a,u b){if(a<b){a=b;return true;}else return false;}
template<class t,class u> bool chmin(t&a,u b){if(b<a){a=b;return true;}else return false;}
 
template<class t> using vc=vector<t>;
 
template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.fi<<","<<p.sc<<"}";
}
 
template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}
 
 //https://codeforces.com/blog/entry/62393
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
 
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
	
	size_t operator()(pair<int,int> x)const{
		return operator()(uint64_t(x.first)<<32|x.second);
	}
};
//unordered_set -> dtype, null_type
//unordered_map -> dtype(key), dtype(value)
using namespace __gnu_pbds;
template<class t,class u>
using hash_table=gp_hash_table<t,u,custom_hash>;

template<class T>
void g(T &a){
	cin >> a;
}
template<class T>
void o(const T &a,bool space=false){
	cout << a << (space?' ':'\n');
}
//ios::sync_with_stdio(false);
const ll mod = 998244353;
//const ll mod = 1000000007;
mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
void add(T&a,T b){
	a+=b;
	if(a >= mod) a-=mod;
}
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
#define _sz 1
ll F[_sz],R[_sz];
void make(){
	F[0] = 1;
	for(int i=1;i<_sz;i++) F[i] = F[i-1]*i%mod;
	R[_sz-1] = modpow(F[_sz-1], mod-2);
	for(int i=_sz-2;i>=0;i--) R[i] = R[i+1] * (i+1) % mod;
}
ll C(int a,int b){
	if(b < 0 || a < b) return 0;
	return F[a]*R[b]%mod*R[a-b]%mod;
}

//modified program of https://gist.github.com/brunodccarvalho/fb9f2b47d7f8469d209506b336013473

struct linked_lists {
    int L, N;
    vector<int> next, prev;

    // L: lists are [0...L), N: elements are [0,...N)
    explicit linked_lists(int L = 0, int N = 0) { assign(L, N); }

    int repp(int l) const { return l + N; } // "representative" of list l
    int head(int l) const { return next[repp(l)]; }
    int tail(int l) const { return prev[repp(l)]; }
    bool empty(int l) const { return next[repp(l)] == repp(l); }

    void push_front(int l, int n) { link(repp(l), n, head(l)); }
    void push_back(int l, int n) { link(tail(l), n, repp(l)); }
    void insert_before(int i, int n) { link(prev[i], n, i); }
    void insert_after(int i, int n) { link(i, n, next[i]); }
    void erase(int n) { link(prev[n], next[n]); }
    void pop_front(int l) { link(repp(l), next[head(l)]); }
    void pop_back(int l) { link(prev[tail(l)], repp(l)); }

    void clear() {
        iota(begin(next) + N, end(next), N); // sets next[repp(l)] = repp(l)
        iota(begin(prev) + N, end(prev), N); // sets prev[repp(l)] = repp(l)
    }
    void assign(int L, int N) {
        this->L = L, this->N = N;
        next.resize(N + L), prev.resize(N + L), clear();
    }

  private:
    inline void link(int u, int v) { next[u] = v, prev[v] = u; }
    inline void link(int u, int v, int w) { link(u, v), link(v, w); }
};

// Iterate through elements (call them i) of the list #l in "lists"
#define FOR_EACH_IN_LINKED_LIST(i, l, lists) \
    for (int z##i = l, i = lists.head(z##i); i != lists.repp(z##i); i = lists.next[i])

/**
 * Network simplex for minimum cost circulation with fixed supply/demand at nodes.
 * Supports negative costs, negative cost cycles, self-loops and multiple edges fine.
 *
 * Flow should be large enough to hold sum of supplies and edge flows
 * Cost should be large enough to hold sum of absolute costs * 2V (usually >=64 bits)
 *
 * Complexity: O(V) expected pivot, O(E) worst-case
 *
 * Usage:
 *     network_simplex<int, long> mcc(V);
 *     for (edges...) {
 *         mcc.add(u, v, cap, cost);
 *     }
 *     for (nodes...) {
 *         mcc.set_supply(u, supply);
 *         mcc.set_demand(v, demand);
 *     }
 *     bool feasible = mcc.mincost_circulation();
 *     auto mincost = mcc.circulation_cost();
 *
 * References:
 *   LEMON network_simplex.h
 *   OCW MIT MIT15_082JF10_av16.pdf
 *   OCW MIT MIT15_082JF10_lec16.pdf
 */
template <typename Flow, typename Cost>
struct network_simplex {
    // we number the vertices 0,...,V-1, R is given number V

    explicit network_simplex(int V) : V(V), node(V + 1) {}

    void add(int u, int v, Flow cap, Cost cost) {
        assert(0 <= u && u < V && 0 <= v && v < V);
        edge.push_back({{u, v}, cap, cost}), E++;
    }

    void set_supply(int u, Flow supply) { node[u].supply = supply; }
    void set_demand(int u, Flow demand) { node[u].supply = -demand; }
    auto get_supply(int u) const { return node[u].supply; }

    auto get_potential(int u) const { return node[u].pi; }
    auto get_flow(int e) const { return edge[e].flow; }

    auto reduced_cost(int e) const {
        auto [u, v] = edge[e].node;
        return edge[e].cost + node[u].pi - node[v].pi;
    }

    template <typename CostSum = Cost>
    auto circulation_cost() const {
        CostSum sum = 0;
        for (int e = 0; e < E; e++) {
            sum += edge[e].flow * CostSum(edge[e].cost);
        }
        return sum;
    }

    void verify_spanning_tree() const {
        for (int e = 0; e < E; e++) {
            assert(0 <= edge[e].flow && edge[e].flow <= edge[e].cap);
            assert(edge[e].flow == 0 || reduced_cost(e) <= 0);
            assert(edge[e].flow == edge[e].cap || reduced_cost(e) >= 0);
        }
    }

    bool mincost_circulation() {
        static constexpr bool INFEASIBLE = false, OPTIMAL = true;

        // Check trivialities: positive cap[e] and sum of supplies is 0
        Flow sum_supply = 0;
        for (int u = 0; u < V; u++) {
            sum_supply += node[u].supply;
        }
        if (sum_supply != 0) {
            return INFEASIBLE;
        }
        for (int e = 0; e < E; e++) {
            if (edge[e].cap < 0) {
                return INFEASIBLE;
            }
        }

        // Compute inf_cost as sum of all costs + 1, and reset the flow network
        Cost inf_cost = 1;
        for (int e = 0; e < E; e++) {
            edge[e].flow = 0;
            edge[e].state = STATE_LOWER;
            inf_cost += edge[e].cost<0?-edge[e].cost:edge[e].cost;
        }

        edge.resize(E + V); // make space for V artificial edges
        bfs.resize(V + 1);
        children.assign(V + 1, V + 1);

        // Add V artificial edges with infinite cost and initial supply for feasible flow
        int root = V;
        node[root] = {-1, -1, 0, 0};

        for (int u = 0, e = E; u < V; u++, e++) {
            // spanning tree links
            node[u].parent = root, node[u].pred = e;
            children.push_back(root, u);

            auto supply = node[u].supply;
            if (supply >= 0) {
                node[u].pi = -inf_cost;
                edge[e] = {{u, root}, supply, inf_cost, supply, STATE_TREE};
            } else {
                node[u].pi = inf_cost;
                edge[e] = {{root, u}, -supply, inf_cost, -supply, STATE_TREE};
            }
        }

        // We want to, hopefully, find a pivot edge in O(sqrt(E)). This can be tuned.
        block_size = max((int)(ceil(sqrt(E + V))), min((int)10, V + 1));
        next_arc = 0;

        // Pivot pivot pivot
        int e_in = select_pivot_edge();
        while (e_in != -1) {
            pivot(e_in);
            e_in = select_pivot_edge();
        }

        // If there is >0 flow through an artificial edge, the problem is infeasible.
        for (int e = E; e < E + V; e++) {
            if (edge[e].flow > 0) {
                edge.resize(E);
                return INFEASIBLE;
            }
        }
        edge.resize(E);
        return OPTIMAL;
    }

  private:
    enum ArcState : int8_t { STATE_UPPER = -1, STATE_TREE = 0, STATE_LOWER = 1 };

    struct Node {
        int parent, pred;
        Flow supply;
        Cost pi;
    };
    struct Edge {
        array<int, 2> node; // [0]->[1]
        Flow cap;
        Cost cost;
        Flow flow = 0;
        ArcState state = STATE_LOWER;
    };

    int V, E = 0, next_arc = 0, block_size = 0;
    vector<Node> node;
    vector<Edge> edge;
    linked_lists children;
    vector<int> bfs; // scratchpad for downwards bfs and evert

    int select_pivot_edge() {
        // block search: check block_size edges looping, and pick the lowest reduced cost
        Cost minimum = 0;
        int e_in = -1;
        int count = block_size, seen_edges = E + V;
        for (int &e = next_arc; seen_edges-- > 0; e = e + 1 == E + V ? 0 : e + 1) {
            if (minimum > edge[e].state * reduced_cost(e)) {
                minimum = edge[e].state * reduced_cost(e);
                e_in = e;
            }
            if (--count == 0 && minimum < 0) {
                break;
            } else if (count == 0) {
                count = block_size;
            }
        }
        return e_in;
    }

    void pivot(int e_in) {
        // Find lca of u_in and v_in with two pointers technique
        auto [u_in, v_in] = edge[e_in].node;
        int a = u_in, b = v_in;
        while (a != b) {
            a = node[a].parent == -1 ? v_in : node[a].parent;
            b = node[b].parent == -1 ? u_in : node[b].parent;
        }
        int lca = a;

        // Orient the edge so that we add flow along u_in->v_in
        if (edge[e_in].state == STATE_UPPER) {
            swap(u_in, v_in);
        }

        // Let's find the saturing flow and exiting arc
        enum OutArcSide { SAME_EDGE, U_IN_SIDE, V_IN_SIDE };
        OutArcSide side = SAME_EDGE;
        Flow flow_delta = edge[e_in].cap;
        int u_out = -1;

        // Go up from u_in to lca, break ties by prefering lower vertices
        for (int u = u_in; u != lca && flow_delta > 0; u = node[u].parent) {
            int e = node[u].pred;
            bool edge_down = u == edge[e].node[1];
            Flow to_saturate = edge_down ? edge[e].cap - edge[e].flow : edge[e].flow;

            if (flow_delta > to_saturate) {
                flow_delta = to_saturate;
                u_out = u;
                side = U_IN_SIDE;
            }
        }

        // Go up from v_in to lca, break ties by prefering higher vertices
        for (int u = v_in; u != lca; u = node[u].parent) {
            int e = node[u].pred;
            bool edge_up = u == edge[e].node[0];
            Flow to_saturate = edge_up ? edge[e].cap - edge[e].flow : edge[e].flow;

            if (flow_delta >= to_saturate) {
                flow_delta = to_saturate;
                u_out = u;
                side = V_IN_SIDE;
            }
        }

        // Augment along the cycle if we can push anything
        if (flow_delta > 0) {
            auto delta = edge[e_in].state * flow_delta;
            edge[e_in].flow += delta;

            for (int u = edge[e_in].node[0]; u != lca; u = node[u].parent) {
                int e = node[u].pred;
                edge[e].flow += u == edge[e].node[0] ? -delta : delta;
            }
            for (int u = edge[e_in].node[1]; u != lca; u = node[u].parent) {
                int e = node[u].pred;
                edge[e].flow += u == edge[e].node[0] ? delta : -delta;
            }
        }

        // Return now if we didn't change the spanning tree. The state of e_in flipped.
        if (side == SAME_EDGE) {
            edge[e_in].state = ArcState(-edge[e_in].state);
            return;
        }

        // Basis exchange: Replace out_arc with e_in in the spanning tree
        int out_arc = node[u_out].pred;
        edge[e_in].state = STATE_TREE;
        edge[out_arc].state = edge[out_arc].flow != 0? STATE_UPPER : STATE_LOWER;

        // Put u_in on the same side as u_out
        if (side == V_IN_SIDE) {
            swap(u_in, v_in);
        }

        // Evert: Walk up from u_in to u_out, and fix parent/pred/child pointers downwards
        int i = 0, S = 0;
        for (int u = u_in; u != u_out; u = node[u].parent) {
            bfs[S++] = u;
        }
        for (i = S - 1; i >= 0; i--) {
            int u = bfs[i], p = node[u].parent;
            children.erase(p); // remove p from its children list and add it to u's
            children.push_back(u, p);
            node[p].parent = u;
            node[p].pred = node[u].pred;
        }
        children.erase(u_in); // remove u_in from its children list and add it to v_in's
        children.push_back(v_in, u_in);
        node[u_in].parent = v_in;
        node[u_in].pred = e_in;

        // Fix potentials: Visit the subtree of u_in (pi_delta is not 0).
        Cost current_pi = reduced_cost(e_in);
        Cost pi_delta = u_in == edge[e_in].node[0] ? -current_pi : current_pi;

        bfs[0] = u_in;
        for (i = 0, S = 1; i < S; i++) {
            int u = bfs[i];
            node[u].pi += pi_delta;
            FOR_EACH_IN_LINKED_LIST (v, u, children) { bfs[S++] = v; }
        }
    }
};
/* IMPORTANT NOTES: 
Cost should be large enough to hold sum of absolute costs * 2V (usually >= 64 bits)
potential of node v: mcc.get_potential(v)
flow of edge i: mcc.get_get_flow(i)

USAGE:
	int V = ;
	network_simplex<int, __int128> mcc(V);
	vc<int>sup(V);
	__int128 mincost = 0;
	for (edges...) {
		mcc.add(u, v, high-low, cost);
		mincost += low * cost;
		sup[u] -= low;
		sup[v] += low;
	}
	rep(u, V){
		//u already got supply units of flow : mcc.set_supply(u, supply);
		//v already sent demand units of flow : mcc.set_demand(v, demand);
		mcc.set_supply(u, sup[u]);
	}
	bool feasible = mcc.mincost_circulation();
	mincost += mcc.circulation_cost();
	wr(mincost);
*/
//helper function for __int128
template<typename T>
void wr(T a){
	if(a < 0) {
		cout << "-";
		a = -a;
	}
	if(a == 0) cout << 0 << endl;
	else{
		vc<int>v;
		while(a){ v.pb(a%10); a/=10; }
		reverse(all(v));
		for(auto a:v) cout<<a;
		cout<<endl;
	}
}

void solve(){
	int n, m; cin >> n >> m;
	vc<int>a(n+1); repn(i,n)cin>>a[i];
	int V = 1005;
	network_simplex<int, __int128> mcc(V);
	vc<int>sup(V);
	__int128 mincost = 0;
	repn(i, n){
		mcc.add(0, i, 1, a[i]);
		mcc.add(i, 0, 1, -a[i]);
	}
	rep(i, m){
		int u, v; cin >> u >> v;
		mcc.add(v, u, 1e18 ,0);
	}
	bool feasible = mcc.mincost_circulation();
	mincost += mcc.circulation_cost();
	//wr(mincost);
	vc<__int128>diff;
	repn(i, n){
		diff.pb(a[i]-mcc.get_potential(i));
	}
	SORT(diff);
	int v = diff[n/2];
	mincost *= -1;
	repn(i, n){
		wr(mcc.get_potential(i) + v);
		auto D = a[i] - mcc.get_potential(i) - v;
		if(D < 0) D = -D;
		mincost -= D;
	}
	assert(!mincost);
}
signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	int t; t = 1; //cin >> t;
	while(t--) solve();
}