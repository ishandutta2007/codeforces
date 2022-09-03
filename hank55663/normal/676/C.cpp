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
    char c[100005];
    scanf("%s",c+1);
    map<int,int> m;
    m[0]=0;
    int cnt=0;
    int ans=0;
    for(int i = 1;c[i]!=0;i++){
        if(c[i]=='b'){
            cnt++;
            m[cnt]=i;
        }
        if(cnt<=k)ans=max(ans,i);
        else ans=max(ans,i-m[cnt-k]);
    }
    cnt=0;
    m.clear();
    m[0]=0;
     for(int i = 1;c[i]!=0;i++){
        if(c[i]=='a'){
            cnt++;
            m[cnt]=i;
        }
        if(cnt<=k)ans=max(ans,i);
        else ans=max(ans,i-m[cnt-k]);
    }
    printf("%d\n",ans);
}
int main(){
    int t=1;;//  scanf("%d",&t);
    while(t--)solve();
   /* while(t--){
        solve();
    }*/
}