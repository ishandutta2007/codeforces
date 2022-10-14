/**
 *    author:  gary
 *    created: 29.10.2021 18:19:31
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
const int MAXN=2e5+9;
const int N=1<<18;
set<int> se;
struct SEGMENTTREE{
    int tree[N+N];
    SEGMENTTREE(){
        memset(tree,63,sizeof(tree));
    }
    void modify(int pos,int val){
        if(val!=INF) se.insert(pos);
        pos+=N-1;
        tree[pos]=val;
        pos>>=1;
        while(pos){
            tree[pos]=min(tree[pos<<1],tree[pos<<1|1]);
            pos>>=1;
        }
    }
    int query(int a,int b,int now=1,int l=1,int r=N+1){
        if(r<=a||l>=b) return INF;
        if(r<=b&&l>=a) return tree[now];
        int mid=(l+r)>>1;
        return min(query(a,b,now<<1,l,mid),query(a,b,now<<1|1,mid,r));
    }
}sgt;
int n,a[MAXN];
vector<int> vv;
vector<int> pos[MAXN];
int pre[MAXN],suf[MAXN];
int pt[MAXN];
int t;
void solve(int testid){
    vv.clear();
    se.clear();
    scanf("%d",&n);
    rb(i,1,n) scanf("%d",&a[i]),vv.PB(a[i]);
    rb(i,1,n+4) sgt.modify(i,INF);
    sort(ALL(vv));
    vv.erase(unique(ALL(vv)),vv.end());
    rb(i,1,n) a[i]=lower_bound(ALL(vv),a[i])-vv.begin()+2;
    rb(i,1,vv.size()+1) pos[i].clear();
    rb(i,1,n) pos[a[i]].PB(i);
    int OLDn=n;
    n=vv.size()+1;
    rb(i,1,n) reverse(ALL(pos[i]));
    suf[n+1]=suf[n+2]=0;
    rb(i,1,n){
        pre[i]=pre[i-1];
        pre[i]+=pos[i].size();
    }
    rl(i,n,1){
        suf[i]=suf[i+1];
        suf[i]+=pos[i].size();
    }
    int r=2;
    int ans=OLDn-1;
    rb(i,1,n) pt[i]=0;
    rb(l,1,n-1){
        for(auto it:pos[l]){
            sgt.modify(it,INF);
            if(se.find(it)==se.end()) exit(0);
            se.erase(it);
        }
        reverse(ALL(pos[l]));
        while(true){
            while(r<=n&&pos[r].size()==pt[r]) r++;
            if(r>n) break;
            bool ok=1;
            while(pos[r].size()>pt[r]){
                if(sgt.query(pos[r][pt[r]],OLDn+1)>=r){
                    pt[r]++;
                    sgt.modify(pos[r][pt[r]-1],r);
                    int tmp=pre[l]+suf[r+1]+pos[r].size()-pt[r];
                    tmp-=lower_bound(ALL(pos[l]),*se.begin())-pos[l].begin();
                    check_min(ans,tmp);
                }
                else{
                    ok=0;
                    break;
                }
            }
            if(ok==0) break;
        }
        // cout<<l<<' '<<r<<" "<<pt[r]<<" "<<sgt.query(pos[r][pt[r]],n+1)<<endl;
        if(r>n) break;
    }
    // if(t<=1000)
    printf("%d\n",ans);
    // else{
    //     if(testid==4999){
    //         cout<<OLDn<<endl;
    //         rb(i,1,OLDn) cout<<a[i]<<" ";
    //         cout<<endl;
    //     }
    // }
}
int main(){
    // freopen("test.in","r",stdin);
    scanf("%d",&t);
    rb(z,1,t) solve(z);
    return 0;
}