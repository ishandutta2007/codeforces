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
#define index Index
void solve(){
    int n;
    scanf("%d",&n);
    int l[100005],r[100005],c[100005];
    int Minl=1e9+7,Maxr=0;
    int a=0,b=0;
    int ans=2e9+7;
    pii ansr;
    for(int i = 0;i<n;i++){
        scanf("%d %d %d",&l[i],&r[i],&c[i]);
        if(l[i]<Minl)Minl=l[i],a=c[i];
        if(l[i]==Minl)a=min(a,c[i]);
        if(r[i]>Maxr)Maxr=r[i],b=c[i];
        if(r[i]==Maxr)b=min(b,c[i]);
         if(ansr!=mp(Minl,Maxr))ans=2e9+7;
        if(l[i]==Minl&&r[i]==Maxr){
            ansr=mp(l[i],r[i]);
            ans=min(ans,c[i]);
        }
       
        printf("%d\n",min(a+b,ans));
    }
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
8876666554222188 
*/