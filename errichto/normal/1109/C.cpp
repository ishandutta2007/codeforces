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

const int INF = 1e9 + 5;

struct S {
    ll start, speed, min_volume, delta;
    // delta - total change of volume
    // min_volume - lowest point reached in the process
    void merge(const S& a, const S& b) {
        if(a.is_fake()) {
            *this = b;
        }
        else if(b.is_fake()) {
            *this = a;
        }
        else {
            min_volume = min(a.min_volume, a.delta + b.min_volume);
            delta = a.delta + b.delta;
        }
    }
    void init(int t0, int t1, int _speed) {
        speed = _speed;
        delta = (ll) (t1 - t0) * speed;
        min_volume = min(0LL, delta);
        start = t0;
    }
    bool is_fake() const {
        return start == -1;
    }
    double find_exact_point(ll v0) {
        assert(!is_fake());
        assert(speed < 0);
        return start + v0 / (double) -speed;
    }
};

debug& operator << (debug& dd, S s) {
    dd << imie(s.start) imie(s.speed) imie(s.min_volume) imie(s.delta);
    return dd;
}

int main() {
    int q;
    scanf("%d", &q);
    vector<vector<int>> queries;
    vector<int> values;
    for(int i = 0; i < q; ++i) {
        int type;
        scanf("%d", &type);
        if(type == 1) {
            int t, s;
            scanf("%d%d", &t, &s);
            queries.push_back({type, t, s});
            values.push_back(t);
        }
        else if(type == 2) {
            int t;
            scanf("%d", &t);
            queries.push_back({type, t});
            values.push_back(t);
        }
        else if(type == 3) {
            int l, r, v;
            scanf("%d%d%d", &l, &r, &v);
            queries.push_back({type, l, r, v});
            values.push_back(l);
            values.push_back(r);
        }
        else {
            assert(false);
        }
    }
    
    map<int,int> speeds;
    speeds[0] = 0;
    speeds[INF] = 0;
    
    values.push_back(0);
    values.push_back(INF);
    
    debug() << imie(values);
    sort(values.begin(), values.end());
    values.resize( unique(values.begin(), values.end()) - values.begin() );
    debug() << imie(values);
    
    auto get_id = [&](int x) {
        return lower_bound(values.begin(), values.end(), x) - values.begin();
    };
    
    int base = 1;
    while(base < (int) values.size()) {
        base *= 2;
    }
    vector<S> tree(2 * base, S{-1});
    
    auto init_leaf = [&](int id, int t0, int t1, int speed) {
        tree[base+id].init(t0, t1, speed);
        for(int x = (base + id) / 2; x >= 1; x /= 2) {
            tree[x].merge(tree[2*x], tree[2*x+1]);
        }
    };
    
    init_leaf(0, 0, INF, 0);
    
    for(vector<int> query : queries) {
        int type = query[0];
        debug() << imie(type) imie(query);
        for(int i = 1; i < 2 * base; ++i) {
            debug() << imie(i) << tree[i];
        }
        if(type == 1) {
            int t = query[1];
            int s = query[2];
            auto it = speeds.lower_bound(t);
            assert(it != speeds.begin());
            --it;
            int t_previous = it -> first;
            //~ int id_leaf = base + get_id(t_previous);
            init_leaf(get_id(t_previous), t_previous, t, it -> second);
            //~ tree[id_leaf].init(t_previous, t, it -> second);
            ++it;
            init_leaf(get_id(t), t, it -> first, s);
            speeds[t] = s;
        }
        else if(type == 2) {
            int t = query[1];
            auto it = speeds.find(t);
            assert(it -> first == t);
            assert(it != speeds.begin());
            --it;
            int t_previous = it -> first;
            int s_previous = it -> second;
            ++it;
            ++it;
            int t_next = it -> first;
            init_leaf(get_id(t), -1, -1, -1);
            init_leaf(get_id(t_previous), t_previous, t_next, s_previous);
            speeds.erase(t);
        }
        else if(type == 3) {
            int L = query[1];
            ll v0 = query[3];
            if(v0 == 0) {
                printf("%d\n", L);
                continue;
            }
            L = speeds.lower_bound(L)->first;
            if(L == INF) {
                puts("-1");
                continue;
            }
            
            //~ auto it = speeds.lower_bound(L);
            //~ bool special_split = it->first != L;
            //~ if(special_split) {
                //~ int t_next = it -> first;
                //~ assert(it != speeds.begin());
                //~ --it;
                //~ int t_previous = it -> first;
                //~ int s_previous = it -> second;
                //~ init_leaf(get_id(t_previous), t_previous, L, s_previous);
                //~ init_leaf(get_id(L), L, t_next, s_previous);
                //~ speeds[L] = s_previous;
            //~ }
            //~ auto fix = [&]() {
                //~ if(special_split) {
                    //~ L = query[1];
                    //~ it = speeds.find(L);
                    //~ assert(it != speeds.end());
                    //~ assert(it->first == L);
                    //~ assert(it != speeds.begin());
                    //~ --it;
                    //~ int t_previous = it->first;
                    //~ int s_previous = it->second;
                    //~ ++it;
                    //~ ++it;
                    //~ assert(it != speeds.end());
                    //~ init_leaf(get_id(t_previous), t_previous, it->first, s_previous);
                    //~ init_leaf(get_id(L), -1, -1, -1);
                //~ }
            //~ };
            
            L = get_id(L);
            
            L += base;
            vector<int> left;
            left.push_back(L);
            for(; L > 1; L /= 2) {
                if(L % 2 == 0) {
                    left.push_back(L + 1);
                }
            }
            //~ reverse(right.begin(), right.end());
            //~ for(auto x : right) {
                //~ left.push_back(x);
            //~ }
            int found = -1;
            assert(v0 >= 0);
            for(int id : left) {
                if(tree[id].is_fake()) {
                    continue;
                }
                if(tree[id].min_volume <= -v0) {
                    found = id;
                    break;
                }
                else {
                    assert(tree[id].min_volume <= tree[id].delta);
                    debug() << imie(v0) imie(tree[id]);
                    v0 += tree[id].delta;
                    assert(v0 >= 0);
                }
            }
            if(found == -1) {
                puts("-1");
                //~ fix();
                continue;
            }
            int id = found;
            while(id < base) { // not a leaf
                if(!tree[2*id].is_fake() && tree[2*id].min_volume <= -v0) {
                    id = 2 * id;
                }
                else {
                    if(!tree[2*id].is_fake()) {
                        assert(tree[2*id].min_volume <= tree[2*id].delta);
                        v0 += tree[2*id].delta;
                        assert(v0 >= 0);
                    }
                    id = 2 * id + 1;
                }
            }
            assert(!tree[id].is_fake());
            debug() << imie(id) imie(tree[id]) imie(v0);
            double answer = tree[id].find_exact_point(v0);
            if(answer <= query[2] + 1e-12) {
                printf("%.10lf\n", answer);
            }
            else {
                puts("-1");
            }
            //~ fix();
        }
        else {
            assert(false); // invalid type
        }
    }
}