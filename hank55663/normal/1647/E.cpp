#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
#define MXN 2005
int go[100005][40];
void solve(){
    int n;
    scanf("%d",&n);
    int p[100005],a[100005];
    int Max=0;
    set<int> s;
    for(int i = 0;i<n;i++){
        scanf("%d",&p[i]),s.insert(p[i]);
        p[i]--;
    }
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]),Max=max(Max,a[i]);
        a[i]--;
    }
    int round=(Max-n)/(n-s.size());
    if(round==0){
        for(int i=0;i<n;i++)printf("%d ",a[i]+1);
        printf("\n");
    }
    else{
        set<int> s;
        for(int i = 0;i<n;i++){
            go[i][0]=p[i];
        }
        for(int i = 1;i<40;i++){
            for(int j = 0;j<n;j++){
                go[j][i]=go[go[j][i-1]][i-1];
            }
        }
        int val[100005];
        for(int i = 0;i<n;i++){
            int now=i;
            for(int j = 0;j<30;j++){
                if(round&(1<<j)){
                    now=go[now][j];  
                }
            }
            val[i]=now;
        //    printf("%d ",now);
        }
      //  printf("%d\n",round);
        int vis[100005];
        for(int i = 0;i<n;i++)vis[i]=0,s.insert(i);
        int ans[100005];
      //  for(int i = 0;i<n;i++)printf("%d ",a[i]);
      //  printf("\n");
        for(int i = 0;i<n;i++){
            if(!vis[val[i]]){
                vis[val[i]]=1;
                ans[i]=a[val[i]];
             //   printf("%d %d %d\n",i,val[i],a[val[i]]);
                s.erase(ans[i]);
            }
            else{
                ans[i]=-1;
            }
        }
        for(int i = 0;i<n;i++){
            if(ans[i]==-1){
                auto it=*s.lower_bound(a[val[i]]);
                ans[i]=it;
                s.erase(it);
            }
        }
        for(int i = 0;i<n;i++){
            printf("%d ",ans[i]+1);
        }
        printf("\n");
    }
}
int main(){
    int t=1;0000;
    //  scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
*/