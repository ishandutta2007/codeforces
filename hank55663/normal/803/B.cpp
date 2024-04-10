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
#define N 200005
#define less Less
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i =1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int ans[200005];
    fill(ans,ans+n+1,1e9);
    int last=-1e9;
    for(int i = 1;i<=n;i++){
        if(a[i]==0)
            last=i;
        ans[i]=i-last;
    }
    last=1e9;
    for(int i =n;i>=1;i--){
        if(a[i]==0)
            last=i;
        ans[i]=min(ans[i],last-i);
    }
    for(int i = 1;i<=n;i++)
        printf("%d ",ans[i]);
}