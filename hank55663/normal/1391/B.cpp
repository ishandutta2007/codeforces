#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[105][105];
    for(int i = 0;i<n;i++)scanf("%s",c[i]);
    int cnt=0;
    for(int i = 0;i<n-1;i++){
        if(c[i][m-1]=='R')cnt++;
    }
    for(int i = 0;i<m-1;i++){
        if(c[n-1][i]=='D')cnt++;
    }
    printf("%d\n",cnt);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/