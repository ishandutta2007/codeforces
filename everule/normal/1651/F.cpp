#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
template<typename T>
ostream& operator+(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out<<x<<" ";
    }
    out<<"\n";
    return out;
}
template<typename T>
ostream& operator*(ostream& out, const vector<T> &vec){
    for(const auto &x : vec){
        out+x;
    }
    return out;
}
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
template<typename T>
struct node{
    T val;
    node<T>* left = NULL;
    node<T>* right = NULL;
};
template<typename T>
struct persistent_segment_tree{
    function<T(const T&,const T&)> join;
    int n;
    T base;
    vector<node<T>*> roots;
    persistent_segment_tree(int _n, function<T(const T&,const T&)> join, T base) : n(_n), join(join), base(base){
        n = 32 - __builtin_clz(n-1);
        n = (1<<n);
        roots.push_back(build(0,n));
    }
    persistent_segment_tree(vector<T> v, function<T(const T&,const T&)> join, T base) : n(v.size()), join(join), base(base){
        n = 32 - __builtin_clz(n-1);
        n = (1<<n);
        roots.push_back(build(0,n,v));
    }
    node<T>* build(int l,int r){
        node<T> *root = new node<T>;
        if(l+1==r){
            root->val = base;
            return root;
        } 
        root->left = build(l,(l+r)/2);
        root->right = build((l+r)/2, r);
        root->val = join(root->left->val, root->right->val);
        return root;
    }
    node<T>* build(int l,int r, vector<T> &v){
        node<T> *root = new node<T>;
        if(l+1==r){
            root->val = l < v.size() ? v[l] : base;
            return root;
        } 
        root->left = build(l,(l+r)/2, v);
        root->right = build((l+r)/2, r, v);
        root->val = join(root->left->val, root->right->val);
        return root;
    }
    void set(int pos, T val){
        node<T>* currnew = new node<T>;
        node<T>* currold = roots.back();
        set(0, n, currnew, currold, pos, val);
        roots.push_back(currnew);
    }
    void set(int l,int r, node<T>* currnew, node<T>* currold, int pos, T val){
        if(l+1==r){
            currnew->val = val;
            return;
        }
        if(pos<(l+r)/2){
            currnew->right = currold->right;
            currnew->left = new node<T>;
            set(l,(l+r)/2, currnew->left, currold->left, pos, val);
            currnew->val = join(currnew->left->val, currnew->right->val);
        }
        else{
            currnew->left = currold->left;
            currnew->right = new node<T>;
            set((l+r)/2, r, currnew->right, currold->right, pos, val);
            currnew->val = join(currnew->left->val, currnew->right->val);
        }
    }
    void increment(int pos, T val){
        node<T>* currnew = new node<T>;
        node<T>* currold = roots.back();
        increment(0,n, currnew, currold, pos, val);
        roots.push_back(currnew);
    }
    void increment(int l,int r, node<T>* currnew, node<T>* currold, int pos, T val){
        if(l+1==r){
            currnew->val = join(currold->val, val);
            return;
        }
        if(pos<(l+r)/2){
            currnew->right = currold->right;
            currnew->left = new node<T>;
            increment(l,(l+r)/2, currnew->left, currold->left, pos, val);
            currnew->val = join(currnew->left->val, currnew->right->val);
        }
        else{
            currnew->left = currold->left;
            currnew->right = new node<T>;
            increment((l+r)/2, r, currnew->right, currold->right, pos, val);
            currnew->val = join(currnew->left->val, currnew->right->val);
        }
    }
    T query(int l,int r,int time){
        if(l > r) return base;
        return query(0,n,l,r+1,roots[time]);
    }
    T query(int l,int r,int ql, int qr, node<T>* curr){
        if(l>=qr || r<=ql){
            return base;
        }
        if(l>=ql && r<=qr){
            return curr->val;
        }
        return join(query(l,(l+r)/2, ql, qr, curr->left), query((l+r)/2, r, ql, qr, curr->right));
    }
    pair<int, T> search(function<bool(T)> cmp, int t, int maxr){
        node<T>* curr = roots[t];
        int r = n;
        T currv = base;
        int ans = 0;
        while(curr->left != NULL){
            r >>= 1;
            if(ans + r <= maxr && !cmp(join(currv, curr->left->val))){
                currv = join(currv, curr->left->val);
                curr = curr->right;
                ans += r;
            }
            else{
                curr = curr->left;
            }
        }
        currv = join(currv, curr->val);
        if(!cmp(currv)) ans++;
        return {ans, currv};
    }
};
struct line{
    ll a, b;
    line(ll a,ll b) : a(a), b(b) {}
    line() : a(0), b(0) {}
    line operator+(line o){
        return line(a + o.a, b + o.b);
    }
    line operator-(line o){
        return line(a - o.a, b - o.b);
    }
    ll operator()(ll x){
        return a * x + b;
    }
};
const int INF = 1e9 + 7;
void solve(){
    int n;
    cin>>n;
    vector<ll> c(n), rg(n);
    for(int i=0;i<n;i++) cin>>c[i]>>rg[i];
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int x,int y){
        return c[x] * rg[y] < c[y] * rg[x];
    });
    vector<line> lines(n);
    for(int i=0;i<n;i++) lines[i] = line(rg[i], 0);
    persistent_segment_tree<line> pst(lines, [&](line x, line y){
        return x + y;
    }, line());
    for(int i=0;i<n;i++){
        pst.set(ord[i], line(0, c[ord[i]]));
    }
    auto getpstroot = [&](int t){
        return lower_bound(ord.begin(), ord.end(), t, [&](int x,int y){
            return c[x] <= y * rg[x];
        }) - ord.begin();
    };
    set<array<int, 3>> ranges;
    ranges.insert({0, n-1, -INF});
    int q;
    cin>>q;
    ll ans = 0;
    vector<array<int, 2>> spl(n, {0, 0});
    //cout<<pst.query(0, 3, 3).a<<" "<<pst.query(0, 3, 3).b<<"\n";
    //cout<<pst.query(0, 4, 3).a<<" "<<pst.query(0, 4, 3).b<<"\n";
    //cout<<pst.query(4, 4, 3).a<<" "<<pst.query(4, 4, 3).b<<"\n";
    for(int i=0;i<q;i++){
        int t;
        ll h;
        cin>>t>>h;
        //cout<<"Monster "<<i + 1<<"\n";
        while(h > 0){
            if(ranges.size() == 0) break;
            auto [l,r,rt] = *ranges.begin();
            //cout<<l<<" "<<r<<" "<<rt<<"\n";
            ranges.erase(ranges.begin());
            int te = t - rt;
            if(rt == INF){
                te = t - spl[l][1];
                int cmana = min(c[l], spl[l][0] + rg[l] * te);
                h -= cmana;
                //cout<<l<<" "<<spl[l][0]<<" "<<spl[l][1]<<" "<<h<<" special attack\n";
                if(h <= 0){
                    if(l > 0) ranges.insert({0, l-1, t});
                    ranges.insert({l, l, INF});
                    spl[l] = {int(-h), t};
                    //cout<<l<<" "<<spl[l][0]<<" "<<spl[l][1]<<" update spl\n";
                }
                continue;
            }
            int rtt = getpstroot(te);
            line ext = pst.query(0, l-1, rtt);
            auto [f,ln] = pst.search([&](line v){
                return (v - ext)(te) >= h;
            }, rtt, r);
            //cout<<ln.a<<" "<<ln.b<<" "<<ext.a<<" "<<ext.b<<" line of answer\n";
            h -= (ln - ext)(te);
            //cout<<rtt<<" "<<h<<" "<<te<<" "<<f<<" pst node / health / time elapsed / reach\n";
            if(h <= 0){
                if(f > 0) ranges.insert({0, f-1, t});
                if(f + 1 <= r) ranges.insert({f+1, r, rt});
                ranges.insert({f, f, INF});
                spl[f] = {int(-h), t};
                //cout<<f<<" "<<int(-h)<<" "<<t<<"\n"; 
                //cout<<f<<" "<<spl[f][0]<<" "<<spl[f][1]<<" update spl\n";
            }
        }
        if(ranges.size() == 0) ranges.insert({0, n-1, t}), ans += h;
        //if(h > 0) cout<<"Lost "<<h<<"\n";
        //cout<<"Ranges\n";
        //for(auto &[a,b,c] : ranges) cout<<a<<" "<<b<<" "<<c<<"\n";
        //cout<<"\n"; 
    }
    cout<<ans<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}