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
#define MXN 200005
int bit[30];
int guess(int a,int ti,int k){
    int tmp[30];
    MEM(tmp);
    for(int i = 0;a;i++){
        tmp[i]=a%k;
        a/=k;
    }
    int ans=0;
    for(int i = 29;i>=0;i--){
        if(ti&1){
            ans=ans*k+(bit[i]-tmp[i]+k)%k;
            tmp[i]=(bit[i]-tmp[i]+k)%k;
        }
        else{
            ans=ans*k+(bit[i]+tmp[i])%k;
            tmp[i]=(bit[i]+tmp[i])%k;
        }
    }
    for(int i = 0;i<30;i++){
        bit[i]=(tmp[i]-bit[i]+k)%k;
      //  printf("%d ",bit[i]);
    }
  //  printf("\n");
    return ans;
}
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    MEM(bit);
    for(int i = 0;i<n;i++){
        printf("%d\n",guess(i,i,k));
        fflush(stdout);
        int x;
        scanf("%d",&x);
        if(x==1)break;
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}