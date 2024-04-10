#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define N 700005
vector<pii> v;
void dfs(int l,int r){
    if(l==r)return;
    int mid=(l+r)/2;
    dfs(l,mid);
    dfs(mid+1,r);
    int x=mid+1;
    for(int i = l;i<=mid;i++){
        v.pb(mp(i,x++));
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    //for(int i =0;i<x;i++)
    int x=1;
    while((x<<1)<=n)x<<=1;
    dfs(1,x);
    dfs(n-x+1,n);
    printf("%d\n",v.size());
    for(auto it:v){
        printf("%d %d\n",it.x,it.y);
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/