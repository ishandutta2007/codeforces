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
void solve(){
    int n;
    scanf("%d",&n);
    char c[1005];
    scanf("%s",c);
    int num[2][2];//,even[2];
    MEM(num);
    for(int i = 0;c[i]!=0;i++){
        num[(i+1)&1][(c[i]-'0')&1]++;
    }
    if(n%2==0){
        if(num[0][0])printf("2\n");
        else printf("1\n");
    }
    if(n%2==1){
        if(num[1][1])printf("1\n");
        else printf("2\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/