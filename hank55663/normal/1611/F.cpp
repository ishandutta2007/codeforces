#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n,s;
    scanf("%d %d",&n,&s);
    int a[200005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    LL sum=0;
    int l=0;
    pii p=mp(-1,-1);
    for(int i = 0;i<n;i++){
        sum-=a[i];
        while(sum>s)sum+=a[l],l++;
       // printf("%d %d\n",l,i);
        if(l<=i&&i-l>=p.y-p.x)p=mp(l,i);
    }
    if(p.x==-1)printf("-1\n");
    else printf("%d %d\n",p.x+1,p.y+1);
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/