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
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> h;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        h.pb(x);
    }
    vector<int> v;
    for(int i=0;i<m;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if(x==1){
            v.pb(y);
        }
    }
    sort(h.begin(),h.end());
    h.pb(1e9);
    sort(v.begin(),v.end());
    int ans=1e9;
    for(int i=0;i<h.size();i++){
        int x=lower_bound(v.begin(),v.end(),h[i])-v.begin();
        x=v.size()-x;
        ans=min(ans,x+i);
    }
    printf("%d\n",ans);
}