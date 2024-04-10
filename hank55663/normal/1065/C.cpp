#include<bits/stdc++.h>
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
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int h[200005];
    for(int i=0;i<n;i++)
        scanf("%d",&h[i]);
    sort(h,h+n);
    int tot=0,ans=0;
    for(int i=2e5;i>=0;i--){
        int x=n-(lower_bound(h,h+n,i)-h);
        if(x==n)
        break;
        if(tot+x>k){
            ans++;
            tot=0;
        }
        tot+=x;
    }
    if(tot)
    ans++;
    printf("%d\n",ans);
}