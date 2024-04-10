#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int ans[200005];
int ans2[200005];
int cnt[200005];
vector<int> qquery[200005];
struct node{
    node *l,*r;
    int a,b;
    int Max;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL),Max(0){}
}*root;
void pull(node *n){
    n->Max=max(n->l->Max,n->r->Max);
}
void build(node *n){
    if(n->a==n->b){
        n->Max=ans[n->a];
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
int query(node *n,int l,int r){
    if(l>r)return -1;
    if(n->a>=l&&n->b<=r){
        return n->Max;
    }
    if(n->b<l||n->a>r)return 0;
    return max(query(n->l,l,r),query(n->r,l,r));
}
int Find(node *n,int l,int r){
    if(n->a==n->b&&n->Max==1e9&&n->a>=l&&n->b<=r)return n->a;
    if(n->a>=l&&n->b<=r){
        if(n->Max==1e9){
            return max(Find(n->l,l,r),Find(n->r,l,r));
        }
        else{
            return -1;
        }
    }
    if(n->b<l||n->a>r)return -1;
    return max(Find(n->l,l,r),Find(n->r,l,r));
}
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    vector<pair<int,vector<int> > > v;
    for(int i = 0;i<q;i++){
        int t;
        scanf("%d",&t);
        if(t==0){
            int l,r,x;
            scanf("%d %d %d",&l,&r,&x);
            v.pb(mp(t,vector<int>{l,r,x}));
            if(x==0){
                qquery[l].pb(i);
                qquery[r+1].pb(i);
            }
        }
        else{
            int x;
            scanf("%d",&x);
            v.pb(mp(t,vector<int>{x}));
        }
    }
    fill(ans,ans+200005,1e9);
      fill(ans2,ans2+200005,1e9);
    set<int> s;
    for(int i = 1;i<=n;i++){
        for(auto it:qquery[i]){
            if(s.find(it)==s.end())s.insert(it);
            else s.erase(it);
        }
        if(s.size()){
            ans[i]=*s.begin();
            cnt[i]++;
         //   printf("!!%d\n",i);
        }
        cnt[i]+=cnt[i-1];
    }
    root=new node(1,n);
    build(root);
    for(int i = 0;i<v.size();i++){
        if(v[i].x==0&&v[i].y.back()==1){
            int l=v[i].y[0],r=v[i].y[1];
         //   printf("??%d %d\n",cnt[r],cnt[l-1]);
            if(cnt[r]-cnt[l-1]==r-l){
               
                int x=Find(root,l,r);
            //     printf("!%d %d %d %d\n",i,l,r,x);
                ans2[x]=min(ans2[x],max(max(query(root,l,x-1),query(root,x+1,r)),i));
            }
        }
    }
    for(int i = 0;i<v.size();i++){
        if(v[i].x==1){
            int x=v[i].y[0];
            if(ans[x]==1e9&&ans2[x]==1e9){
                printf("N/A\n");
            }
            else if(ans[x]!=1e9){
                if(ans[x]<i)printf("NO\n");
                else printf("N/A\n");
            }
            else if(ans2[x]!=1e9){
                if(ans2[x]<i)printf("YES\n");
                else printf("N/A\n");

            }
        }
    }
}
int main(){
    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}