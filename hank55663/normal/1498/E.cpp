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
    int n;
    scanf("%d",&n);
    pii k[505];
    for(int i = 1;i<=n;i++){
        scanf("%d",&k[i].x);
        k[i].y=i;
    }
    sort(k+1,k+n+1);
    for(int ans=n;ans>=0;ans--){
        for(int i = 1;i<=n;i++){
            for(int j = i+1;j<=n;j++){
                //if(k[j].x-k[i].x>ans)break;
                if(k[j].x-k[i].x==ans){
                    printf("? %d %d\n",k[j].y,k[i].y);
                    fflush(stdout);
                    int x;
                    char c[10];
                    scanf("%s",c);
                    if(c[0]=='Y'){
                        printf("! %d %d\n",k[j].y,k[i].y);
                        return;
                    }
                }
            }
        }
    }
    printf("! 0 0\n");

}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
}