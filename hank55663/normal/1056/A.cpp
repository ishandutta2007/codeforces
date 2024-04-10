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
#define LL unsigned long long 
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
int main(){
    int n;
    scanf("%d",&n);
    int cnt[100005];
    MEM(cnt);
    for(int i=0;i<n;i++){
        int r;
        scanf("%d",&r);
        while(r--){
            int x;
            scanf("%d",&x);
            cnt[x]++;
        }
    }
    for(int i=1;i<=100;i++){
        if(cnt[i]==n)
        printf("%d ",i);
    }
}