#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
void solve(){
    int n;
    char s[1000005],t[1000005];
    scanf("%d %s %s",&n,s,t);
    vector<int> v;
    int tot=0;
    for(int i = 0;s[i]!=0;i++){
        if(s[i]!=t[i]){
            if(s[i]=='0')tot++,v.pb(0);
            else tot--,v.pb(1);
        }
    }
    if(v.empty()){
        printf("0\n");
        return ;
    }
    if(tot){
        printf("-1\n");
        return ;
    }
    if(v[0]==v.back()){
        int cnt=0;
        while(v.back()==v[0])cnt++,v.pop_back();
        reverse(v.begin(),v.end());
        while(cnt--)v.pb(v.back());
        reverse(v.begin(),v.end());
    }
    int ans=0;
    int cnt[2]={0,0};///,last=0;
    for(auto it:v){
        if(cnt[it^1])cnt[it^1]--,cnt[it]++;
        else{
            cnt[it]++;
            ans++;
        }
    }
    
    printf("%d\n",ans);
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