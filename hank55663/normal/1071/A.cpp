#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
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
#define N 1000005
int isprime[N];
vector<int> prime;
void Find(){
    fill(isprime,isprime+N,0);
    for(int i=2;i<N;i++){
        if(!isprime[i]){
            prime.pb(i);
            for(int j=i;j<N;j+=i){
                isprime[j]=i;
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
bool check(int x){
    for(auto it:prime){
        if(it*it>x){
            break;
        }
        if(x%it==0){
            return false;
        }
    }
    return true;
}
vector<int> factor[4000005];
int inv[4000005];
LL ans[4000005];
int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int sum=a+b;
    LL Max=1e5,Min=0;
    while(Max>Min+1){
        LL mid=(Max+Min)/2;
        if(mid*(mid+1)/2>sum){
            Max=mid;
        }
        else{
            Min=mid;
        }
    }
    vector<int> v,v1;
    for(int i=Min;i>=1;i--){
        if(b>=i){
            v1.pb(i);
            b-=i;
        }
        else{
            v.pb(i);
        }
    }
    printf("%d\n",v.size());
    for(auto it:v)
    printf("%d ",it);
    printf("\n%d\n",v1.size());
    for(auto it:v1)
    printf("%d ",it);
    printf("\n");
}