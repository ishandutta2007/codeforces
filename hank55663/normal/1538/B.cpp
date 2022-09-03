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
const int mod=1e9+7;
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    int sum=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum%n!=0){
        printf("-1\n");
    }
    else{
        sum/=n;
        int ans=0;
        for(int i = 1;i<=n;i++){
            if(a[i]>sum)ans++;
        }
        printf("%d\n",ans);
    }
 
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/