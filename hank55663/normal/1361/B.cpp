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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
int mod=1e9+7;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,p;
        scanf("%d %d",&n,&p);
        int a[1000005];
        for(int i= 0;i<n;i++){
            scanf("%d",&a[i]);
        }
        if(p==1){
            printf("%d\n",n&1);
            continue;
        }
        sort(a,a+n);
        reverse(a,a+n);
        map<int,int> m;
        for(int i = 0;i<n;i++){
            m[a[i]]++;
            int now=a[i];
            while(m[now]==p&&now!=m.rbegin()->x){
                m[now+1]++;
                m.erase(now);
                now++;
            }
            if(m.rbegin()->y%2==0){
                m.erase(m.rbegin()->x);
            }
        }
        LL ans=0;
        for(auto it:m){
            ans=ans+mod-f_pow(p,it.x)*it.y%mod;
            ans%=mod;
        }
        if(m.size()){
            ans+=f_pow(p,m.rbegin()->x)*2%mod;
            ans%=mod;
        }
        printf("%lld\n",ans);
    }
}

/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/