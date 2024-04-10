#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    pii p[2005];
    for(int i = 0;i<m;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        p[i]=mp(l,r);
    }
    int ans=0;
    for(int i = 1;i<=n;i++){
        int sum=0;
        int add[4005];
        MEM(add);
        int pp=0;
        for(int j=0;j<m;j++){
            if(p[j].x<=i){
                sum+=max(min(p[j].y-i+1,k),0);
            }
            else{
                int now=max(min(p[j].y,i+k-1)-p[j].x+1,0);
                sum+=now;
                //val[p[j].x]+=min(k,p[j].y-p[j].x+1)-now;
                int st=max(p[j].x-k+1,i+1);
                int en=max(p[j].y-k+2,i+1);
                add[st]++;
                add[max(p[j].x+1,i+1)]--;
                add[en]--;
                add[max(p[j].y+2-now,i+1)]++;
               // printf("? %d %d %d %d %d %d\n",p[j].x,p[j].y,st,max(p[j].x,i+1),en,max(p[j].y+1-now,i+1));
            }
        }
            ans=max(ans,sum);
        for(int j = i+1;j<=n;j++){
            pp+=add[j];
            sum+=pp;
            //printf("%d %d %d %d\n",i,j,sum,pp);
            ans=max(ans,sum);
        }
    }
    printf("%d\n",ans);
}

int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}