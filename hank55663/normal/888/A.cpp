#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
int main(){
    int n;
    scanf("%d",&n);
    int a[1005];
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    int ans=0;
    for(int i = 1;i<n-1;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1])ans++;
        if(a[i]<a[i-1]&&a[i]<a[i+1])ans++;
    }
    printf("%d\n",ans);
} 
/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/