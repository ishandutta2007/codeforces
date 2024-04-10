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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        int a[35],b[35];
        int sum=0;
        for(int i = 0;i<n;i++)scanf("%d",&a[i]),sum+=a[i];
        for(int i =0;i<n;i++)scanf("%d",&b[i]);
        sort(a,a+n);
        sort(b,b+n);
        reverse(b,b+n);
        
        for(int i = 0;i<n&&i<k;i++){
            sum+=max(0,b[i]-a[i]);
        }
        printf("%d\n",sum);
    }

}

/*
C[i][j]=C[i>>1][j]
1000

1001
0000
0001
1000
1001
*/