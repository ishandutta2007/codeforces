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
static const double INF = 2147483647;
void solve(){
    int n;
    scanf("%d",&n);
    LL sum=0;
    int b[200005];
    map<LL,int> m;
    for(int i = 0;i<n+2;i++){
        scanf("%d",&b[i]);
        sum+=b[i];
        m[b[i]]++;
    }
    for(int i = 0;i<n+2;i++){
        m[b[i]]--;
        if(m[sum-b[i]*2]){
            int vis=0;
            for(int j = 0;j<n+2;j++){
                if(j==i);
                else if(!vis&&b[j]==sum-b[i]*2){
                    vis=1;
                }
                else if(j==i);
                else{
                    printf("%d ",b[j]);
                }
            }
            printf("\n");
            return;
        }
        m[b[i]]++;
    }
    printf("-1\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
*/