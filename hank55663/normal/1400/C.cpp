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
    char s[100005];
    int x;
    scanf("%s %d",s,&x);
    char w[100005];
    for(int i = 0;s[i]!=0;i++)w[i]='1',w[i+1]=0;
    int n=strlen(s);
    for(int i = 0;i<n;i++){
        if(s[i]=='0'){
            if(i>=x)w[i-x]='0';
            if(i+x<n)w[i+x]='0';
        }
    }
    for(int i = 0;s[i]!=0;i++){
        if(s[i]=='1'){
            int ok=0;
            if(i>=x&&w[i-x]=='1')ok=1;
            if(i+x<n&&w[i+x]=='1')ok=1;
            if(!ok){
                printf("-1\n");
                return ;
            }
        }
    }
    printf("%s\n",w);
}
int main(){
    int t=1;
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