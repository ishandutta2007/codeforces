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

int n,m;
#define Maxn 300010
ll c[Maxn];
pair<ll,int> b[Maxn];

ll input(){
    ll ans=0;
    rep(i,1,m){
        scanf("%lld",&c[i]);
        ans+=c[i]*i;
    }
    return ans;
}

int main(){
    int t;rd(t);
    while(t--){
        rd(n);rd(m);
        rep(i,1,n){
            b[i].FR=input();b[i].SE=i;
        }
        sort(b+1,b+n+1);
        printf("%d %lld\n",b[n].SE,b[n].FR-b[1].FR);
    }
    return 0;
}