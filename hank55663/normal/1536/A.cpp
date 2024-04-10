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
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    int a[105];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);   
    }
    sort(a,a+n);
    if(a[0]<0)printf("NO\n");
    else {
        printf("YES\n");
       /* printf("%d\n",n+101);
        for(int i = 0;i<n;i++)printf(" %d",a[i]);
      */
     printf("101\n");
        for(int i = 0;i<=100;i++){
            printf(" %d",i);
        }
        printf("\n");
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