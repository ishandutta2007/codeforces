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
void solve(){
    int n;
    scanf("%d",&n);
    int a[4];
    for(int i = 0;i<4;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<(1<<4);i++){
        for(int j = 0;j<4;j++){
            if(i&(1<<j)){
                a[j]--;
                a[(j+1)%4]--;
            }
        }
        int ok=1;
        for(int j =0;j<4;j++){
            if(a[j]>=0&&a[j]<=n-2){

            }
            else{
                ok=0;
            }
        }
        if(ok){
            printf("YES\n");
            return ;
        }
         for(int j = 0;j<4;j++){
            if(i&(1<<j)){
                a[j]++;
                a[(j+1)%4]++;
            }
        }
    }
    printf("NO\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/