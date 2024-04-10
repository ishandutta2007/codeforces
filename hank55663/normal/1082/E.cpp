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
#define EPS 1e-12
vector<int> v[500005];
int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    int a[500005];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        v[a[i]].pb(i);
    }
    int pre[500005],suf[500005];
    MEM(pre);MEM(suf);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1];
        if(a[i]==c)
        pre[i]++;
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1];
        if(a[i]==c)
        suf[i]++;
    }
    int ans=0;
    for(int i=1;i<=500000;i++){
        int Max=0;
        for(auto it:v[i]){
            Max++;
            Max=max(Max,pre[it-1]+1);
            ans=max(ans,Max+suf[it+1]);
        }
    }
    printf("%d\n",ans);
}