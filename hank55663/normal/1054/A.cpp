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
    int x,y,z,t1,t2,t3;
    scanf("%d %d %d %d %d %d",&x,&y,&z,&t1,&t2,&t3);
    int st=abs(x-y)*t1;
    int ev=(abs(z-x)+abs(x-y))*t2+t3+t3+t3;
    //printf("%d %d\n",st,ev);
    if(st<ev)
    printf("NO\n");
    else
    printf("YES\n");
}