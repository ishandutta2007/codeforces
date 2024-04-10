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
    int n,m;
    scanf("%d %d",&n,&m);
    int Max=0;
    int ans[100005];
    for(int i=0;i<n;i++){
        scanf("%d",&ans[i]);
    }
    sort(ans,ans+n);
    LL res=0;
    int need=ans[n-1];
    for(int i=n-1;i>=0;i--){
        if(ans[i]==0)
        break;
        if(ans[i]>=need){
            res+=max(ans[i]-1,0);
        }
        else{
            res+=max(ans[i]-1,0);
            res-=need-ans[i];
            need=ans[i];
        }
        //printf("%d\n",res);
        need--;
    }
    if(need>0)
    res-=need;
    printf("%lld\n",res);
}