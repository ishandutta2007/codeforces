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
#define MXN 10005
#define less Less
int main(){
    LL n;
    char c[65];
    scanf("%lld %s",&n,c+1);
    LL ans[65];
    fill(ans,ans+65,1e18+1);
    ans[0]=0;
    for(int i = 1;c[i]!=0;i++){
        LL value=0;
        //if(c[i]!='0')
        for(int j = i;value<n&&c[j]!=0;j++){
            value=value*10+c[j]-'0';
            if(value>=n)
            break;
            //printf("%d\n",ans[i-1]);
            if(ans[i-1]!=0){
                LL k=1000000000000000001/ans[i-1];
                if(k<n)
                break;
            }
            ans[j]=min(ans[j],ans[i-1]*n+value);
            //printf("%d %lld\n",j,ans[i-1]*n+value);
            if(c[i]=='0')
            break;
        }
      //  printf("%lld\n",ans[i]);
    }
    printf("%lld\n",ans[strlen(c+1)]);
    return 0;
}
/*
1 
2 6 
3 5 
4
*/