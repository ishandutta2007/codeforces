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
const int mod=998244353;
pii p[300005];
/*
struct node{
    node *l,*r;
    pii p;
    int a,b;
    node(int _a,int _b):l(NULL),r(NULL),p(0,0),a(_a),b(_b){

    }
}*roota,*rootb;
void build(node *n,int *a){
    if(n->a==n->b){
        n->p=mp(0,a[n->a]);
        return;
    }
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l,a);
    build(n->r,a);
}
void add()*/
vector<pair<int,pii> > v[300005];
int ans[300005];
void solve(){
    int n,q,mod;
    p[0]=mp(1,0);
    p[1]=mp(0,1);
    scanf("%d %d %d",&n,&q,&mod);
    for(int i = 2;i<=n;i++){
        p[i].x=(p[i-1].x+p[i-2].x)%mod;
        p[i].y=(p[i-1].y+p[i-2].y)%mod;
    }
    int a[300005],b[300005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    for(int i = 1;i<=n;i++)scanf("%d",&b[i]);
    for(int i = 1;i<=q;i++){
        char c;
        int l,r;
        scanf(" %c %d %d",&c,&l,&r);
        if(c=='A'){
            v[l].pb(mp(i,mp(0,1)));
            v[r+1].pb(mp(i,mp(mod-p[r-l+2].x,mod-p[r-l+2].y)));
        }
        else{
             v[l].pb(mp(i,mp(0,mod-1)));
             v[r+1].pb(mp(i,mp(p[r-l+2].x,p[r-l+2].y)));
        }
    }
    vector<pair<int,pii> > add;
    for(int i = 1;i<=n;i++){
        for(auto &it:add){
            it.y=mp(it.y.y,(it.y.x+it.y.y)%mod);
        }
        for(auto it:v[i]){
            add.pb(it);
        }
        sort(add.begin(),add.end());
     //    for(auto it:add)printf("%d %d %d\n",it.x,it.y.x,it.y.y);
      //  printf("\n");
     //   printf("\\\\");
        for(int i = 1;i<add.size();i++){
            add[i].y.x+=add[i-1].y.x;
            add[i].y.y+=add[i-1].y.y;
            add[i].y.x%=mod;
            add[i].y.y%=mod;
        }
        if(a[i]!=b[i]){
            ans[0]++;
            if(add.size())ans[add[0].x]--;
        }
      //   for(int j = 0;j<=q;j++)printf("%d ",ans[j]);
      //  printf("\n");
      //  for(auto it:add)printf("%d %d %d\n",it.x,it.y.x,it.y.y);
      //  printf("\n");
        for(int j = 0;j<add.size();j++){
            if((a[i]+add[j].y.y)%mod!=b[i]){
            //    printf("? %d %d %d %d\n",a[i],add[j].y.y,b[i],j);
                ans[add[j].x]++;
                if(j!=add.size()-1)ans[add[j+1].x]--;
            }
        }
        vector<pair<int,pii> > tmp;
        for(int j = 0;j<add.size();j++){
            if((a[i]+add[j].y.y)%mod==b[i]){
                if(tmp.empty()||add[j].y!=tmp.back().y)
                tmp.pb(add[j]);
            }
        }
        if(tmp.size())
        for(int j = tmp.size()-1;j>0;j--){
            tmp[j].y.x-=tmp[j-1].y.x;
            tmp[j].y.y-=tmp[j-1].y.y;
            tmp[j].y.x=(tmp[j].y.x+mod)%mod;
            tmp[j].y.y=(tmp[j].y.y+mod)%mod;
        }
        swap(tmp,add);
        /*   for(auto it:add)printf("%d %d %d\n",it.x,it.y.x,it.y.y);
        printf("\n");
        for(int j = 0;j<=q;j++)printf("%d ",ans[j]);
        printf("\n");*/
    } 
    int now=0;
    for(int i = 0;i<=q;i++){
        now+=ans[i];
        if(i){
            if(now)printf("No\n");
            else printf("Yes\n");
        }
    }
} 
/*
LLRLLR
012345
LRLL
1
2
2
1
1
*/
int main(){
   /* for(int i = 2;i<=1000000;i++){
        if(v[i].empty())
        for(int j = i;j<=1000000;j+=i )v[j].pb(i);
    }*/
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
(k_1x+b)k_2+b=y
3 1 2 4 5

36
0123
0123 4567

RRRRR
6 4 4 4
5 3 4 4
4 3 3 4
4 2 4 4
3 2 3 4
4 4 2 4


*/