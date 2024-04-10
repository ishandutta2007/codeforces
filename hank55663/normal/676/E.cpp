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
    int n,k;
    scanf("%d %d",&n,&k);
    int a[100005];
    int ok=0,cnt=0;
    for(int i = 0;i<=n;i++){
        char c[100005];
        scanf("%s",c);
        if(c[0]=='?')ok++,a[i]=-1000000000;
        else{
            sscanf(c,"%d",&a[i]);
            cnt++;
        }
    }
    if(k==0){
        if(a[0]!=-1000000000){
            if(a[0]==0)printf("Yes\n");
            else printf("No\n");
        }
        else{
            if(cnt%2==0)printf("No\n");
            else printf("Yes\n");
        }
    }
    else if(ok){
        if(n%2==0)printf("No\n");
        else printf("Yes\n");
    }
    else{
        for(int t=0;t<100;t++){
            LL mod=rand()%1000000000+1000000000;
            while(true){
                int ok=1;
                for(int i = 2;i*i<=mod;i++){
                    if(mod%i==0){
                        ok=0;
                        break;
                    }
                }
                if(ok)break;
                mod++;
            }
            LL now=0;
            for(int i = n;i>=0;i--){
                now*=k;
                now+=a[i];
                now%=mod;
                now+=mod;
                now%=mod;
            }
            if(now!=0){
                printf("No\n");
                return true;
            }
        }
        printf("Yes\n");
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