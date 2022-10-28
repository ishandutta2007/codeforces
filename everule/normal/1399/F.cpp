#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
template<typename T>
struct segment_tree{
    vector<T> segtree;
    int n;
    segment_tree(int n) : n(n){
        segtree.resize(n<<1);
    }
    void update(int pos, T val){
        pos+=n;
        segtree[pos]=max(segtree[pos], val);
        pos>>=1;
        while(pos){
            segtree[pos]=max(segtree[2*pos],segtree[2*pos+1]);
            pos>>=1;
        }
    }
    T query(int x, int y){
        T ansl=0;
        T ansr=0;
        x+=n;
        y+=n+1;
        while(x<y){
            if(x&1){
                ansl=max(ansl, segtree[x++]);
            }
            if(y&1){
                ansr=max(segtree[--y], ansr);
            }
            x>>=1;
            y>>=1;
        }
        return max(ansl, ansr);
    }
};
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> segments(n); 
    vector<int> values;
    for(auto &[l,r] : segments){
        cin>>l>>r;
        values.pb(l);
        values.pb(l+1);
        values.pb(l-1);
        values.pb(r);
        values.pb(r-1);
        values.pb(r+1);
    }
    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end()) - values.begin());
    for(auto &[l,r] : segments){
        l = lower_bound(values.begin(), values.end(), l) - values.begin() + 1;
        r = lower_bound(values.begin(), values.end(), r) - values.begin() + 1;
    }
    vector<pair<int,int>> segments2 = segments;
    sort(segments2.begin(), segments2.end(), [](const pair<int,int> &x, const pair<int,int> &y){
        return x.second < y.second;
    });
    sort(segments.begin(), segments.end(), [&](const pair<int,int> &x, const pair<int,int> &y){
        return x.second - x.first < y.second -  y.first;
    });
    vector<int> segvalue(n+1, 1);
    for(const auto &[l,r] : segments){
        int i=0;
        int idx = -1;
        segment_tree<int> segtree(r + 1);
        for(const auto &[l2, r2] : segments2){
            if(l2 == l && r2 == r){
                idx = i;
                ++i;
                continue;
            }
            if(l<=l2 && r2<=r){
                segtree.update(r2, segtree.query(0, l2 - 1) + segvalue[i]);
            }
            ++i;
        }
        assert(~idx);
        segvalue[idx] = segtree.query(0, r) + 1;
    }
    int i=0;
    segment_tree<int> segtree(values.size() + 1);
    for(const auto &[l,r] : segments2){
        segtree.update(r, segtree.query(0, l - 1) + segvalue[i]);
        ++i;
    }
    cout<<segtree.query(0,values.size())<<"\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}