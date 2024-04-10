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
    int n,k;
    scanf("%d %d",&n,&k);
    int a[105];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    int cnt=0;
    for(int i = 1;i<n;i++){
        if(a[i]!=a[i-1])cnt++;
    }
    if(k==1){
        if(cnt){
            printf("-1\n");
        }
        else{
            printf("1\n");
        }
    }
    else{
        printf("%d\n",max((cnt+k-2)/(k-1),1));
    }
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