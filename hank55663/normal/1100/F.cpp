#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
#define MAXN 605
int a[500005];
int ans[500005];
vector<int> dl[500005],dr[500005];
void dc(int l,int r,vector<pair<pii,int> > v){
    int mid=(l+r)/2;
    dr[mid+1].clear();
    dr[mid+1].pb(a[mid+1]);
    for(int i=mid+2;i<=r;i++){
        dr[i]=dr[i-1];
        int x=a[i];
        for(auto &it:dr[i]){
            if(x>it)
            swap(x,it);
            x=min(x,x^it);
        }
        if(x)dr[i].pb(x);
    }
    dl[mid].clear();
    dl[mid].pb(a[mid]);
    for(int i=mid-1;i>=l;i--){
        dl[i]=dl[i+1];
        int x=a[i];
        for(auto &it:dl[i]){
            if(x>it)swap(x,it);
            x=min(x,x^it);
        }
        if(x)dl[i].pb(x);
    }
    vector<pair<pii,int> > vl,vr;
    for(auto q:v){
        if(q.x.y<=mid)
            vl.pb(q);
        else if(q.x.x>mid)
            vr.pb(q);
        else{
            vector<int> vv=dl[q.x.x];
            for(auto it2:dr[q.x.y]){
                for(auto &it:vv){
                    if(it2>it)swap(it,it2);
                    it2=min(it2,it2^it);
                }
                if(it2)
                vv.pb(it2);
            }
            ans[q.y]=0;
            for(auto it:vv){
                ans[q.y]=max(ans[q.y],ans[q.y]^it);
            }
        }
    }
    if(vl.size()){
        dc(l,mid,vl);
    }
    if(vr.size()){
        dc(mid+1,r,vr);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int q;
    scanf("%d",&q);
    vector<pair<pii,int> > v;
    for(int i=0;i<q;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        if(l==r){
            ans[i]=a[l];
        }
        else
        v.pb(mp(mp(l,r),i));
    }
    dc(1,n,v);
    for(int i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }
}