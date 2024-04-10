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
#define plus Plus
#define IOS ios_base::sync_with_stdio(0); cin.tie(0) 
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    pii p[300005];
    for(int i=0;i<n;i++)
        scanf("%d",&p[i].x);
    for(int i=0;i<n;i++)
        scanf("%d",&p[i].y);
    int x=0,y=0;
    for(int i=0;i<n;i++){
        int a=p[i].x,b=p[i].y;
        if(a>b){
            y=0;
            x=max(0ll,a-(k-x)-(LL)k*(b-1));
            if(x>k){
                printf("NO\n");
                return 0;
            }
        }
        else if(a==b){
            if(a==1){
                if(x==k)
                    x=1;
                if(y==k)
                    y=1;
            }
            else{
                if(k!=1){
                    x=0,y=0;
                }
            }
        }
        else{
            x=0;
            y=max(0ll,b-(k-y)-(LL)k*(a-1));
            if(y>k){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
}