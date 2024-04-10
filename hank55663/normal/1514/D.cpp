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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct node{
    node *l,*r;
    int val,cnt;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b),val(0),cnt(0){

    }
    node():l(NULL),r(NULL),val(0),cnt(0){
        
    }
}*root;
void pull(node *n){
    if(n->l->val==n->r->val){
        n->val=n->l->val;
        n->cnt=n->r->cnt+n->l->cnt;
    }
    else{
        if(n->l->cnt>n->r->cnt){
            n->val=n->l->val;
            n->cnt=n->l->cnt-n->r->cnt;
        }
        else{
            n->val=n->r->val;
            n->cnt=n->r->cnt-n->l->cnt;
        }
    }
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->val=a[n->a];
        n->cnt=1;
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
node query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return *n;
    }
    if(n->b<l||n->a>r){
        node nn;
        return nn;
    }
    node nn;
    node ll=query(n->l,l,r);
    node rr=query(n->r,l,r);
    nn.l=&ll;
    nn.r=&rr;
    pull(&nn);
    return nn;
}
vector<int> v[300005];
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    int a[300005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]].pb(i);
    }
    root=new node(1,n);
    build(root,a);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        node n=query(root,l,r);
        int x=n.val;
        int cnt=upper_bound(v[x].begin(),v[x].end(),r)-lower_bound(v[x].begin(),v[x].end(),l);
        if(cnt>(r-l+2)/2){
            int Max=r-l+1,Min=1;
            while(Max>Min+1){
                int mid=(Max+Min)/2;
                if(cnt-mid+1>(r-l+1-mid+1+1)/2)Min=mid;
                else Max=mid;
            }
            printf("%d\n",Max);
        }
        else{
            printf("1\n");
        }
    }
}
int main(){
    int t=1;00000;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
000
011
101
*/