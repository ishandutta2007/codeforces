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
using namespace std;
#define MXN 100005
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[105],b[105];
    int vis[1005];
    fill(vis,vis+1000,0);
    for(int i= 0;i<n;i++){
        scanf("%d",&a[i]);
        vis[a[i]]++;
    }
    int sum=0;
    for(int i = 0;i<m;i++){
        scanf("%d",&b[i]);
        if(vis[b[i]]){
            sum++;
          //  printf("%d\n",b[i]);
        }
    }
    printf("%d\n",sum);

}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
       solve();
    }
}
/*
*/