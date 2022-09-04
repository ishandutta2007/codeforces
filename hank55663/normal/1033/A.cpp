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
    int map[1005][1005];
    MEM(map);
    int n;
    scanf("%d",&n);
    MEM(map);
    int x,y;
    scanf("%d %d",&x,&y);
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    a-=x;
    b-=y;
    c-=x;
    d-=y;
    if((a^c)>=0&&(b^d)>=0)
    printf("YES\n");
    else
    printf("NO\n");
}
/*
100
11
10
01

*/