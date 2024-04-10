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
    char c[200005];
    scanf("%s",c);
    vector<char> v;
    int cnt=0;
    int cnt1=0,cnt2=0;;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='(')cnt1++;
        if(c[i]=='[')cnt2++;
        if(c[i]==')'&&cnt1)cnt++,cnt1--;
        if(c[i]==']'&&cnt2)cnt++,cnt2--;
    }
    printf("%d\n",cnt);
}

int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}