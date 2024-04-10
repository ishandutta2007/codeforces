#include <stdio.h>
#include <bits/stdc++.h> 

using namespace std;
#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

template<typename T, typename U> struct seg_tree_lazy {
    int S, H;
 
    T zero;
    vector<T> value;
 
    U noop;
    vector<bool> dirty;
    vector<U> prop;
 
    seg_tree_lazy<T, U>(int _S, T _zero = T(), U _noop = U()) {
        zero = _zero, noop = _noop;
        for (S = 1, H = 1; S < _S; ) S *= 2, H++;
 
        value.resize(2*S, zero);
        dirty.resize(2*S, false);
        prop.resize(2*S, noop);
    }
 
    void set_leaves(vector<T> &leaves) {
        copy(leaves.begin(), leaves.end(), value.begin() + S);
 
        for (int i = S - 1; i > 0; i--)
            value[i] = value[2 * i] + value[2 * i + 1];
    }
 
    void apply(int i, U &update) {
        value[i] = update(value[i]);
        if(i < S) {
            prop[i] = prop[i] + update;
            dirty[i] = true;
        }
    }
 
    void rebuild(int i) {
        for (int l = i/2; l; l /= 2) {
            T combined = value[2*l] + value[2*l+1];
            value[l] = prop[l](combined);
        }
    }
 
    void propagate(int i) {
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
 
    void upd(int i, int j, U update) {
        i += S, j += S;
        propagate(i), propagate(j);
 
        for (int l = i, r = j; l <= r; l /= 2, r /= 2) {
            if((l&1) == 1) apply(l++, update);
            if((r&1) == 0) apply(r--, update);
        }
 
        rebuild(i), rebuild(j);
    }
 
    T query(int i, int j){
        i += S, j += S;
        propagate(i), propagate(j);
 
        T res_left = zero, res_right = zero;
        for(; i <= j; i /= 2, j /= 2){
            if((i&1) == 1) res_left = res_left + value[i++];
            if((j&1) == 0) res_right = value[j--] + res_right;
        }
        return res_left + res_right;
    }
};

struct node {
    int value;
    int where;
    
    node operator+(const node &n) {
        if (value > n.value) return *this;
        else return n;
    }    
};

struct update {
    int value;

    node operator()(const node &n) {
        return { n.value + value, n.where };
    }

    update operator+(const update &u) {
        return {value + u.value}; 
    }
};


struct worker {
    int l, v, r, id;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vector<worker> workers(N);
    REP(i,N) {
        cin >> workers[i].l >> workers[i].v >> workers[i].r;
        workers[i].id = i;
    }

    vector<worker> l_workers = workers;

    sort(workers.begin(), workers.end(), [](const worker &a, const worker &b){
        return a.v < b.v;
    });
    sort(l_workers.begin(), l_workers.end(), [](const worker &a, const worker &b){
        return a.l < b.l;
    });

    seg_tree_lazy<node, update> st(310000, {-1,-1}, {0});
    vector<node> leaves(310000, {0, 0});
    REP(i,310000) leaves[i].where = i;
    st.set_leaves(leaves);

    int ans = 0;
    int ansL = 0;
    int ansR = 0;
    for (int i = 300000; i >= 1; i--) {
        while (!workers.empty() && workers.back().v == i) {
            st.upd(workers.back().v, workers.back().r, {1});
            workers.pop_back();
        }
        while (!l_workers.empty() && l_workers.back().l == i+1) {
            st.upd(l_workers.back().v, l_workers.back().r, {-1});
            l_workers.pop_back();
        }

        node qry = st.query(1, 305000);
        if (qry.value > ans) {
            ans = qry.value;
            ansL = i;
            ansR = qry.where;
        }
    }

    //cout << ansL << " " << ansR << endl;
    cout << ans << endl;
    REP(i,N) {
        if (workers[i].l <= ansL && ansL <= workers[i].v && workers[i].v <= ansR && ansR <= workers[i].r) {
            cout << workers[i].id+1 << " ";
        }
    }
    cout << endl;
}