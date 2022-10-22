#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second

inline void rd(int &x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}

int t,n;
#define Maxn 100010
int a[Maxn];
int dp[Maxn];
map<int,int> mp;

int main(){
    rd(t);
    while(t--){
        rd(n);
        mp.clear();
        rep(i,1,n){
            rd(a[i]);
            a[i]^=a[i-1];
        }
         int mx=0;
        mp[0]=0;
        rep(i,1,n){
            dp[i]=mx;
            if(mp.count(a[i]))dp[i]=max(dp[i],mp[a[i]]+1);
            mp[a[i]]=dp[i];
            mx=max(mx,dp[i]);
        }
        printf("%d\n",n-mx);
    }
    return 0;
}