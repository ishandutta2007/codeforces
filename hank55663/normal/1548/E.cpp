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
const int mod=1e9+7;
int S[200005],S2[200005];
void add(int x,int k,int *S){
    for(int i = x;i<200005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x,int *S){
    if(x<=0)return 0;
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
void solve(){
    int n,m,X;
    scanf("%d %d %d",&n,&m,&X);
    int a[200005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    vector<pii> v;
    int lx[200005],rx[200005];
    MEM(lx);
    MEM(rx);
    for(int i = 1;i<=n;i++){
        while(v.size()&&v.back().x>a[i]){
            lx[i]=max(lx[i],v.back().x);
            lx[i]=max(lx[i],lx[v.back().y]);
            v.pop_back();
        }
        if(v.empty())lx[i]=1e9;
        v.pb(mp(a[i],i));
    }
    v.clear();
    for(int i = n;i>=1;i--){
        while(v.size()&&v.back().x>=a[i]){
            rx[i]=max(rx[i],v.back().x);
            rx[i]=max(rx[i],rx[v.back().y]);
            v.pop_back();
        }
        if(v.empty())rx[i]=1e9;
        v.pb(mp(a[i],i));
    }   
    v.clear();
    int b[200005];
    for(int i = 1;i<=m;i++)scanf("%d",&b[i]);
    int ly[200005],ry[200005];
    MEM(ly);
    MEM(ry);
    for(int i = 1;i<=m;i++){
        while(v.size()&&v.back().x>b[i]){
            ly[i]=max(ly[i],v.back().x);
            ly[i]=max(ly[i],ly[v.back().y]);
            v.pop_back();
        }
        if(v.empty())ly[i]=1e9;
        v.pb(mp(b[i],i));
       // printf("%d %d %d\n",ly[i],b[i],v.size());
    }
  //  printf("\n");
  v.clear();
    for(int i = m;i>=1;i--){
        while(v.size()&&v.back().x>=b[i]){
            ry[i]=max(ry[i],v.back().x);
            ry[i]=max(ry[i],ry[v.back().y]);
            v.pop_back();
        }
        if(v.empty())ry[i]=1e9;
        v.pb(mp(b[i],i));
       // printf("%d ",ry[i]);
    }
    v.clear();
   // printf("\n");
    vector<pair<pii,int> > vv;
    for(int i = 1;i<=n;i++){
        vv.pb(mp(mp(min(lx[i],rx[i])-a[i],a[i]),0));
    }
    for(int i = 1;i<=m;i++){
        vv.pb(mp(mp(min(ly[i],ry[i])-b[i],b[i]),1));
    }
 //   printf("??\n");
    sort(vv.begin(),vv.end());
    LL ans=0;
    reverse(vv.begin(),vv.end());
    for(auto it:vv){
          int ax=it.x.x+it.x.y;
         // printf("%d %d %d\n",ax,it.x.y,it.y);
        if(it.y==0){
            add(it.x.y,1,S);
            if(X-it.x.y>X-ax)
            ans+=query(X-it.x.y,S2)-query(X-ax,S2);
        }
        else{

         add(it.x.y,1,S2);
         if(X-it.x.y>X-ax)
         ans+=query(X-it.x.y,S)-query(X-ax,S);
        }
        // printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

a b c
b c
ab ac bc
5
4 3
1 4
4 2
3 4
0 0
*/