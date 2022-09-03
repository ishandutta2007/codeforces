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
//pii p[1005];
void solve(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c);
    int cnt=0;
    int ans=0;
    char last=c[0];
    int tot=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]==last)tot++;
        else{
            last=c[i];
            int add=min(tot-1,cnt+1);
            ans+=add;
           
            if(tot==1)cnt++;
            else{
                 cnt-=add-1;
            }
            tot=1;
        }
   //     printf("%d %d %d %d\n",ans,tot,cnt);
    }
     int add=min(tot-1,cnt+1);
        ans+=add;
        
        if(tot==1)cnt++;
        else{
                cnt-=add-1;
        }
    ans+=(cnt+1)/2;
    printf("%d\n",ans);
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
    int t;
    scanf("%d",&t);
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