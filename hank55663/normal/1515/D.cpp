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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MAXK 2500
int cntl[200005],cntr[200005];
void solve(){
    int n,l,r;
    scanf("%d %d %d",&n,&l,&r);
    fill(cntl,cntl+n+1,0);
    fill(cntr,cntr+n+1,0);
    for(int i= 0;i<l;i++){
        int x;
        scanf("%d",&x);
        cntl[x]++;
    }
    for(int i=0;i<r;i++){
        int x;
        scanf("%d",&x);
        cntr[x]++;
    }
    for(int i = 1;i<=n;i++){
        while(cntl[i]&&cntr[i]){
            cntl[i]--;
            cntr[i]--;
            l--;
            r--;
        }
    }
    if(r>l){
        int ans=0;
        for(int i = 1;i<=n;i++){
            while(cntr[i]>=2){
                ans++;
                cntr[i]-=2;
                r-=2;
                if(r==l)break;
            }
            if(r==l)break;
        }
        //if(l==r)
        ans+=r;
       // else{
        //    ans+=l;
    
   //     }
        printf("%d\n",ans);
    }
    else{
        int ans=0;
        for(int i = 1;i<=n;i++){
            if(r==l)break;
            while(cntl[i]>=2){
                ans++;
                cntl[i]-=2;
                l-=2;
                if(l==r)break;
            }
        }
        ans+=l;
        printf("%d\n",ans);
    }
}
int main(){
  //  for(int i = 1;i*i<=1e9;i++)s.insert(i*i);
    int t=1;00000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
36

x x<<13  x>>7  x<<13>>7
x<<17  x<<30 x>>7<<17 x<<23

*/