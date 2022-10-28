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
template<typename T, typename U>
struct lazy_segment_tree{
    int n;
    int H;
    T base;
    vector<T> segtree;
    vector<U> lazytree;
    vector<bool> isempty;
    function<T(const T&, const T&)> join;
    function<T(int, const U&, const T&)> assign;
    function<U(const U&,const U&)> lazyassign;

    lazy_segment_tree(vector<T> &seq, 
    function<T(const T&, const T&)> join, 
    function<T(int, const U&, const T&)> assign,
    function<U(const U&,const U&)> lazyassign,
    T base) : join(join), assign(assign), lazyassign(lazyassign), base(base){
        n = seq.size();
        H = 32 - __builtin_clz(n);
        segtree.resize(2*n);
        lazytree.resize(n);
        isempty.resize(n,1);
        for(int i=0;i<n;i++){
            segtree[n+i]=seq[i];
        }
        for(int i=n-1;i>=1;i--){
            segtree[i]=join(segtree[(i<<1)], segtree[(i<<1)|1]);
        }
    }
    void calc(int pos, int h){
        segtree[pos]=join(segtree[(pos<<1)],segtree[(pos<<1)|1]);
        if(!isempty[pos]){
            segtree[pos]=assign(h,lazytree[pos],segtree[pos]);
        }
    }
    void apply(int pos, U value, int h){
        segtree[pos]=assign(h, value, segtree[pos]);
        if(pos<n){
            if(!isempty[pos]){
                lazytree[pos]=lazyassign(value, lazytree[pos]);
            }
            else{
                lazytree[pos] = value;
            }
            isempty[pos]=0;
        }
    }
    void updatenode(int pos){
        int h=0;
        pos+=n;
        while(pos>1){
            h++;
            pos>>=1;
            calc(pos, h);
        }
    }
    void push(int pos){
        int h=H;
        for(pos+=n;h;--h){
            int x=(pos>>h);
            if(!isempty[x]){
                apply((x<<1), lazytree[x], h-1);
                apply((x<<1)|1, lazytree[x], h-1);
                isempty[x]=1;
            }
        }
    }
    void updaterange(int l, int r, U value){
        push(l);
        push(r);
        int k=0;
        int l0=l, r0=r;
        for(l+=n, r+=n+1;l<r;l>>=1, r>>=1, k++){
            if(l&1){
                apply(l++, value, k);
            }
            if(r&1){
                apply(--r, value,k);
            }
        }
        updatenode(l0);
        updatenode(r0);
    }
    T query(int l, int r){
        push(l);
        push(r);
        T ansl=base;
        T ansr=base;
        for(l+=n,r+=n+1;l<r;l>>=1,r>>=1){
            if(l&1){
                ansl=join(ansl, segtree[l++]);
            }        
            if(r&1){
                ansr=join(segtree[--r], ansr);
            }
        }
        return join(ansl,ansr);
    }
};
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void solve(){
    int n,q;
    cin>>n>>q;
    set<array<int, 3>> ranges;
    ranges.insert({1, n, 1});
    int sum = n;
    //for(auto &[x, y, k] : ranges) cout<<x<<" "<<y<<" "<<k<<"\n";
    //cout<<sum<<"\n";
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        --k;
        auto it = ranges.lower_bound({l+1, -1, -1});
        assert(it != ranges.begin());
        --it;
        assert(it != ranges.end());
        if((*it)[0] <= l && (*it)[1] >= r){
            if(k == (*it)[2]){
                cout<<sum<<"\n";
                continue;
            }
            sum += (r - l + 1) * (2 * k - 1);
            if((*it)[0] < l){
                ranges.insert({(*it)[0], l-1, (*it)[2]});
                assert(l - 1 != 0);
            } 
            if((*it)[1] > r){
                ranges.insert({r+1, (*it)[1], (*it)[2]});
                assert((*it)[1] != 0);
            }
            ranges.insert({l, r, k});
            ranges.erase(it);
            //for(auto &[x, y, k] : ranges) cout<<x<<" "<<y<<" "<<k<<"\n";
            cout<<sum<<"\n";
            //cout<<"\n";
            continue;
        }
        if((*it)[1] < r){
            if((*it)[2] == k){
                l = (*it)[0];
                auto it2 = it;
                ++it;
                assert(it2 != ranges.end());
                sum -= ((*it2)[1] - (*it2)[0] + 1) * (*it2)[2];
                ranges.erase(it2);
            }
            else{
                auto it2 = it;
                ++it;
                assert(it2 != ranges.end());
                if(l - 1 >= (*it2)[0]){
                    sum += (l - (*it2)[0]) * (*it2)[2];
                    ranges.insert({(*it2)[0], l-1, (*it2)[2]});
                } 
                sum -= ((*it2)[1] - (*it2)[0] + 1) * ((*it2)[2]);
                ranges.erase(it2);
            }
        }
        while(it != ranges.end()){
            if((*it)[1] > r) break;
            auto it2 = it;
            it++;
            assert(it2 != ranges.end());
            sum -= ((*it2)[1] - (*it2)[0] + 1) * (*it2)[2];
            ranges.erase(it2);
        }
        if(it != ranges.end() && r >= (*it)[0]){
            if(k == (*it)[2]){
                r = (*it)[1];
                auto it2 = it;
                ++it;
                assert(it2 != ranges.end());
                sum -= ((*it2)[1] - (*it2)[0] + 1) * (*it2)[2];
                ranges.erase(it2);
            }
            else{
                auto it2 = it;
                ++it;
                assert(it2 != ranges.end());
                sum += ((*it2)[1] - r) * (*it2)[2];
                ranges.insert({r+1, (*it2)[1], (*it2)[2]});
                sum -= ((*it2)[1] - (*it2)[0] + 1) * (*it2)[2];
                ranges.erase(it2);
            }
        }
        ranges.insert({l, r, k});
        sum += k * (r - l + 1);
        //for(auto &[x, y, k] : ranges) cout<<x<<" "<<y<<" "<<k<<"\n";
        cout<<sum<<"\n";
        //cout<<"\n";
        //cout.flush();
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}