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
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[1000005];
    int cnt[26],cnt2[26];
    scanf("%s",c);
    MEM(cnt);
    MEM(cnt2);
    for(int i = 0;c[i]!=0;i++)cnt[c[i]-'a']++;
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++)cnt2[c[i]-'a']++;
    int ok=1;
    int sum=0;
    for(int i = 0;i<26;i++){
        if(cnt[i]%k!=cnt2[i]%k)ok=0;
        sum+=cnt[i];
        sum-=cnt2[i];
        if(sum<0)ok=0;
    }
    if(ok){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
}

int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}