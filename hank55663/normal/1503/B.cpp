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
const int mod=1e9+7;

void solve(){
    int a[105][105];
    int n;
    scanf("%d",&n);
    queue<pii> q[2];
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            q[(i+j)%2].push(mp(i,j));
        }
    }
    for(int i = 0;i<n*n;i++){
        int a;
        scanf("%d",&a);
        if(a!=1){
            if(q[0].size()){
                pii p=q[0].front();
                q[0].pop();
                printf("1 %d %d\n",p.x,p.y);
            }
            else{
                pii p=q[1].front();
                q[1].pop();
                printf("%d %d %d\n",5-a,p.x,p.y);
            }
        }
        else if(a!=2){
            if(q[1].size()){
                pii p=q[1].front();
                q[1].pop();
                printf("2 %d %d\n",p.x,p.y);
            }
            else{
                pii p=q[0].front();
                q[0].pop();
                printf("%d %d %d\n",4-a,p.x,p.y);
            }
        }
        fflush(stdout);
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}