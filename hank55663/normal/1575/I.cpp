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
int Size[100005];
bool cmp(const int &a,const int &b){
    return Size[a]>Size[b];
}
vector<int> v[100005];
vector<pii> seg[100005];
void dfs(int x,int f){
    Size[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
        }
    }
    sort(v[x].begin(),v[x].end(),cmp);
}
vector<pii> tmp;
int in[100005];
int go[100005];
int t;
int p[100005][20];
int d[100005];
void dfs2(int x,int f){
    in[x]=++t;
    go[t]=x;
    p[x][0]=f;
    d[x]=d[f]+1;
    if(tmp.empty()||tmp.back().y+1!=in[x])tmp.pb(mp(in[x],in[x]));
    else tmp.back().y++;
    seg[x]=tmp;
    for(auto it:v[x]){
        if(it!=f){
            dfs2(it,x);
        }
    }
    tmp.back().y--;
    if(tmp.back().x>tmp.back().y)tmp.pop_back();
}
void build(int n){
    for(int i = 1;i<20;i++){
        for(int j =1;j<=n;j++){
            p[j][i]=p[p[j][i-1]][i-1];
        }
    }
}
int lca(int x,int y){
    if(d[x]>d[y])swap(x,y);
    int dd=d[y]-d[x];
    for(int i = 0;i<20;i++){
        if(dd&(1<<i))y=p[y][i];
    }
    if(x==y)return x;
    for(int i = 19;i>=0;i--){
        if(p[x][i]!=p[y][i]){
            x=p[x][i];
            y=p[y][i];
        }
    }
    return p[x][0];
}
LL S[100005];
void add(int x,LL k){
    for(int i = x;i<100005;i+=i&-i)S[i]+=k;
}
LL query(int x){
    LL res=0;
    for(int i =x;i>0;i-=i&-i)res+=S[i];
    return res;
}
int a[100005];
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]=abs(a[i]);
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
   // printf("?\n");
    dfs(1,0);
   // printf("!\n");
    dfs2(1,0);
  //  printf("X\n");
    build(n);
    //printf("W\n");

    for(int i = 1;i<=n;i++){
      //  printf("%d\n",in[i]);
        add(in[i],a[i]);
    }
   // printf("!\n");
    while(q--){
        int op,x,y;
        scanf("%d %d %d",&op,&x,&y);
        if(op==1){
            y=abs(y);
            add(in[x],-a[x]);
            a[x]=y;
            add(in[x],a[x]);
        }
        else{
            if(x==y){
                printf("0\n");
                continue;
            }
            int z=lca(x,y);
            LL res=0;
            for(auto it:seg[x]){
                if(d[go[it.x]]>=d[z]){
                    res+=query(it.y)-query(it.x-1);
                   // printf("%d %d\n",it.x,it.y);
                }
                else if(d[go[it.y]]>=d[z]){
                    res+=query(it.y)-query(in[z]-1);
                     //   printf("%d %d\n",in[z],it.y);
                }
            }
            for(auto it:seg[y]){
                 if(d[go[it.x]]>=d[z]){
                    res+=query(it.y)-query(it.x-1);
                //    printf("%d %d\n",it.x,it.y);
                }
                else if(d[go[it.y]]>=d[z]){
                    res+=query(it.y)-query(in[z]-1);
                      //  printf("%d %d\n",in[z],it.y);
                }
            }
            res-=a[z];
            
            res*=2;
            res-=a[x];
            res-=a[y];
            printf("%lld\n",res);
        }
    }
}
int main(){
    int t=1;//00;//00;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
 //   printf("0\n1\n2\n");
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
*/