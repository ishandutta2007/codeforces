#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#include<iostream>
#include<cmath>
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
//#define pii pair<int,int> 
#define N 100
bool isprime[N];
void Find(){
    fill(isprime,isprime+N,1);
    for(int i=2;i<N;i++){
        if(isprime[i]){
            for(int j=i*2;j<N;j+=i){
                isprime[j]=0;
            }
        }
    }
}
pll gcd(LL a, LL b){
    if(b == 0) return mp(1, 0);
    else{
        LL p = a / b;
        pll q = gcd(b, a % b);
        return make_pair(q.y, q.x - q.y * p);
    }
}
int mod=1000;
LL f_pow(int a,int b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    map<int,int> m;
    int n,k;
    scanf("%d %d",&n,&k);
    int xd= (1<<k)-1;
    //printf("%d",xd);
    int now=0;
    m[now]++;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        now^=a;
        if(m.find(now^xd)!=m.end())
        m[now^xd]++;
        else
        m[now]++;
    }
    LL ans=(LL)n*(n+1)/2;
    for(auto it:m){
        LL a=it.y/2,b=it.y-a;
        ans-=a*(a-1)/2;
        ans-=b*(b-1)/2;
    }
    printf("%lld\n",ans);
}