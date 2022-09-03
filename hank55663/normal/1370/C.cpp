#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
    if(n==1){
        printf("FastestFinger\n");
    }
    else if(n%2==1){
        printf("Ashishgup\n");
    }
    else if(n==2){
        printf("Ashishgup\n");
    }
    else{
        int cnt=0;
        while(n%2==0)
        n/=2,cnt++;
        if(cnt==1){
            cnt=0;
            for(int i = 2;i*i<=n;i++){
                while(n%i==0){
                    cnt++;
                    n/=i;
                }
            }
            if(n!=1)cnt++;
            if(cnt>=2) printf("Ashishgup\n");
            else printf("FastestFinger\n");
        }
        else{
            if(n!=1){
                 printf("Ashishgup\n");
            }
            else{
                printf("FastestFinger\n");
            }
        }
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