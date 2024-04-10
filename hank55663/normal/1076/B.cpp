/*#include<stdio.h>
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
#include<bitset>*/
#include<bits/stdc++.h>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
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
int main(){
    LL n;
    scanf("%lld",&n);
    if(n%2==0){
        printf("%lld\n",n/2);
        return 0;
    }
    for(LL i=3;i*i<=n;i++){
        if(n%i==0){
            printf("%lld\n",1+(n-i)/2);
            return 0;
        }
    }
    printf("1\n");
    return 0;
}