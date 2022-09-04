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
int a[100005];
int ans[100005];
int n;
int get(int x){
    if(ans[x]!=-1)
        return ans[x];
    ans[x]=0;
    for(int i=a[x];i<=n;i+=a[x]){
        int xx=x+i;
        if(xx<=n&&a[xx]>a[x]&&get(xx)==0){
            ans[x]=1;
            break;
        }
        xx=x-i;
        if(xx>0&&a[xx]>a[x]&&get(xx)==0){
            ans[x]=1;
            break;
        }
    }
    return ans[x];
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    MEMS(ans);
    for(int i=1;i<=n;i++){
        if(get(i))
        printf("A");
        else
        printf("B");
    }
    printf("\n");
}
/*
100
11
10
01

*/