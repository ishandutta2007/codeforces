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
const int mod=1e9+7;
set<pii> s[200005];
map<int,int> m[200005];
int factor[200005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void solve(){
    for(int i = 2;i<=200000;i++){
        if(factor[i]==0){
            for(int j = i;j<=200000;j+=i){
                factor[j]=i;
            }
        }
    }
    int n,q;
    scanf("%d %d",&n,&q);
    LL ans=0;
    for(int i = 1;i<=n;i++){
        LL x;
        scanf("%lld",&x);
        ans=__gcd(ans,x);
          //  printf("%lld\n",ans);
        while(x!=1){
            m[i][factor[x]]++;
            x=x/factor[x];
        }
        for(auto it:m[i]){
            s[it.x].insert(mp(it.y,i));
        }
    }
   // printf("%lld\n",ans);
    while(q--){
        int i,x;
        scanf("%d %d",&i,&x);
        map<int,int> tmp;
        while(x!=1){
            tmp[factor[x]]++;
            x=x/factor[x];
        }
        for(auto it:tmp){
            if(s[it.x].size()==n){
                int x=s[it.x].begin()->x;
                ans=ans*f_pow(f_pow(it.x,x),mod-2)%mod;
            }
            s[it.x].erase(mp(m[i][it.x],i));
            m[i][it.x]+=it.y;
            s[it.x].insert(mp(m[i][it.x],i));
            if(s[it.x].size()==n){
                int x=s[it.x].begin()->x;
                ans=ans*f_pow(it.x,x)%mod;
            }
        }
        printf("%lld\n",ans);
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*

a b c
b c
ab ac bc
5
4 3
1 4
4 2
3 4
0 0
*/