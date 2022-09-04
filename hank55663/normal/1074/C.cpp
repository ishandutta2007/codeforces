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
    int n;
    scanf("%d",&n);
    int minx=1e9,maxx=-1e9,miny=1e9,maxy=-1e9;
    vector<pii> p;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p.pb(mp(x,y));
        minx=min(x,minx);
        miny=min(y,miny);
        maxx=max(x,maxx);
        maxy=max(y,maxy);
    }
    int ans=0;
    for(int i=0;i<p.size();i++){
        int x=max(p[i].x-minx,maxx-p[i].x);
        int y=max(p[i].y-miny,maxy-p[i].y);
        ans=max(ans,(x+y)<<1);
    }
    printf("%d",ans);
    for(int i=4;i<=n;i++){
        printf(" %d",(maxx-minx+maxy-miny)<<1);
    }
    printf("\n");
}