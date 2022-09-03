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
#define pdd pair<double,double>
#define cpdd const pdd
int main(){
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    LL sum=0;
    for(int i = 0;i<n-1;i++)
        sum+=a[i];
    if(sum>=a[n-1]&&(sum+a[n-1])%2==0){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000

 */