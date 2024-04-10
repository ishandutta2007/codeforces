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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
int S[500005];
int add(int x,int k,int n){
    for(int i = x;i<=n;i+=i&-i){
        S[i]=max(S[i],k);
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res=max(res,S[i]);
    }
    return res;
}
int dp[500005];
int dp2[500005];
bool solve(){
    int n=20;
  //  int val[500005];
  //  int p[500005];
    int a[500005];

    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        dp2[i]=0;
       // a[i]=rand()%n+1;
      //  printf("%d ",a[i]);
    }
    
  //  printf("\n");
    vector<pii> vv;
    vector<pii> v;
    for(int i = 1;i<=n;i++){
        while(v.size()&&v.back().x<=a[i])v.pop_back();
        if(v.size())vv.pb(mp(v.back().y,i));//printf("%d %d\n",v.back().y,i);
        v.pb(mp(a[i],i));
    }
    sort(vv.begin(),vv.end());
    queue<pii> q;
    for(auto it:vv)q.push(it);
    int ans=0;
    for(int i = 1;i<=n;i++){
        while(q.size()&&q.front().x==i){
            dp2[q.front().y]=query(a[q.front().y])+2;
            q.pop();
        }
        dp[i]=max(dp2[i],query(a[i])+1);
        add(a[i],dp[i],n);
        ans=max(ans,dp[i]);
     //   printf("%d ",dp[i]);
    }
  //  printf("\n");
    fill(S,S+n+1,0);
    /*LL ans=0;
    int now=v.size()-1;
    for(int i = n;i>=1;i--){
        if(p[i]==now){
            now--;
            ans+=val[i];
        }
    }*/
    printf("%d\n",ans);
   /* int ans2=0;
    for(int i = 0;i<(1<<n);i++){
        int last=-1,last2=-1;
        int ok=1;
        for(int j = 0;j<n;j++){
            if(i&(1<<j)){
                if(a[j+1]<min(last,last2))ok=0;
                last=last2;
                last2=a[j+1];
            }
        }
        if(ok){
            ans2=max(ans2,(int)__builtin_popcount(i));
        }
    }
    printf("%d\n",ans2);
    assert(ans==ans2);*/
    return true;
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/