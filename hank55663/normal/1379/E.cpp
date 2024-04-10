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
int now=0;
int p[100005];
int buildbinary(int dep){
    now++;
    if(dep==1)return now;
    int node=now;
    p[buildbinary(dep-1)]=node;
    p[buildbinary(dep-1)]=node;
    return node;
}
bool dfs(int x,int need,int &val){
    if(need<0)return false;
    if(__builtin_popcount(x+1)==1&&need==1)return false;
    if(__builtin_popcount(x+1)==1&&need==0){
        val = buildbinary(__builtin_popcount(x));
        return true;
    }
    x--;
    for(int i = 1;(1<<i)-1<x;i++){
        int l=(1<<i)-1;
        int r=x-l;
        if(l*2<r||r*2<l){
            int a;
            int last=now;
            if(dfs(r,need-1,a)){
            //    printf("%d\n",a);
                int b=buildbinary(i);
                now++;
                p[a]=now;
                p[b]=now;
                val=now;
                return true;
            }
            now=last;
        }
        else{
            int a;
            int last=now;
            if(dfs(r,need,a)){    
                int b=buildbinary(i);
                now++;
                p[a]=now;
                p[b]=now;
                val=now;
                return true;
            }
            now=last;
        }
    }
    return false;
}
void solve(){
    int n,need;
    scanf("%d %d",&n,&need);
    if(n%2==0){
        printf("NO\n");
    }
    else{
        if(need==0){
            if(__builtin_popcount(n+1)==1){
                printf("YES\n");
                for(int i = 1;i<=n;i++){
                    printf("%d ",i/2);
                }
                printf("\n");
            }
            else{
                printf("NO\n");
            }
            return ;
        }
        else if((n-3)/2<need){
            printf("NO\n");
        }
        else{
            int root;
           if(dfs(n,need,root)){
               p[root]=0;
               printf("YES\n");
               for(int i = 1;i<=n;i++){
                   printf("%d ",p[i]);
               }
               printf("\n");
           }
           else{
               printf("NO\n");
           }
        }
    }
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