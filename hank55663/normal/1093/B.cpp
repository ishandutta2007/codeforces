/*#include<utility>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<iostream>
#include<string.h>*/
#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
using namespace std;
typedef long long LL;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        char c[10005];
        scanf("%s",c);
        int len=strlen(c);
        sort(c,c+len);
        if(c[0]==c[len-1]){
            printf("-1\n");
        }
        else{
            printf("%s\n",c);
        }
    }
}
/*
0 1 0
0 0 1
1 0 1
*/