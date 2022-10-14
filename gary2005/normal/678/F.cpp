/**
 *    author:  gary
 *    created: 15.03.2022 15:09:49
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
bool bad(mp A,mp B,mp C){
    // x= (B.second-A.second)/(A.first-B.first)
    long long vala,valb;
    vala=1ll*B.first*(B.second-A.second)+1ll*B.second*(A.first-B.first);
    valb=1ll*C.first*(B.second-A.second)+1ll*C.second*(A.first-B.first);
    if(A.first>B.first) return vala<=valb;
    return vala>=valb;
}
const int MAXN=3e5+10;
int n;
mp addi[MAXN];
int q[MAXN];
long long ans[MAXN];
vector<mp> getconvexhull(vector<mp> v){
    vector<mp> tmp;
    for(auto it:v){
        if(!tmp.empty()&&tmp.back().first==it.first) tmp.pop_back();
        while (tmp.size()>=2&&bad(tmp[tmp.size()-2],tmp[tmp.size()-1],it)){
            tmp.pop_back();
        }
        tmp.push_back(it);
    }
    return tmp;
}
vector<int> cdq(int l,int r,vector<pair<mp,mp > > &seg){
    vector<pair<mp,mp> > tol,tor;
    vector<mp> now;
    int mid=(l+r)>>1;
    for(auto it:seg){
        int L,R;
        tie(L,R)=it.first;
        if(L<=l&&R>=r) now.PB(it.second);
        else{
            if(L<=mid) tol.PB(it);
            if(R>mid) tor.PB(it);
        }
    }
    vector<int> idx;
    if(l==r){
        if(q[l]==INF) return {};
        idx.PB(l);
    }
    else{
        auto A=cdq(l,mid,tol);
        auto B=cdq(mid+1,r,tor);
        int pt=0;
        for(auto it:A){
            while (pt<B.size()&&q[B[pt]]<q[it]){
                idx.PB(B[pt++]);
            }
            idx.PB(it);
        }
        while (pt<B.size())
        {
            idx.PB(B[pt++]);
        }
    }
    now=getconvexhull(now);
    int pt=0;
    if(now.size())
    for(auto it:idx){
        int x=q[it];
        while (pt+1<now.size()&&1ll*now[pt].first*x+now[pt].second<1ll*now[pt+1].first*x+now[pt+1].second){
            pt++;
        }
        check_max(ans[it],1ll*now[pt].first*x+now[pt].second);
    }
    return idx;
}
bool cmp(pair<mp,mp> A,pair<mp,mp> B){
    return A.second<B.second;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<pair<mp,mp> > seg;
    cin>>n;
    rb(i,1,n){
        int t;
        cin>>t;
        if(t==1){
            int a,b;
            cin>>a>>b;
            addi[i]=II(a,b);
        }
        else addi[i]=II(-INF,-INF);
        if(t==2){
            int a;
            cin>>a;
            seg.PB(II(II(a,i),addi[a]));
            addi[a]=II(-INF,-INF);
        }
        if(t==3){
            cin>>q[i];
            ans[i]=-2e18;
        }
        else q[i]=INF;
    }
    rb(i,1,n) if(addi[i]!=II(-INF,-INF)) seg.PB(II(II(i,n),addi[i]));
    sort(ALL(seg),cmp);
    cdq(1,n,seg);
    rb(i,1,n) if(q[i]!=INF){
        if(ans[i]==-2e18) cout<<"EMPTY SET\n";
        else cout<<ans[i]<<endl;
    }
    return 0;
}