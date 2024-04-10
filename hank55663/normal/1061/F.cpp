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
LL mod=1e9+7;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int dep=1;
    int now=1;
    while(now!=n){
        now=now*k+1;
        dep++;
    }
    //printf("%d\")
    srand(time(NULL));
    int x,y;
    vector<int> v;
    while(1){
        x=rand()%n+1,y=rand()%n+1;
        while(y==x)
        y=rand()%n+1;
        for(int i=1;i<=n;i++){
            printf("? %d %d %d\n",x,i,y);
            fflush(stdout);
            char c[105];
            scanf("%s",c);
            if(c[0]=='Y')
            v.pb(i);
        }
        if(v.size()==dep*2-1){
            break;
        }
        v.clear();
    }
 //   printf("!\n");
    random_shuffle(v.begin(),v.end());
    for(auto it:v){
        int cnt=0;
        for(int i=1;i<=n;i++){
            printf("? %d %d %d\n",x,i,it);
            fflush(stdout);
            char c[105];
            scanf("%s",c);
            if(c[0]=='Y')
            cnt++;
        }
        if(cnt==dep){
            printf("! %d\n",it);
            break;
        }
    }
    fflush(stdout);
}