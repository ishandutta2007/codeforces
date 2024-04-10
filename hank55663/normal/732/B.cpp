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
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    int Min=1e9,Mini;
    int a[505];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    int sum=0;
    for(int i = 1;i<n;i++){
        while(a[i-1]+a[i]<k){
            a[i]++;
            sum++;
        }
    }
    printf("%d\n",sum);
    for(int i = 0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}