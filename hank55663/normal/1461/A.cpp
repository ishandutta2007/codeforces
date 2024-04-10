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
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;i++){
        printf("%c",i%3+'a');
    }
    printf("\n");
}
int main(){
    int t=1;   scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}