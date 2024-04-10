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
using namespace std;
double val[15][15];
bool solve(){
    vector<int> v;
    int n,t;
    scanf("%d %d",&n,&t);
    val[0][0]=t;
    int cnt=0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(val[i][j]>=1){
                cnt++;
                val[i+1][j]+=(val[i][j]-1)/2;
                val[i+1][j+1]+=(val[i][j]-1)/2;
            }
        }
    }
    printf("%d\n",cnt);
}
int main(){
    int t=1;;//  scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}