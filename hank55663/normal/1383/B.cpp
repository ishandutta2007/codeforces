#include<bits/stdc++.h>
/*#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 30;i>=0;i--){
        int z=0,o=0;
        for(int j = 0;j<n;j++){
            if(a[j]&(1<<i))o++;
            else z++;
        }
        if(o%2){
            if((o/2+1)&1)printf("WIN\n");
            else if(z%2)printf("WIN\n");
            else printf("LOSE\n");
            return ;
        }
    }
    printf("DRAW\n");
}
int main(){
    int t;
    scanf("%d",&t);
    //Find();
    while(t--){
        solve();
    }
}