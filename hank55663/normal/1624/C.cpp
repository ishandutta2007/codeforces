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
void solve(){
    int n;
    scanf("%d",&n);
    int a[55];
    int vis[55];
    MEM(vis);
    int ok=1;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        while(a[i]>n||vis[a[i]]){
            a[i]=a[i]/2;
        }
        if(a[i]==0){
            ok=0;
        }
        else{
            vis[a[i]]=1;
        }
    }
    if(ok)printf("YES\n");
    else printf("NO\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}