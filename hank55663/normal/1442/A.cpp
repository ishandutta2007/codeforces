#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){   
    int n;
    scanf("%d",&n);
    int a[30005];
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int last=a[0];
   // int ok=1;
    int cnt=0;
    a[0]=0;
    int ok=1;
    for(int i = 1;i<n;i++){
        last=min(last,a[i]-a[i-1]);
        if(last<0)ok=0;
        a[i]-=last;
       // printf("%d ",a[i]);
    }
/*
    for(int i = 0;i<n-1;i++){
        if(a[i]>a[i+1])ok=0;
    }*/
    if(ok)printf("YES\n");
    else printf("NO\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}


/*
11 4 12
1 1 1 1
AABB
.AB.
CCDD
.CD.
EEFF
.EF.
GGHH
.GH.
IIJJ
.IJ.
KKLL

12
0 0
0 -13
3 -13
3 -10
10 -10
10 10
-1 10
-1 13
-4 13
-4 10
-10 10
-10 0

*/