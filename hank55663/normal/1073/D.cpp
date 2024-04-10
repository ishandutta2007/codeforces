#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
LL S[1<<20];
LL S1[1<<20];
int Max=1<<20;
void add(LL *s,int x,int add){
    for(int i=x;i<Max;i+=i&-i){
        s[i]+=add;
    }
}
LL query(LL *s,int x){
    LL ret=0;
    for(int i=x;i>0;i-=i&-i)
        ret+=s[i];
    return ret;
}
LL query2(LL *s,LL need){
    LL sum=0,ret=0;
    for(int i=Max>>1;i>0;i>>=1){
        if(sum+s[ret+i]<=need){
            sum+=s[ret+i];
            ret+=i;
        }
    }
    return ret;
}
int main(){
    int n;
    LL t;
    scanf("%d %lld",&n,&t);
    int a[200005];
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        add(S,i,a[i]);
        add(S1,i,1);
    }
    LL ans=0,tot=0;
   // printf("?\n");
    while(t){
        LL x=query(S,n);
       // printf("%d\n",x);
        while(x>t){
            int re=query2(S,t);
            add(S,re+1,-a[re+1]);
            add(S1,re+1,-1);
            tot++;
            x=query(S,n);
        }
        if(tot==n)
        break;
        LL add=query(S1,n);
        ans+=t/x*add;
        t%=x;
       // printf("%d\n",ans);
    }
    printf("%lld\n",ans);
}
/*
21 3
3 1
4 1
5 1
6 2
7 2
8 2
1 2
9 1
9 10
9 11
9 12
10 13
10 14
10 15
11 16
11 17
11 18
12 19
12 20
12 21

*/