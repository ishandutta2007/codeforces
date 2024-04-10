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
    int n,q;
    scanf("%d %d",&n,&q);
    int a[300005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    while(q--){
        int x;
        scanf("%d",&x);
        for(int i = 0;i<n;i++){
            if(a[i]==x){
                printf("%d ",i+1);
                for(int j =i-1;j>=0;j--){
                    swap(a[j],a[j+1]);
                }
                break;
            }
        }
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    //for(int i = 2)
    while(t--){
        solve();
    }
}