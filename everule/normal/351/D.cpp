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
const int MAXA = 1e5 + 7;
const int sqrtn = 350;
struct query{
    int l,r,idx;
    bool operator<(const query &o){
        if(o.l/sqrtn!=l/sqrtn){
            return l/sqrtn < o.l/sqrtn;
        }
        if(l/sqrtn&1){
            return r > o.r;
        }
        else{
            return r < o.r;
        }
    }
};
void solve(){
    int n;
    cin>>n;
    vector<int> seq(n);
    vector<int> count(MAXA);
    vector<vector<int>> pos(MAXA);
    for(auto &x : seq) {
        cin>>x;
        --x;
        ++count[x];
    }
    vector<int> whichoccurence(n);
    for(int i=0;i<n;i++){
        whichoccurence[i] = pos[seq[i]].size();
        pos[seq[i]].pb(i);
    }
    vector<vector<int>> range(MAXA);
    for(int i=0;i<MAXA;i++){
        range[i].assign(count[i],0);
        for(int j=0,k=1;j<count[i] && k<count[i];j++){
            int diff = pos[i][k] - pos[i][k-1];
            while(k<count[i]){
                if(pos[i][k] - pos[i][k-1] != diff){
                    j = k - 2;
                    break;
                }
                range[i][k] = j;
                ++k;
            }
        }
    }
    int Q;
    cin>>Q;
    vector<query> queries(Q);
    for(int i=0;i<Q;i++){
        cin>>queries[i].l>>queries[i].r;
        queries[i].idx = i;
        --queries[i].l;--queries[i].r;
    }
    sort(queries.begin(), queries.end());
    int l=0,r=-1;
    vector<deque<int>> currpos(MAXA);
    vector<int> currcount(MAXA);
    vector<int> ans(Q);
    int good = 0;
    int distinct = 0;
    for(const auto &q : queries){
        while(r<q.r){
            ++r;
            if(currcount[seq[r]]) --distinct;
            ++currcount[seq[r]];
            if(currcount[seq[r]]) ++distinct;
            if(currpos[seq[r]].size() && range[seq[r]][currpos[seq[r]].back()] <= currpos[seq[r]].front()) --good;
            currpos[seq[r]].push_back(whichoccurence[r]);
            if(currpos[seq[r]].size() && range[seq[r]][currpos[seq[r]].back()] <= currpos[seq[r]].front()) ++good;
        }
        while(l>q.l){
            --l;
            if(currcount[seq[l]]) --distinct;
            ++currcount[seq[l]];
            if(currcount[seq[l]]) ++distinct;
            if(currpos[seq[l]].size() && range[seq[l]][currpos[seq[l]].back()] <= currpos[seq[l]].front()) --good;
            currpos[seq[l]].push_front(whichoccurence[l]);
            if(currpos[seq[l]].size() && range[seq[l]][currpos[seq[l]].back()] <= currpos[seq[l]].front()) ++good;
        }
        while(r>q.r){
            if(currcount[seq[r]]) --distinct;
            --currcount[seq[r]];
            if(currcount[seq[r]]) ++distinct;
            if(currpos[seq[r]].size() && range[seq[r]][currpos[seq[r]].back()] <= currpos[seq[r]].front()) --good;
            currpos[seq[r]].pop_back();
            if(currpos[seq[r]].size() && range[seq[r]][currpos[seq[r]].back()] <= currpos[seq[r]].front()) ++good;
            --r;
        }
        while(l<q.l){
            if(currcount[seq[l]]) --distinct;
            --currcount[seq[l]];
            if(currcount[seq[l]]) ++distinct;
            if(currpos[seq[l]].size() && range[seq[l]][currpos[seq[l]].back()] <= currpos[seq[l]].front()) --good;
            currpos[seq[l]].pop_front();
            if(currpos[seq[l]].size() && range[seq[l]][currpos[seq[l]].back()] <= currpos[seq[l]].front()) ++good;
            ++l;
        }
        ans[q.idx] = distinct;
        if(good==0){
            ans[q.idx]++;
        }
    }
    for(const auto &x : ans){
        cout<<x<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}