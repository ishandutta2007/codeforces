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
void solve(){
    int n;
    scanf("%d",&n);
    char c[500005];
    scanf("%s",c);
    int rank[500005];
    for(int i = 0;c[i]!=0;i++){
        rank[i]=c[i];
    }
    for(int t =0;t<n;t++){
        vector<pair<pii,int> > v;
        for(int i = 0;c[i]!=0;i++){
            v.pb(mp(mp(rank[i],rank[i^(1<<t)]),i));
        }
        sort(v.begin(),v.end());
        int now=0;
        rank[v[0].y]=now;
        for(int i = 1;i<v.size();i++){
            if(v[i].x!=v[i-1].x){
                now++;
            }
            rank[v[i].y]=now;
        }
      //  for(int i = 0;i<(1<<n);i++)printf("%d ",rank[i]);
      //  printf("\n");
    }
    for(int i = 0;i<(1<<n);i++){
        if(rank[i]==0){
            //printf("%d\n",i);
            char ans[500005];
            ans[(1<<n)]=0;
            for(int j = 0;j<(1<<n);j++)ans[j^i]=c[j];//printf("%d",j^i);
            printf("%s\n",ans);
            return;
        }
    }
}


int main(){
    int t=1;
  //scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/