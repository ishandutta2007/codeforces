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
const int mod=1e9+7;
#define MXN 2005
int ook[2000005];
int vis[2000005];
void solve(){
    int n,c;
    scanf("%d %d",&n,&c);
    fill(ook,ook+c+1,0);
        fill(vis,vis+c+1,0);
    int a[1000005];
    set<int> s;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        vis[a[i]]=1;
    }
    sort(a,a+n);
    for(int i = 0;i<n;i++){
        if(i==0||a[i]!=a[i-1]){
            for(int j = 1;j*a[i]<=c;j++){
                if(!vis[j]){
                    ook[j*a[i]]++;
                    if((j+1)*a[i]<=c)ook[(j+1)*a[i]]--;
                }
            }
        }
    }
    LL sum=0;
    for(int i = 1;i<=c;i++){
        sum+=ook[i];
        if(sum&&vis[i]){
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
}
int main(){
    int t=1;0000;
      scanf("%d",&t);
   //  while(solve());
     
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}