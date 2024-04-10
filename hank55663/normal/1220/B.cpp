#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 15000
int main(){
    int n;
    scanf("%d",&n);
    int a[1005][1005];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++)
            scanf("%d",&a[i][j]);
    }
    int gcd=a[0][0];
    for(int i = 1;i<n;i++){
        gcd=__gcd(gcd,a[0][i]);
    }
    int ans[1005];
    ans[0]=gcd;
    for(int i = 1;i<n;i++){
        ans[i]=a[0][i]/gcd;
    }
    int x=a[1][2]/(ans[1]*ans[2]);
    for(int i = 0;i<x;i++){
        if(i*i==x){
            x=i;
            break;
        }
    }
    //printf("%d \n",x);
    ans[0]/=x;
    for(int i = 1;i<n;i++)ans[i]*=x;
    for(int i =0;i<n;i++)
        printf("%d ",ans[i]);
    return 0;
}