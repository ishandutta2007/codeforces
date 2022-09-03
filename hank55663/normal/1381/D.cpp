#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
//#define ll long long
struct node{
    node *l,*r;
    int a,b;
    int Max;
    int tag;
    node(int _a,int _b):a(_a),b(_b),l(NULL),r(NULL){
        Max=0;
        tag=0;
    }
}*root;
int Max(node *n){
    return n->Max+n->tag;
}
void pull(node *n){
    n->Max=max(Max(n->l),Max(n->r));

    //for(int i =0;i<3;i++)n->Max[i]=a[i];
}
void push(node *n){
    n->l->tag+=n->tag;
    n->r->tag+=n->tag;
    n->tag=0;
}
void build(node *n,int *a){
    if(n->a==n->b){
        n->Max=a[n->a];
        return ;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
    pull(n);
}
void add(node *n,int l,int r,int k){
    if(l>r)return;
    if(n->a>=l&&n->b<=r){
        n->tag+=k;
        return ;
    }
    if(n->b<l||n->a>r)return ;
    push(n);
    add(n->l,l,r,k);
    add(n->r,l,r,k);
    pull(n);
}
int in[100005];
int out[100005];
int d[100005];
vector<int> v[100005];
int t;
void dfs(int x,int f){
    in[x]=++t;
    d[t]=d[in[f]]+1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
    }
    out[x]=t;
}
vector<int> stk;
int go(int s,int t,int f){
   /// printf("%d %d %d\n",s,t,f);
    //getchar();
    stk.pb(s);
    if(s==t)return 1;
    for(auto it:v[s]){
        if(it!=f){
            int x;
            if(x=go(it,t,s))return x+1;
        }
    }
    stk.pop_back();
    return 0;
}
int query(node *n,int l,int r){
    if(l>r)return 0;
    if(n->a>=l&&n->b<=r){
        return Max(n);//->Max;
    }
    if(n->b<l||n->a>r){
        return 0;
    }
    push(n);
   // node nn(1,1);
    int a=query(n->l,l,r);
    int b=query(n->r,l,r);
   // nn.l=&ll;
   // nn.r=&rr;
    pull(n);
   // pull(nn);
    return max(a,b);
}
vector<int> ans;
int Max1[100005],Maxi[100005],Max2[100005];
int n;
void dfs2(int x,int f,int q){
    Max1[x]=Max2[x]=0;
    vector<int> Max;
    for(auto it:v[x]){
        if(it!=f){
            int a;
            Max.pb(a=query(root,in[it],out[it]));
            if(a>Max1[x]){
                Max2[x]=Max1[x];
                Max1[x]=a;
                Maxi[x]=it;
            }
            else if(a>Max2[x]){
                Max2[x]=a;
            }
        }
    }
    int a;
    Max.pb(a=max(query(root,1,in[x]-1),query(root,out[x]+1,n)));
    if(a>Max1[x]){
        Max2[x]=Max1[x];
        Max1[x]=a;
        Maxi[x]=f;
    }
    else if(a>Max2[x]){
        Max2[x]=a;
    }
    sort(Max.begin(),Max.end());
    reverse(Max.begin(),Max.end());
    if(Max.size()>=3&&Max[2]>=q)ans.pb(x);
    for(auto it:v[x]){
        if(it!=f){
            add(root,in[it],out[it],-1);
            add(root,1,in[it]-1,1);
            add(root,out[it]+1,n,1);
            dfs2(it,x,q);
            add(root,in[it],out[it],1);
            add(root,1,in[it]-1,-1);
            add(root,out[it]+1,n,-1);
        }
    }
}
int get(int a,int b){
    if(Maxi[a]==b)return Max2[a];
    return Max1[a];
}
int ok[100005];
void dfs3(int x,int f){
    ok[x]=1;
    for(auto it:v[x]){
        if(it!=f)
            dfs3(it,x);
    }
}
void solve(){
    int a,b;
    scanf("%d %d %d",&n,&a,&b);
    t=0;
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    
    dfs(1,0);
  //  printf("%d %d\n",a,b);
  stk.clear();
    int dis=go(a,b,0);
    root=new node(1,n);
    build(root,d);
    ans.clear();
    dfs2(1,0,dis);
    //if(ans)printf("YES\n");
    //else printf("NO\n");
    int Maxa=get(stk[0],stk[1]),Maxb=get(stk.back(),stk[stk.size()-2]);
    int l=0,r=stk.size()-1;
    while(l+1<Maxb||r-1>(int)stk.size()-1-Maxa){
      //  printf("%d %d %d %d\n",l,r,Maxa,Maxb);
        if(l+1<Maxb){
            l++;
            if(l!=stk.size()-1){
                Maxa=get(stk[l],stk[l+1])-l;
            }
            else{
                break;
            }
        }
        if(r-1>(int)stk.size()-Maxa-1){
            r--;
            if(r!=0){
                Maxb=get(stk[r],stk[r-1])-(stk.size()-1-r);
            }
            else{
                break;
            }
        }
    }
  //  for(auto it:stk)printf("%d ",it);
   // printf("%d %d\n",l,r);
    fill(ok,ok+n+1,0);
    if(l==stk.size()-1||r==0){
        if(ans.size())
        printf("YES\n");
        else{
            printf("NO\n");
        }
    }
    else{
        dfs3(stk[l],stk[l+1]);
        dfs3(stk[r],stk[r-1]);
        for(auto it:ans){
            if(ok[it]){
                printf("YES\n");
                return ;
            }
        }
        printf("NO\n");
    }
}
int main(){
    int t;
    scanf("%d",&t);
    //Find();
    while(t--){
        solve();
    }
}