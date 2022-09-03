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
int Size[200005];
vector<pii> v[200005];
int forbid[200005];
vector<int> tmp;
void dfs(int x,int f){
    Size[x]=1;
    tmp.pb(x);
    for(auto it:v[x]){
        if(it.x!=f&&!forbid[it.x]){
            dfs(it.x,x);
            Size[x]+=Size[it.x];
        }
    }
    
}
int cen(int x){
    tmp.clear();
    dfs(x,0);
    int xx=Size[x];
    int res=0;
    for(auto it:tmp){
        if(Size[it]>=(xx+1)/2){
            res=it;
        }
    }
    return res;
}
LL S[4][200005];
const int mod=1e9+7;
void add(int x,int k,LL *s){
    x++;
    for(int i=x;i<200005;i+=i&-i){
        s[i]+=k;
        s[i]%=mod;
    }
}
void reset(int x,LL *s){
    x++;
    for(int i=x;i<200005;i+=i&-i){
        s[i]=0;
    }
}
LL query(int x,LL *s){
    x++;
    LL res=0;
    for(int i=x;i>0;i-=i&-i){
        res+=s[i];
        res%=mod;
    }
    return res;
}
vector<pll> vv;
LL a[200005];
void dfs(int x,int last,int f,int sum,LL sum2){
    vv.pb(mp(a[x]+sum2,sum));
    for(auto it:v[x]){
        if(it.x!=f&&!forbid[it.x]){
            dfs(it.x,it.y,x,sum+(it.y!=last),(sum2+a[x])%mod);
        }
    }
}
LL ans=0;
int k;
vector<pii> ttmp;
void go(int x){
     x=cen(x);
    // printf("cen %d\n",x);
    for(auto it:v[x]){
        if(!forbid[it.x]){
            dfs(it.x,it.y,x,0,a[x]);
            for(auto it2:vv){
                ans+=query(k-it2.y,S[it.y]);
              
                ans+=query(k-it2.y,S[2+it.y])*it2.x%mod;
                ans+=query(k-it2.y-1,S[it.y^1]);
                 ans+=query(k-it2.y-1,S[2+(it.y^1)])*it2.x%mod;
                if(it2.y<=k)ans+=it2.x;//printf("??%lld\n",ans);
                ans%=mod;
            }
            for(auto it2:vv){
                add(it2.y,it2.x-a[x],S[it.y]);
                add(it2.y,1,S[2+it.y]);
                ttmp.pb(it2);
             //   printf("%d %d %d\n",it2.x,it2.y,it.y);
            }
          //  printf("\n");
            vv.clear();
        }
          //  printf("%lld\n",ans);
    }
  //  printf("%lld\n",ans);
    for(auto it:ttmp){
        reset(it.y,S[0]);
        reset(it.y,S[1]);
        reset(it.y,S[2]);
        reset(it.y,S[3]);
    }
    ttmp.clear();
    forbid[x]=1;
    for(auto it:v[x]){
        if(!forbid[it.x]){
            go(it.x);
        }
    }
}
void solve(){
    int n;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++)scanf("%lld",&a[i]),ans+=a[i];
    for(int i = 1;i<n;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        v[x].pb(mp(y,w));
        v[y].pb(mp(x,w));
    }
    go(1);
    printf("%lld\n",(ans%mod+mod)%mod);
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