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
#define next Next
int main() {
    int n;
    scanf("%d",&n);
    int a[200005];
    int mid;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]==n)mid=i;
    }
    int ans=1;
    for(int i = 0;i<mid;i++){
        if(a[i]>a[i+1])
        ans=0;
    }
    for(int i=n-1;i>mid;i--){
        if(a[i]>a[i-1])
            ans=0;
    }
    if(ans)printf("YES\n");
    else printf("NO\n");
}