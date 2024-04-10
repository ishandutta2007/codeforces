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
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    int vis[200005];
    MEM(vis);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        v.pb(x);
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        int cnt=0;
        while(!vis[x]){
            vis[v.back()]=1;
            v.pop_back();
            cnt++;
        }
        printf("%d ",cnt);
    }
}
/*
21 3
3 1
4 1
5 1
6 2
7 2
8 2
1 2
9 1
9 10
9 11
9 12
10 13
10 14
10 15
11 16
11 17
11 18
12 19
12 20
12 21

*/