/**
 *    author:  gary
 *    created: 20.02.2022 22:31:52
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
const int MAXN=3e5+1;
int n,q;
int x[MAXN],h[MAXN];
set<int> se;
vector<pair<mp,long long> > ve;
bool cmp(int A,int B){
    return h[A]>h[B];
}
const int N=1<<19;
LL mn[N+N];
LL query(int a,int b,int now=1,int l=1,int r=N+1){
    if(r<=a||l>=b) return 4e18;
    if(r<=b&&l>=a) return mn[now];
    int mid=(l+r)>>1;
    return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
}
LL ans[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    rb(i,1,n) cin>>x[i]>>h[i];
    vector<int> ord;
    rb(i,1,n) ord.PB(i);
    sort(ALL(ord),cmp);
    rb(i,1,n) se.insert(i);
    for(auto it:ord){
        se.erase(it);
        auto ite=se.lower_bound(it);
        if(ite!=se.end()&&ite!=se.begin()){
            int l,r;
            l=*prev(ite);
            r=*ite;
            ve.PB(II(II(l,r),1ll*(h[l]+h[r])*abs(x[l]-x[r])));
        }
    }
    rb(i,1,n-1){
        ve.PB(II(II(i,i+1),1ll*(h[i]+h[i+1])*abs(x[i]-x[i+1])));
    }
    sort(ALL(ve));
    memset(mn,127,sizeof(mn));
    int p=0;
    vector<pair<mp,int> > qqq;
    int cnt=0;
    int Q=q;
    while(q--){
        int l,r;
        cin>>l>>r;
        qqq.PB(II(II(l,r),++cnt));
    }
    q=Q;
    sort(ALL(qqq));
    reverse(ALL(qqq));
    reverse(ALL(ve));
    for(auto it:qqq){
        while(p<ve.size()&&ve[p].first.first>=it.first.first){
            int now=ve[p].first.second;
            LL val=ve[p].second;
            now+=N-1;
            // cout<<ve[p].first.first<<" "<<ve[p].first.second<<" "<<ve[p].second<<endl;
            while(now){
                check_min(mn[now],val);
                now>>=1;
            }
            p++;
        }
        ans[it.second]=query(it.first.first,it.first.second+1);
    }
    rb(i,1,q){
        cout<<ans[i]<<endl;
    }
    return 0;
}