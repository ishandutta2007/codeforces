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
int main(){
    vector<int> v;
    int n;
    scanf("%d",&n);
    char c[100005];
    scanf("%s",c);
    int cnt=0;
    int tot=0;
    for(int i=0;c[i]!=0;i++){
        if(c[i]=='G'){
            cnt++;
            tot++;
        }
        else{
            v.pb(cnt);
            cnt=0;
        }
    }
    v.pb(cnt);
    v.pb(0);
    int ans=0;
    for(int i=0;i<v.size()-1;i++){
        ans=max(ans,v[i]+v[i+1]+1);
    }
    ans=min(ans,tot);
    printf("%d\n",ans);
}