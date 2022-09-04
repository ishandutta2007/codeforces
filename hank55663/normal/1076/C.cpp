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
    int t;
    scanf("%d",&t);
    while(t--){
        int d;
        scanf("%d",&d);
        if(d*d-4*d<0){
            printf("N\n");
        }
        else if(d-sqrt(d*d-4*d)<-1e-6){
            printf("N\n");
        }
        else{
            printf("Y %.12lf %.12lf\n",(d+sqrt(d*d-4*d))/2,abs(d-sqrt(d*d-4*d))/2);
        }
    }
    return 0;
}