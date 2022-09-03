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
LL h[1000005];
LL S[1000005];
void add(int x,LL k){
    for(int i = x;i<1000005;i+=i&-i){
        S[i]+=k;
    }
}
LL query(int x){
    LL res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&h[i]);
    }
    add(1,h[1]);
    add(2,-h[1]);
    int last = 1;
    for(int i = 2;i<=n;i++){
       // printf("%d\n",i);
        LL k=h[i]-(query(i-1)+1);
        add(i,query(i-1)+1);
        add(i+1,-query(i-1)-1); 
        add(1,k/i);
        add(i+1,-k/i);
        k%=i;
        int remain=i-last+1;
     //   printf("? %d\n",last);
        if(k<remain){
            
            add(last,1);
            last+=k;
            add(last,-1);
            if(last==i+1)last=1;
        }
        else{
            add(last,1);
            add(i+1,-1);
            k-=remain;
            add(1,1);
            add(k+1,-1);
            last=k+1;
        }
       /* for(int i = 1;i<=n;i++){
         printf("%lld ",query(i));
        }
        printf("\n");*/
    }
 //   printf("?\n");
    for(int i = 1;i<=n;i++){
        printf("%lld ",query(i));
    }
    printf("\n");
    
}
int main(){
    int t=1;
    //scanf("%d",&t);
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