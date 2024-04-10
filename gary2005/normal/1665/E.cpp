/**
 *    author:  gary
 *    created: 08.04.2022 22:37:53
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
const int INF=2e9;
typedef pair<int,int> mp;
const int N=1<<17;
int n,a[N];
pair<mp,mp> sgt[N+N];
pair<mp,mp> merge(pair<mp,mp> A,pair<mp,mp> B){
    if(A.first<B.first){
        return II(A.first,min(A.second,B.first));
    }
    return II(B.first,min(A.first,B.second));
}
void modify(int pos,int val){
    sgt[pos+N-1]=II(II(val,pos),II(INF,INF));
    pos+=N-1;
    pos>>=1;
    while(pos){
        sgt[pos]=merge(sgt[pos<<1],sgt[pos<<1|1]);
        pos>>=1;
    }
}
pair<mp,mp> query(int a,int b,int now=1,int l=1,int r=N+1){
    if(r<=a||l>=b) return II(II(INF,INF),II(INF,INF));
    if(r<=b&&l>=a) return sgt[now];
    int mid=(l+r)>>1;
    return merge(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
}
void solve(){
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]);
    rb(i,1,n){
        int ii=i+N-1;
        while(ii){sgt[ii]=II(II(INF,INF),II(INF,INF)),ii>>=1;}
    }
    int q;
    rb(i,1,n){
        modify(i,a[i]);
    }
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d%d",&l,&r);
        r++;
        int rest;
        vector<mp> tmp;
        while (true){
            auto it=query(l,r);
            if(it.first.first==it.second.first){
                rest=it.first.first;
                break;
            }
            tmp.PB(II(it.first.second,a[it.first.second]));
            a[it.first.second]^=1<<(31-__builtin_clz(it.FIR.FIR^it.SEC.FIR));
            modify(it.first.second,a[it.first.second]);
        }
        reverse(ALL(tmp));
        for(auto it:tmp){
            a[it.first]=it.second;
            modify(it.first,a[it.first]);
        }
        printf("%d\n",rest);
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        solve();
    }
    return 0;
}