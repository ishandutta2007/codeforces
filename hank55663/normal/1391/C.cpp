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
    int n;
    scanf("%d",&n);
    LL res=1;
    int mod=1e9+7;
    for(int i = 1;i<=n;i++)res=res*i%mod;
    LL tmp=1;
    for(int i = 1;i<n;i++)tmp=tmp*2%mod;
    printf("%lld\n",((res-tmp)%mod+mod)%mod);
}
int main(){
    int t=1;
   // scanf("%d",&t);
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