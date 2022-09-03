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
    int arr[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int ans=2*n-1;
    for(int i = 2;i<n;i++){
        for(int k = 3;k<=5&&i-k+1>=0;k++){
            int ok=1;
            for(int a=i-k+1;a<=i;a++){
                for(int b=a+1;b<=i;b++){
                    for(int c=b+1;c<=i;c++){
                        if(arr[a]<=arr[b]&&arr[b]<=arr[c])ok=0;
                         if(arr[a]>=arr[b]&&arr[b]>=arr[c])ok=0;
                    }
                }
            }
            ans+=ok;
        }
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}