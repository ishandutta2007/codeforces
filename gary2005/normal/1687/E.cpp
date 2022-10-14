/**
 *    author:  gary
 *    created: 08.06.2022 19:55:23
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXA=1e6+10;
int n,a[100000+10],p[MAXA];
vector<int> fact[MAXA];
vector<mp> has[100000+10];
multiset<mp> need;
map<int,int> need2;
void doit(int i){
    for(auto it:has[i]){
        if(need.find(it)!=need.end()){
            need.erase(need.find(it));
        }
    }
}
void doit2(int i){
    for(auto ite=need2.begin();ite!=need2.end();){
        if(a[i]%ite->first){
            ite->second--;
            if(!ite->second){
                ite=need2.erase(ite);
            }
            else ite++;
        }
        else ite++;
    }
}
map<int,mp> useful;
set<int> cho;
void extend(vector<int> &v){
    map<int,int> cnt;
    for(auto i:v) for(auto it:has[i]) cnt[it.first]++;
    for(auto it:cnt) if(it.second+1>=v.size()&&useful.find(it.first)==useful.end()){
        if(it.second==v.size()) need2[it.first]=2;
        else need2[it.first]=1;
    }
    while (need2.size()){
        mp best=II(0,0);
        rb(i,1,n){
            if(cho.find(i)!=cho.end()) continue;
            int cont=0;
            for(auto it:need2) cont+=a[i]%it.first!=0;
            check_max(best,II(cont,i));
        }
        // cout<<need2.size()<<endl;
        cho.insert(best.second);
        doit2(best.second);
    }
    v.clear();
    for(auto it:cho) v.PB(it);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) cin>>a[i];
    rb(i,2,1000000) if(!p[i]){
        for(int j=i;j<=1000000;j+=i)
        p[j]=1,fact[j].PB(i);
    }
    map<int,vector<int> > have;
    rb(i,1,n){
        int now=a[i];
        for(auto it:fact[a[i]]){
            int cnt=0;
            while (now%it==0){
                cnt++;
                now/=it;
            }
            has[i].PB(II(it,cnt));
            have[it].PB(cnt);
        }
    }
    for(auto it:have) if(it.second.size()<n-1) ;
    else{
        sort(ALL(it.second));
        if(it.second.size()==n-1) useful[it.first]=II(0,it.second[0]);
        else useful[it.first]=II(it.second[0],it.second[1]);
    }
    for(auto it:useful){
        vector<int> v[2];
        rb(i,1,n){
            int now=a[i],cnt=0;
            while (now%it.first==0){
                now/=it.first;
                cnt++;
            }
            if(cnt==it.second.first) v[0].PB(i);
            else if(cnt==it.second.second) v[1].PB(i);
        }
        if(v[0].empty()) {
            need.insert(II(it.first,it.second.second));
            rb(i,1,n) if(a[i]%it.first) cho.insert(i);
        }
        else if(v[0].size()==1) cho.insert(v[0][0]),need.insert(II(it.first,it.second.second));
        else need.insert(II(it.first,it.second.first)),need.insert(II(it.first,it.second.first));
    }
    for(auto it:cho) doit(it);
    while (!need.empty()){
        mp best=II(0,0);
        rb(i,1,n) if(cho.find(i)==cho.end()){
            int cont=0;
            for(auto it:has[i]) cont+=need.find(it)!=need.end();
            check_max(best,II(cont,i));
        }
        cho.insert(best.second);
        doit(best.second);
    }
    vector<int> nwa;
    for(auto it:cho) nwa.PB(it);
    extend(nwa);
    // for(auto it:nwa) cout<<it<<',';
    // cout<<endl;
    vector<vector<int> > rest;
    rep(mask,1<<nwa.size()){
        int cnt=__builtin_popcount(mask);
        if(!mask) continue;
        cnt=(cnt&1? 1:-1)+(cnt&1? -1:1)*(cnt-1);
        while (abs(cnt)){
            vector<int> tmp;
            tmp.PB(cnt<0);
            tmp.PB(__builtin_popcount(mask));
            rep(j,nwa.size()){
                if((mask>>j)&1)
                tmp.PB(nwa[j]);
            }
            rest.PB(tmp);
            cnt+=(cnt<0? 1:-1);
        }
    }
    cout<<rest.size()<<endl;
    for(auto it:rest){
        for(auto itt:it) cout<<itt<<" ";
        cout<<'\n';
    }
    return 0;
}