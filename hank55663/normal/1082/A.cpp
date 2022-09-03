#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>
#define LL long long 
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define cpdd const pdd
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define Line pll
#define EPS 1e-12
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x,y,d;
        scanf("%d %d %d %d",&n,&x,&y,&d);
        int ans=2e9;
        if(abs(y-x)%d==0){
            ans=min(ans,abs(y-x)/d);
        }
        if((y-1)%d==0){
            ans=min(ans,(y-1)/d+(x-1)/d+((x-1)%d!=0));
        }
        if((n-y)%d==0){
            ans=min(ans,(n-y)/d+(n-x)/d+((n-x)%d!=0));
        }
        if(ans==2e9)ans=-1;
        printf("%d\n",ans);
    }
}