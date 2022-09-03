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
#define last Last
#define MXN 200005
void solve(){
    int n;
    scanf("%d",&n);
    int x[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&x[i]);
    }
    int y[200005];
    y[0]=0;
    for(int i = 1;i<n;i++){
        y[i]=0;
        for(int j = (x[i-1]^y[i-1]);j;j-=j&(-j)){
            int a=j&(-j);
            if(x[i]&a);
            else y[i]+=a;
        }
    }
    for(int i = 0;i<n;i++)printf("%d ",y[i]);
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}