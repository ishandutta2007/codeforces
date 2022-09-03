#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pll pair<LL,LL>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
vector<int> v[200005];
struct node{
    node *l,*r;
    int a,b;
    int last;
    pii Min;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){
        last=0;
    }
}*root;
node* Clone(node *n,int i){
    if(n->last==i)return n;
    node *res=new node(n->a,n->b);
    res->last=i;
    res->Min=n->Min;
    res->l=n->l;
    res->r=n->r;
    return res;
}
void pull(node *n){
    n->Min=min(n->l->Min,n->r->Min);
}
void build(node *n){
    if(n->a==n->b){
        n->Min=mp(n->a,n->a);
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
    pull(n);
}
void revise(node *n,int x,int k,int i){
    if(n->a==n->b){
        n->Min.x=k;
        return;
    }
    int mid=(n->a+n->b)/2;
    if(x<=mid){
      //  n->l=Clone(n->l,i);
        revise(n->l,x,k,i);
    }
    else{
       // n->r=Clone(n->r,i);
        revise(n->r,x,k,i);
    }
    pull(n);
}
pii query(node *n,int l,int r){
    if(n->a>=l&&n->b<=r){
        return n->Min;
    }
    if(n->b<l||n->a>r)return mp(1e9,0);
    return min(query(n->l,l,r),query(n->r,l,r));
}
void solve(){
    for(int i = 1;i<=200000;i++){
        for(int j = i;j<=200000;j+=i){
            v[j].pb(i);
        }
    }
    root=new node(1,200000);
    build(root);
    /*for(int i = 1;i<=200000;i++){
        root[i]=Clone(root[i-1],i);
        for(auto it:v[i]){
            revise(root[i],it,i+it,i);
        }
    }*/
    LL n,m,l,r;
    scanf("%lld %lld %lld %lld",&n,&m,&l,&r);
    vector<vector<LL> > ans;
    int last=0;
    int now=1;
    for(int i = n;i>=1;i--){
        LL yl=(l+i-1)/i,yr=min(r/i,m);
        int ok=0;
        if(yl>yr){
            ans.pb({-1});
            continue;
            //printf("-1\n");
            
        }
        while(now<yl){
            for(auto it:v[now]){
                revise(root,it,now+it,now);
            }
            now++;
        }
       // printf("%d %d\n",yl,yr);
        for(auto it:v[i]){
            LL x1=i;
           // LL y1=(yl+it)/(it+1)*(it+1);
            LL Max=n/(x1/it);
            LL y1;
            LL target;
            tie(y1,target)=query(root,it+1,Max);
            if(y1>yr){
                continue;
            }
            LL x2=x1/it*target;
            LL y2=x1*y1/x2;
            if(y1<=yr&&x2<=n){
                ans.pb({x1,y1,x2,y2});
                //printf("%lld %lld %lld %lld\n",x1,y1,x2,y2);
                ok=1;
                break;
            }
        }
        if(!ok){
            ans.pb({-1});
           // printf("-1\n");
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans){
        for(auto it2:it){
            printf("%lld ",it2);
        }
        printf("\n");
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}
/*
 
*/