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
using namespace std;
bool solve(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(c==0){
        if(a==b)printf("YES\n");
        else printf("NO\n");
    }
    else if((b-a)%c!=0||(b-a)/c<0){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
    return true;
}
int main(){
    int t=1;;//  scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}