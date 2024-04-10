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
#define cpdd const pdd
#define rank Rank
#define MXN 1500

int main(){
    LL n;
    scanf("%lld",&n);
    char c[300005];
    scanf("%s",c);
    LL ans=n*(n-1)/2;
  //  LL tot=1;
    for(int t=0;t<2;t++){
    LL lastA=-1,lastB=-1;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='A'){
            lastA=i;
            if(lastB!=-1)ans--;
        }
        else{
            lastB=i;
            if(lastA!=-1)ans--;
        }
    }
    reverse(c,c+n);
    }
    for(int i = 0;c[i+1]!=0;i++){
        if(c[i]!=c[i+1])ans++;
    }
    //ans-=tot*(tot+1)/2;
    printf("%lld\n",ans);
}