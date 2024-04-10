/**
 *    author:  gary
 *    created: 16.06.2022 22:23:59
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
const int MAXN=2e5+20;
int n,p[MAXN],premin[MAXN],premax[MAXN],dp[MAXN],suf[MAXN],mxr[MAXN],pos[MAXN],nexmax[MAXN],nexmin[MAXN],Fmax[MAXN],Fmin[MAXN],told[MAXN],toli[MAXN],tord[MAXN],tori[MAXN];
vector<int> solver(){
    stack<int> sta;
    rb(i,1,n){
        while (!sta.empty()&&p[sta.top()]>p[i]){
            sta.pop();
        }
        premin[i]=sta.empty()? 0:sta.top();
        sta.push(i);
    }
    while (!sta.empty())
    {
        sta.pop();
    }
    rb(i,1,n){
        while (!sta.empty()&&p[sta.top()]<p[i]){
            sta.pop();
        }
        premax[i]=sta.empty()? 0:sta.top();
        sta.push(i);
    }
    rb(i,1,n) pos[p[i]]=i;
    set<int> Fu;
    Fu.insert(1);
    set<int> Poss;
    Poss.insert(0);
    rl(i,n,1){
        auto ite=Poss.lower_bound(pos[i]);
        if(ite!=Poss.end()) Fu.insert(*ite);
        Poss.insert(pos[i]);
        Fmax[pos[i]]=*prev(Poss.lower_bound(*prev(Fu.upper_bound(pos[i]))));
    }
    Poss.clear();
    Poss.insert(0);
    Fu.clear();
    Fu.insert(1);
    rb(i,1,n){
        auto ite=Poss.lower_bound(pos[i]);
        if(ite!=Poss.end()) Fu.insert(*ite);
        Poss.insert(pos[i]);
        Fmin[pos[i]]=*prev(Poss.lower_bound(*prev(Fu.upper_bound(pos[i]))));
    }
    vector<int> A;
    rb(i,1,n){
        dp[i]=max(Fmax[i],Fmin[i])+1;
        A.PB(dp[i]);
    }
    return A;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    rb(i,1,n) cin>>p[i],mxr[i]=i;
    reverse(p+1,p+1+n);
    auto A=solver();
    rb(i,1,n) suf[i]=n-A[n-i]+1,nexmax[i]=n-premax[n-i+1]+1,nexmin[i]=n-premin[n-i+1]+1;
    reverse(p+1,p+1+n);
    solver();
    rb(i,1,n){
        check_max(mxr[dp[i]],suf[i]);
        if(i<n){
            vector<mp> seg[2];
            seg[0].PB(II(p[premax[i]],p[i]));
            seg[0].PB(II(p[i],p[premin[i]]));
            seg[1].PB(II(p[i+1],p[nexmin[i+1]]));
            seg[1].PB(II(p[nexmax[i+1]],p[i+1]));
            bool ok=0;
            // for(auto it:seg[0]) cout<<i<<" "<<it.first<<" "<<it.second<<endl;
            // for(auto it:seg[1]) cout<<i<<" "<<it.first<<" "<<it.second<<endl;
            for(auto it:seg[0])
            for(auto it2:seg[1]){
                ok|=it.first>=it2.second&&it.second<=it2.first;
            }
            if(ok)
            check_max(mxr[dp[i]],suf[i+1]);
        }
    }
    // rb(i,1,n){
    //     told[i]=i;
    //     toli[i]=i;
    //     if(i!=1){
    //         if(p[i-1]>p[i]){
    //             toli[i]=toli[i-1];
    //         }
    //         else told[i]=told[i-1];
    //     }
    // }
    // rl(i,n,1){
    //     tord[i]=i;
    //     tori[i]=i;
    //     if(i!=n){
    //         if(p[i+1]>p[i]){
    //             tori[i]=tori[i+1];
    //         }
    //         else{
    //             tord[i]=tord[i+1];
    //         }
    //     }
    // }
    // rb(i,1,n-1){
    //     check_max(mxr[toli[i]],tord[i+1]);
    //     check_max(mxr[told[i]],tori[i+1]);
    // }
    rb(i,2,n) check_max(mxr[i],mxr[i-1]);
    LL ans=0;
    rb(i,1,n) ans+=mxr[i]-i+1;
    // rb(i,1,n) cout<<mxr[i]<<endl;
    cout<<ans<<endl;
    return 0;
}