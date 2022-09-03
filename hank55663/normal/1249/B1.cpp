#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int a[200005];
int vis[200005];
vector<int> stk;
int ans[200005];
int go(int x,int st){
    vis[x]=1;
    stk.pb(x);
    if(x==st)return 1;
    //vis[x]=1;
    return go(a[x],st)+1;
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        fill(vis,vis+n+1,0);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
       // LL lcm=1;
        for(int i = 1;i<=n;i++){
            if(!vis[i]){
                LL x=go(a[i],i);
                for(auto it:stk)ans[it]=x;
                stk.clear();
                //LL x=go(a[i],i);
                //lcm=lcm*x/__gcd(lcm,x);
            }
        }
        for(int i = 1;i<=n;i++)
        printf("%d ",ans[i]);
        printf("\n");
    } 

}