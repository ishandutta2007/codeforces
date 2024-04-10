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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
#define MXN 10000
int a[55];
int b[55];
void solve(){
    int n;
    scanf("%d",&n);
    //MEM(dp);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);

    for(int i =0;i<m;i++){
        scanf("%d",&b[i]);
    }
    sort(a,a+n);
    sort(b,b+m);
    if(b[m-1]>a[n-1])printf("Bob\n");
    else printf("Alice\n");
    
    if(b[m-1]<a[n-1])printf("Alice\n");
    else printf("Bob\n");
}
int main(){
   // srand(time(NULL));
    int t=10000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}