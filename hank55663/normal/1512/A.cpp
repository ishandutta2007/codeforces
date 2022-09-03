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
    int a[105];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 1;i<n-1;i++){
        if(a[i]!=a[i-1]&&a[i]!=a[i+1]){
            printf("%d\n",i+1);
            return;
        }
    }
    if(a[0]!=a[1])printf("%d\n",1);
    else printf("%d\n",n);
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
3 3 3 4 4 4 5 5 5 6 6 6 7
5 5 5 5 5 6 6 6 6 6 7 7 7

3 3 4 4 5 5 6 6 7 7 8
5 5 5 6 6 6 7 7 7 8 8 

3 3 4 4 5 5 6
5 5 5 5 5 5 5 

1 1 6
0 -3 -3

0 0 5
1 -2 -2
-2 -2 3
3 0 0
1 1
1 2 1
1 3 2 3 1
1 4 3 5 2 5 3 4 1
1 5 4 7 3 8 5 7 2 7 5 8 3 7 4 5 1
*/