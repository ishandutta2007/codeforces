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
    int n;
    int l[1005];
    int r[1005];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&l[i]);
    for(int j=0;j<n;j++)
        scanf("%d",&r[j]);
    int a[1005];
    MEMS(a);
    int cnt=0;
    int ok[1005];
    MEM(ok);
    for(int i=n;i>=1;i--){
        for(int j=0;j<n;j++){
            if(l[j]==0&&r[j]==0&&a[j]==-1){
                a[j]=i;
                ok[j]=1;
                cnt++;
            }
            if(a[j]==-1&&(l[j]<0||r[j]<0)){
                printf("NO\n");
                return 0;
            }
        }
        int tot=0;
        for(int j=0;j<n;j++){
            tot+=ok[j];
            if(a[j]==-1){
                l[j]-=tot;
            }
        }
        tot=0;
        for(int j=n-1;j>=0;j--){
            tot+=ok[j];
            ok[j]=0;
            if(a[j]==-1){
                r[j]-=tot;
            }
        }
       /* for(int j=0;j<n;j++)
        printf("%d ",l[j]);
        printf("\n");
        for(int j=0;j<n;j++)
        printf("%d ",r[j]);
        printf("\n");*/
    }
    if(cnt!=n)
    printf("NO\n");
    else{
    printf("YES\n");
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    printf("\n");
    }
}