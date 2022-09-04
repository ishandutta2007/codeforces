#include<vector>
#include<stdio.h>
#include<utility>
#include<set>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<queue>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define MAXN 505
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL a,b;
        scanf("%lld %lld",&a,&b);
        if(a-b!=1){
            printf("NO\n");
        }
        else{
            int ok=1;
            for(LL i=2;i*i<=a+b;i++){
                if((a+b)%i==0){
                    ok=0;
                }
            }
            if(ok)
            printf("YES\n");
            else
            printf("NO\n");
        }
    }
}
/*
100
11
10
01

*/