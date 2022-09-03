#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
int main(){
    int n;
    scanf("%d",&n);
    int a[50][50];
    int now=1;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<n;j++){
            a[i][j]=now++;
        }
    for(int i = (n+1)/2%2;i<n/2;i+=2){
        for(int j =i;j<n-1-i;j+=2){
            swap(a[i][j],a[i][j+1]);
            swap(a[n-i-1][n-j-1],a[n-i-1][n-j-2]);
        }
        for(int j=i+1;j<n-i;j+=2){
            swap(a[j][i],a[j+1][i]);
            swap(a[n-j-1][n-i-1],a[n-j-2][n-i-1]);
        }
    }
    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

}