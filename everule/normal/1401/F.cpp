#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
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
struct node{
    ll val = 0;
    int swaps = 0;
    node* par = NULL;
    node* left=NULL;
    node* right=NULL;
};
struct segment_tree{
    int n;
    int lgn;
    vector<int> seq;
    vector<int> swaps;
    node* root;
    segment_tree(int lgn) : lgn(lgn){
        int n = (1<<lgn);
        seq.resize(n);
        swaps.resize(lgn);
        cin>>seq;
        root = new node;
        build(root,0,n);
    }
    void build(node* curr,int l, int r){   
        if(l+1==r){
            curr->val = seq[l];
            return;
        }
        curr->left = new node;
        curr->right = new node;
        build(curr->right,(l+r)/2,r);
        build(curr->left,l,(l+r)/2);
        curr->val = curr->right->val + curr->left->val;
        curr->right->par = curr;
        curr->left->par = curr;
    }
    void reversetree(int k){
        for(int i=1;i<=k;i++){
            swaps[lgn - i]++;
        }
    }
    void swaptree(int k){
        swaps[lgn - k - 1]++;
    }
    void update(int idx, int val){
        --idx;
        vector<bool> move(lgn);
        for(int i=lgn-1;i>=0;i--){
            move[i] = idx&1;
            idx>>=1;
        }
        node* curr = root;
        for(int i=0;i<lgn;i++){
            if(curr->swaps != swaps[i]){
                if((swaps[i] - curr->swaps)&1) swap(curr->left, curr->right);
                curr->swaps = swaps[i];
            }
            if(move[i]){
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        curr->val = val;
        while(curr->par){
            curr=curr->par;
            curr->val = curr->right->val + curr->left->val;
        }
    }
    ll sum(ll idx){
        if(idx==0) return 0;
        --idx;
        vector<bool> move(lgn);
        for(int i=lgn-1;i>=0;i--){
            move[i] = idx&1;
            idx>>=1;
        }
        node* curr = root;
        ll ans = 0;
        for(int i=0;i<lgn;i++){
            if(curr->swaps != swaps[i]){
                if((swaps[i] - curr->swaps)&1) swap(curr->left, curr->right);
                curr->swaps = swaps[i];
            }
            if(move[i]){
                ans += curr->left->val;
                curr = curr->right;
            }
            else{
                curr = curr->left;
            }
        }
        ans+=curr->val;
        return ans;
    }
};
void solve(){
    int lgn,q;
    cin>>lgn>>q;
    segment_tree segtree(lgn);
    for(int i=0;i<q;i++){
        int type;
        cin>>type;
        if(type==1){
            int idx,val;
            cin>>idx>>val;
            segtree.update(idx, val);
        }
        if(type==2){
            int k;
            cin>>k;
            segtree.reversetree(k);
        }
        if(type==3){
            int k;
            cin>>k;
            segtree.swaptree(k);
        }
        if(type==4){
            int l,r;
            cin>>l>>r;
            cout<<segtree.sum(r) - segtree.sum(l-1)<<"\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}