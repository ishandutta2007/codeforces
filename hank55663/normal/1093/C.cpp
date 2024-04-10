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
    int n;
    scanf("%d",&n);
    LL b[200005];
    for(int i=0;i<n/2;i++){
        scanf("%lld",&b[i]);
    }
    vector<LL> v;
    v.pb(1e18+1);
    LL last=0;
    for(int i=0;i<n/2;i++){
        LL ans=min(b[i]-last,v.back());
        v.pb(ans);
        printf("%lld ",b[i]-ans);
        last=b[i]-ans;
    }
    reverse(v.begin(),v.end());
    v.pop_back();
    for(auto it:v)
    printf("%lld ",it);
    printf("\n");
}
/*
0 1 0
0 0 1
1 0 1
*/