#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
 
    T zero;
    std::vector<T> value;
 
    U noop;
    std::vector<bool> dirty;
    std::vector<U> prop;
 
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U());
    void set_leaves(std::vector<T> &leaves);
    void apply(int i, U &update);
    void rebuild(int i);
    void propagate(int i);
    void upd(int i, int j, U update);
    T query(int i, int j);
};

using namespace std;


void re(int& x);


template<class T, class... Ts> void re(T& t, Ts&... ts);


typedef pair<int, int> pii;

#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


struct node {
    int a;

    node operator+(node ot) {
        ot.a = max(a, ot.a);
        return ot;
    }
};

node zero = {0};

struct update {
    int ch;

    node operator()(node n) {
        n.a = max(n.a, ch);
        return n;
    }

    update operator+(update ot) {
        ot.ch = max(ot.ch, ch);
        return ot;
    }
};

update noop = {0};


int n, m, k, q;

vector< pair<int, int> > rooks;
vector< pair< pair<pii, pii>, int > > queries;
vector< int > ans;

vector< int > rooks_per_row[110000];
int curr_rook_in_row[110000];

void go() {
    memset(curr_rook_in_row, 0, sizeof(curr_rook_in_row));
    REP(i,m) rooks_per_row[i].clear();

    sort(rooks.begin(), rooks.end());
    sort(queries.begin(), queries.end());

    REP(i,k) rooks_per_row[rooks[i].second].push_back(rooks[i].first);

    seg_tree_lazy<node, update> st(m, zero, noop);
    vector<node> leaves;
    REP(i,m) {
        node nd = {n+1};
        if (!rooks_per_row[i].empty()) nd.a = rooks_per_row[i][0];
        curr_rook_in_row[i] = 0;
        leaves.push_back(nd);
    }
    st.set_leaves(leaves);

    int curr_n = 0;
    int first_rook = 0;

    REP(i,q) {
        while (first_rook < k && rooks[first_rook].first < queries[i].first.first.first) {
            int this_y = rooks[first_rook].second;
            curr_rook_in_row[this_y]++;

            int nxt = n+1;
            if (rooks_per_row[this_y].size() > curr_rook_in_row[this_y]) {
                nxt = rooks_per_row[this_y][curr_rook_in_row[this_y]];
            }
            st.upd(this_y, this_y, {nxt});
            first_rook++;
        }

        int query_idx = queries[i].second;

        int mx = st.query(queries[i].first.second.first, queries[i].first.second.second).a;
        ans[query_idx] |= (mx <= queries[i].first.first.second);
    }
}

void solve()
{
    re(n,m,k,q);

    rooks.resize(k);
    queries.resize(q);
    ans.resize(q);

    REP(i,k) {
        scanf("%d %d", &rooks[i].first, &rooks[i].second);
        rooks[i].first--; rooks[i].second--;
    }

    REP(i,q) {
        int a,b,c,d;
        re(a,b,c,d);
        a--; b--; c--; d--;
        queries[i] = { {{a,c}, {b,d}}, i};
    }

    go();

    std::swap(n,m);
    REP(i,k) std::swap(rooks[i].first, rooks[i].second);
    REP(i,q) std::swap(queries[i].first.first, queries[i].first.second);

    go();

    REP(i,q) {
        printf("%s\n", ans[i] ? "YES" : "NO");
    }
}


int main() {


    solve();
}


template<typename T, typename U>
seg_tree_lazy<T, U>::seg_tree_lazy(int _S, T _zero, U _noop) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }

 template<typename T, typename U>
    void seg_tree_lazy<T, U>::set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);
 
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }
 
  template<typename T, typename U>
    void seg_tree_lazy<T, U>::apply(int i, U &update) {
        value[i] = update(value[i]);
        if(i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;
        }
    }
 
  template<typename T, typename U>
    void seg_tree_lazy<T, U>::rebuild(int i) {
        for (int l = i/2; l; l /= 2) {
            T combined = value[2*l] + value[2*l+1];
            value[l] = prop[l](combined);
        }
    }
 
  template<typename T, typename U>
    void seg_tree_lazy<T, U>::propagate(int i) {
        for (int h = H; h > 0; h--) {
            int l = i >> h;
 
            if (dirty[l]) {
                apply(2*l, prop[l]);
                apply(2*l+1, prop[l]);
 
                prop[l] = noop;
                dirty[l] = false;
            }
        }
    }
 
  template<typename T, typename U>
    void seg_tree_lazy<T, U>::upd(int i, int j, U update) {
        i += S, j += S;
        propagate(i), propagate(j);
 
        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if((l&1) == 1) apply(l++, update);
            if((r&1) == 0) apply(r--, update);
        }
 
        rebuild(i), rebuild(j);
    }
 
  template<typename T, typename U>
    T seg_tree_lazy<T, U>::query(int i, int j){
        i += S, j += S;
        propagate(i), propagate(j);
 
        T res_left = zero, res_right = zero;
        for(; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }


void re(int& x) { scanf("%d", &x); }


template<class T, class... Ts> void re(T& t, Ts&... ts) { 
    re(t); re(ts...); 
}