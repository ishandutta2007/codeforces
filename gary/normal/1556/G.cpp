/**
 *    author:  gary
 *    created: 31.08.2021 09:31:53
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
const int MOD=(1<<23)-1;
int n,m,cntseg;
int fa[20000000];
map<pair<LL,LL> ,int > segid;
map<LL,int> lg;
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void merge(int u,int v){
    fa[root(u)]=root(v);
}
set<pair<LL,LL> > alive;
set<pair<pair<LL,LL> ,int> > alive2;
vector<pair<LL,LL> > segs;
void get(LL A,LL B,LL L=0,LL R=1ll<<n){
    if(R<=B&&L>=A){
        segs.PB(II(L,R-1));
        return ;
    } 
    if(R<=A||L>=B) return ;
    LL mid=(L+R)>>1;
    get(A,B,L,mid);
    get(A,B,mid,R);
}
void add(LL l,LL r){
    alive.insert(II(l,r));
    segid[II(l,r)]=++cntseg;
    auto ite2=alive2.lower_bound(II(II(r+1,0),0));
    if(ite2!=alive2.begin()&&prev(ite2)->FIR.FIR<=l&&prev(ite2)->FIR.SEC>=r) merge(cntseg,prev(ite2)->SEC);
    else alive2.insert(II(II(l,r),cntseg));
    int now=cntseg;
    int d_=lg[r-l+1];
    rb(d,d_,n-1){
        l^=1ll<<d;
        r^=1ll<<d;
        auto ite=alive.lower_bound(II(r+1,0));
        bool z=0;
        if(ite!=alive.begin()){
            --ite;
            if(ite->FIR<=l&&ite->SEC>=r){
                merge(now,segid[*ite]);
                z=1;
            }
            ite++;
        }
        if(!z&&ite!=alive.begin()&&prev(ite)->SEC>=l){
            auto ite3=alive2.lower_bound(II(II(r+1,0),0));
            if(ite3!=alive2.begin()&&prev(ite3)->FIR.FIR<=l&&prev(ite3)->FIR.SEC>=r) merge(cntseg,prev(ite3)->SEC);
            else{
                auto ite=alive2.lower_bound(II(II(l,0),0));
                while(ite!=alive2.end()){
                    if(ite->FIR.FIR>r) break;
                    merge(cntseg,ite->SEC);
                    ite=alive2.erase(ite);
                }
                alive2.insert(II(II(l,r),cntseg));
            }
        }
        l^=1ll<<d;
        r^=1ll<<d;
    }

}
int main(){
    scanf("%d%d",&n,&m);
    vector<pair<string,pair<LL,LL> > > op;
    vector<int> ans;
    map<LL,int> lp;
    rep(i,60) lg[1ll<<i]=i;
    lp[0]=1;
    int cnt_ask=0;
    rb(i,1,m){
        string s;LL l,r;
        cin>>s;
        scanf("%lld%lld",&l,&r);
        op.PB(II(s,II(l,r)));
        cnt_ask+=(s[0]=='a');
        if(s=="block") lp[l]=lp[r+1]=1;
    }
    if(cnt_ask==0){
        return 0;
    }
    if(cnt_ask==1&&op[0].FIR=="ask"){
        cout<<1<<endl;
        return 0;
    }
    lp[1ll<<n]=1;
    for(auto ite=lp.begin();next(ite)!=lp.end();ite++){
        segs.clear();
        get(ite->FIR,next(ite)->FIR);
        for(auto it:segs) 
        alive.insert(it);
    }
    rep(i,20000000) fa[i]=i;
    reverse(ALL(op));
    for(auto it:op){
        if(it.FIR=="block"){
            segs.clear();
            get(it.SEC.FIR,it.SEC.SEC+1);
            for(auto it:segs)
            alive.erase(it);
        }
    }
    vector<pair<LL,LL> > Tmp;
    for(auto ite=alive.begin();ite!=alive.end();ite++) Tmp.PB(*ite);
    alive.clear();
    for(auto it:Tmp){
        add(it.FIR,it.SEC);
    }
    for(auto it:op){
        if(it.FIR=="ask"){
            LL a,b;
            a=it.SEC.FIR;
            b=it.SEC.SEC;
            auto itea=alive.lower_bound(II(a+1,0));
            itea--;
            auto iteb=alive.lower_bound(II(b+1,0));
            iteb--;
            ans.PB(root(segid[*itea])==root(segid[*iteb]));
        }
        if(it.FIR=="block"){
            segs.clear();
            get(it.SEC.FIR,it.SEC.SEC+1);
            for(auto it:segs)
            add(it.FIR,it.SEC);
        }
    }
    reverse(ALL(ans));
    for(auto it:ans){
        printf("%d\n",it);
    }
    return 0;
}