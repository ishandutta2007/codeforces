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
int f[200005];
int pre[200005];
int mod=1e9+7;
void solve(){
    f[0]=1;
    f[1]=1;
    for(int i = 2;i<=200000;i++)f[i]=(f[i-1]+f[i-2])%mod;
    pre[0]=1;
    for(int i = 1;i<=200000;i++)pre[i]=(pre[i-1]+f[i])%mod;
    int n,p;
    scanf("%d %d",&n,&p);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    LL ans=0;
    set<int> s;
    for(int i = 0;i<n;i++){
       // bitset<31> b(a[i]);
       // cout<<b<<endl;
        int x=a[i];
        int ok=1;
        while(true){
            if(s.find(x)!=s.end()){
                ok=0;
                break;
            }
            if(x&1)x>>=1;
            else{
                if(x==0)break;
                else if(x%4!=0)break;
                x>>=2;
            }
        }
        if(ok){
          //  printf("!\n");
            s.insert(a[i]);
            int cnt=0;
            while(a[i]){
                cnt++;
                a[i]>>=1;
            }
            if(cnt>p)continue;
            ans+=pre[p-cnt];
        }
    }

    printf("%lld\n",ans%mod);
}
int main(){
    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}