#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define N 700005
void solve(){
    int n;
    scanf("%d",&n);
    int a[3][105];
    for(int t=0;t<3;t++){
        for(int i = 0;i<n;i++)
            scanf("%d",&a[t][i]);
    }
    int ans[105];
    fill(ans,ans+n+1,-1);
    for(int i = 0;i<n;i++){
        for(int j=0;j<3;j++){
            if((i==0||a[j][i]!=ans[i-1])&&(a[j][i]!=ans[(i+1)%n])){
                ans[i]=a[j][i];
                break;
            }
        }
        printf("%d ",ans[i]);
    }
    printf("\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/