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
#define index Index
#define MXN 10000
int a[55];
int b[55];
void solve(){
    pii p[105];
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        p[i].x=x;
    }
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        p[i].y=x;
    }
    vector<pii> v;
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(p[j]<p[i]){
                v.pb(mp(i+1,j+1));
                swap(p[j],p[i]);
            }
        }
    }
    for(int i=0;i<n-1;i++){
        if(p[i].y>p[i+1].y){
            printf("-1\n");
            return;
        }
    }
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d %d\n",it.x,it.y);
    }
}
int main(){
   // srand(time(NULL));
    int t=10000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}