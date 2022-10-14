/**
 *    author:  gary
 *    created: 15.08.2022 11:03:10
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
map<pair<int,LL> ,LL>  save;
LL query(int i,LL x){
    if(save.count(II(i,x))) return save[II(i,x)];
    cout<<"? "<<i<<" "<<x<<endl;
    // if(x<=4) return x;
    // return 5;
    ff;
    LL val;
    cin>>val;
    return save[II(i,x)]=val;
}
LL l[1001],r[1001];
SRAND;
LL k_th_element(vector<int> v,int k,LL targ,LL from,LL to){
    LL l=from,r=to;
    int x=random(v.size());
    while (l<r){
        LL mid=(l+r)>>1;
        if(query(v[x],mid)-query(v[x],from)<targ) l=mid+1;
        else r=mid;
    }
    vector<int> vl,vr;
    rep(i,v.size()){
        if(i!=x){
            if(query(v[i],l-1)-query(v[i],from)>=targ) vl.push_back(v[i]);
            else if(query(v[i],l)-query(v[i],from)<targ) vr.push_back(v[i]);
            else if(v[i]<v[x]) vl.push_back(v[i]);
            else vr.push_back(v[i]);
        }
    }
    if(k==vl.size()+1) return l;
    if(k<=vl.size()) return k_th_element(vl,k,targ,from,to);
    return k_th_element(vr,k-1-vl.size(),targ,from,to);
}
void solve(vector<int> v,LL b,LL L,LL R){
    if(v.empty()) return;
    if(v.size()==1){
        l[v[0]]=L;
        r[v[0]]=R;
        return ;
    }
    LL x=k_th_element(v,v.size()/2,b*(v.size()/2),L,R);
    vector<pair<LL,int> > V;
    vector<int> vl,vr;
    for(auto it:v) V.emplace_back(query(it,x)-query(it,L),it);
    sort(ALL(V));
    reverse(ALL(V));
    rep(i,v.size()/2) vl.push_back(V[i].second);
    rb(i,v.size()/2,v.size()-1) vr.push_back(V[i].second);
    solve(vl,b,L,x);
    solve(vr,b,x,R);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    LL L;
    cin>>n>>L;
    L/=n;
    vector<int> v;
    rb(i,1,n) v.push_back(i);
    solve(v,L,0,1e18);
    cout<<"!\n";
    rb(i,1,n) cout<<l[i]<<" "<<r[i]<<endl;
    ff;
    return 0;
}