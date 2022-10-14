/**
 *    author:  gary
 *    created: 19.01.2022 13:23:51
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
const int MAXN=1e5+1;
int n,q,b[MAXN],c[MAXN],d[MAXN],cnt1,cnt2,X[MAXN],Y[MAXN];
deque<int> dq[MAXN];
bool cmp(mp A,mp B){
    if(A.FIR/333!=B.FIR/333) return A.FIR<B.FIR;
    return A.SEC<B.SEC;
}
void add(int val,int pos,bool dir){
    c[val]++;
    cnt1+=c[val]==1;
    int old=d[val];
    if(dir==1){ 
        dq[val].PB(pos);
        if(dq[val].size()>=3){
            d[val]+=(dq[val][dq[val].size()-3]+dq[val][dq[val].size()-1])!=(dq[val][dq[val].size()-2]*2);
        }
    }
    if(dir==0){ 
        dq[val].push_front(pos);
        if(dq[val].size()>=3){
            d[val]+=(dq[val][0]+dq[val][2])!=(dq[val][1]*2);
        }
    }
    if(c[val]==1) cnt2++;
    cnt2-=d[val]&&!old;
}
void era(int val,bool dir){
    c[val]--;
    cnt1-=c[val]==0;
    int old=d[val];
    if(dir==1){ 
        if(dq[val].size()>=3){
            d[val]-=(dq[val][dq[val].size()-3]+dq[val][dq[val].size()-1])!=(dq[val][dq[val].size()-2]*2);
        }
        dq[val].POB();
    }
    if(dir==0){ 
        if(dq[val].size()>=3){
            d[val]-=(dq[val][0]+dq[val][2])!=(dq[val][1]*2);
        }
        dq[val].pop_front();
    }
    if(c[val]==0) cnt2--;
    cnt2+=!d[val]&&old;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) cin>>b[i];
    cin>>q;
    vector<mp> queries;
    rb(i,1,q){
        int l,r;
        cin>>l>>r;
        queries.PB(II(l,r));
        X[i]=l,Y[i]=r;
    }
    sort(ALL(queries),cmp);
    map<mp,int> ans;
    int l=1,r=0;
    for(auto it:queries){
        while(r<it.SEC) add(b[r+1],r+1,1),++r;
        while(l>it.FIR) add(b[l-1],l-1,0),--l;
        while(r>it.SEC) era(b[r--],1);
        while(l<it.FIR) era(b[l++],0);
        ans[it]=cnt1+1-(cnt2!=0);
    }
    rb(i,1,q) cout<<ans[II(X[i],Y[i])]<<endl;
    return 0;
}