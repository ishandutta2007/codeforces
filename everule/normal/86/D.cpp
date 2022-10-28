#include <iostream>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#define ll long long int
#define mp make_pair
#define pb push_back
#define vi vector<int>
using namespace std;
const int B=1000;
vector<int> seq;
vector<ll> counts;
vector<ll> value;
vector<int> tochk;
vector<bool> inlist;
vector<int> num;
int n;
struct query{
    int l,r;
    int idx;
    bool operator<(const query &q){
        if(l/B != q.l/B){
            return q.l/B<l/B;
        }
        else{
            if(l/B & 1){
                return q.r<r;
            }
            else{
                return q.r>r;
            }
        }
    }
};
void update(int val, int type){
    counts[value[val]]-=num[val];
    value[val]+=type;
    if(!inlist[value[val]]){
        tochk.pb(value[val]);
        inlist[value[val]]=1;
    }
    counts[value[val]]+=num[val];
}
ll solve(const query &Q, bool reset=0){
    static int x, y;
    if(reset){
        x=0, y=0;
        tochk.clear();
        return 0;
    }
    while(y<Q.r){
        update(seq[y], 1);
        ++y;
    }
    while(x>Q.l){
        --x;
        update(seq[x], 1);
    }
    while(y>Q.r){
        --y;
        update(seq[y], -1);
    }
    while(x<Q.l){
        update(seq[x], -1);
        ++x;
    }
    ll ans=0;
    vector<int> nextochk;
    for(const auto &val : tochk){
        if(counts[val]==0){
            inlist[val]=0;
            continue;
        }
        nextochk.pb(val);
        ans+=counts[val]*val*val;
    }
    tochk=nextochk;
    return ans;
}
void init(){
    int Q;
    cin>>n>>Q;
    seq.resize(n);
    counts.clear();
    inlist.clear();
    inlist.resize(n+1);
    counts.resize(n+1);
    for(auto &x : seq){
        cin>>x;
    }
    map<int, int> remap;
    int base=0;
    for(auto &x : seq){
        if(remap.count(x)){
            x=remap[x];
        }
        else{
            remap[x]=base;
            num.pb(x);
            x=base;
            ++base;
        }
    }
    vector<query> queries(Q);
    for(int i=0;i<Q;i++){
        cin>>queries[i].l>>queries[i].r;
        queries[i].l--;
        queries[i].idx=i;
    }
    vector<ll> answers(Q);
    sort(queries.begin(), queries.end());
    value.clear();
    value.resize(base);
    solve(queries[0], 1);
    for(const auto &query : queries){
        answers[query.idx]=solve(query);
    }
    for(const auto &answer : answers){
        cout<<answer<<"\n";
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //FILE *input=freopen("input.txt", "r", stdin);
    //FILE *output=freopen("output2.txt", "w", stdout);
    init();
    //fclose(input);
    //fclose(output);
}