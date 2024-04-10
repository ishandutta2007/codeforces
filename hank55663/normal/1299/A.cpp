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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
int main(){
    int n;
    scanf("%d",&n);
    int cnt[31];
    int a[100005];
    MEM(cnt);
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        for(int j=0;j<30;j++){
            if(a[i]&(1<<j))cnt[j]++;
        }
    }
    int Max=-1,Maxi=0;
    for(int i = 0;i<n;i++){
        int res=0;
        for(int j = 0;j<30;j++){
            if((a[i]&(1<<j))&&cnt[j]==1)res+=(1<<j);
        }
        if(res>Max)Max=res,Maxi=i;
    }
    printf("%d ",a[Maxi]);
    for(int j =0;j<n;j++){
        if(j!=Maxi)printf("%d ",a[j]);
    }
    printf("\n");
}