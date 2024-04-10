#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
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
void solve(){
    char c[100005];
    scanf("%s",c);
    LL sum=0;
    int len=strlen(c);
    LL ans=0;
    for(int i = 0;i<len;i++){
        sum=(sum*10+c[i]-'0')%mod;
        if(i!=len-1){
            ans+=sum*(f_pow(10,len-i-1)-1+mod)%mod*f_pow(9,mod-2)%mod;
            //printf("%lld %d\n",sum,(f_pow(10,len-i-1)-1+mod)%mod*f_pow(9,mod-2)%mod);
        }
        ans+=(c[i]-'0')*f_pow(10,len-i-1)%mod*(i*1ll*(i+1)/2)%mod;
        ans%=mod;
      //  printf("%lld %lld\n",(c[i]-'0')*f_pow(10,len-i-1),(i*1ll*(i+1)/2));
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*


*/
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/