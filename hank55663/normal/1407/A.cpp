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
    int a[1005];
    int cnt[2]={0,0};
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    if(cnt[0]>=cnt[1]){
        vector<int> v;
        printf("%d\n",cnt[0]);
        for(int j=0;j<cnt[0];j++)printf("0 ");
    }
    else{
        printf("%d\n",cnt[1]-cnt[1]%2);
        for(int j =0;j<cnt[1]-cnt[1]%2;j++)printf("1 ");
    }
    printf("\n");
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