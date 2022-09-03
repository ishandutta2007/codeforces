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
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
queue<int> q[26];
int S[200005];
void add(int x,int k){
    for(int i = x;i<200005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
void solve(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c+1);
    for(int i = 1;i<=n;i++){
        q[c[i]-'a'].push(i);
    }
    reverse(c+1,c+n+1);
    LL ans=0;
    for(int i = 1;i<=n;i++)add(i,1);
    for(int i = 1;i<=n;i++){
       int x=q[c[i]-'a'].front();
       q[c[i]-'a'].pop();
       ans+=query(x-1);
       add(x,-1);
    }
    printf("%lld\n",ans);
}
int main(){
/*    for(int i = 0;i<=1000;i++){
        p[i]=mp(-1,-1);
    }
    for(int i = 0;i*5<=1000;i++){
        for(int j = 0;i*5+j*7<=1000;j++){
            p[i*5+j*7]=mp(i,j);
        }
    }*/
    int t=1;
  //  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*


*/
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