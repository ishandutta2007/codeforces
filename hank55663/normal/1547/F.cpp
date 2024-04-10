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
int factor[1000005];
vector<int> v[1000005];
void solve(){
    int n;
    scanf("%d",&n);
    int a[200005];
    int gcd=0;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        gcd=__gcd(a[i],gcd);
    }
    for(int i = 0;i<n;i++)a[i]/=gcd;
    for(int i =0;i<n;i++){
        map<int,int> m;
        int tmp=a[i];
        while(a[i]!=1){
            m[factor[a[i]]]++;
            a[i]=a[i]/factor[a[i]];
        }
        a[i]=tmp;
        for(auto it:m){
            v[it.x].pb(i);
         //   printf("%d ",it.x);
        }
       // printf("\n");
    }
    int ans=0;
    for(int i = 0;i<n;i++){
        int tmp=a[i];
        while(a[i]!=1){
            if(v[factor[a[i]]].size()){
                int cnt=0;
                int last=-100;
               // printf("%d\n",factor[a[i]]);
                for(auto it:v[factor[a[i]]]){
                    if(it==last+1)cnt++;
                    else cnt=1;
                    last=it;
                    ans=max(ans,cnt);
                   // printf("%d ",it);
                }
                for(auto it:v[factor[a[i]]]){
                    if(it+n==last+1)cnt++;
                    else cnt=1;
                    last=it+n;
                    ans=max(ans,cnt);
                   // printf("%d ",it+n);
                }
               // printf("\n");
            }
            v[factor[a[i]]].clear();
            a[i]=a[i]/factor[a[i]];
        }
    }
    printf("%d\n",ans);
}
int main(){
    for(int i = 2;i<=1000000;i++){
        if(factor[i]==0){
            for(int j = i;j<=1000000;j+=i){
                factor[j]=i;
            }
        }
    }
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}