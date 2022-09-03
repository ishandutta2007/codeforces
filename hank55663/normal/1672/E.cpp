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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int ans=1e9;
//int query[2005];
int cnt;
int n;
map<int,int> m;
int qu(int w){
/*    cnt++;
    int tot=0;
    int now=query[0];
    if(query[0]>w)return 0;
    for(int i = 1;i<n;i++){
        if(now+1+query[i]>w)tot++,now=query[i];
        else now+=query[i]+1;
        if(query[i]>w)return 0;
    }*/
    if(m.find(w)!=m.end())return m[w];
    printf("? %d\n",w);
    fflush(stdout);
    int x;
    scanf("%d",&x);
    return m[w]=x;
}

void go(vector<int> v,int l,int r){
    if(v.empty())return;
    if(l==r){
        for(auto it:v){
            ans=min(ans,it*l);
        }
        return;
    }
    int mid=(l+r)/2;
  //  printf("? %d\n",mid);
    vector<int> x,y;
    fflush(stdout);
    int a=qu(mid);
   // scanf("%d",&a);
    if(a==0)y=v;
    else{
        for(auto it:v){
            if(it>=a)x.pb(it);
            else y.pb(it);
        }
    }
    if(y.empty())
    go(x,l,mid);
    else
    go(y,mid+1,r);
}
void solve(){
  //  int n;
    scanf("%d",&n);
    /*for(int i = 0;i<n;i++){
      //  scanf("%d",&query[i]);
       // query[i]=rand()%2000+1;
    }*/
    int Max=n*2000+2;
    int Min=1;
    vector<int> v;
    for(int i = 1;i<=n;i++)v.pb(i);
    go(v,Min,Max);
    int res=ans;
    int st=n;
   // printf("?%d\n",ans);
    for(int i = ans-n+1;i<=ans-1;i++){
     //   printf("???%d %d\n",i,st);
        for(int j = max(st,1);j<=n;j++){
            if(i%j==0){
                int a=qu(i/j);
              //  printf("%d %d\n",i/j,a);
                if(a==j){
                    res=i;
                    break;
                }
            }
        }
        st--;
        if(res==i)break;
    }
    printf("! %d\n",res);
   // printf("%d\n",cnt);
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
    //scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
*/