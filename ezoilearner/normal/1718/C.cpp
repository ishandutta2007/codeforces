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

int t,n,q;
#define Maxn 200010
int a[Maxn],cnt;
ll num[20][Maxn];
int pr[20];multiset<ll> S[20];
multiset<ll>::iterator it;

void query(){
    ll mx=0;
    rep(i,1,cnt){
        it=S[i].end();it--;
        mx=max(mx,(*it)*pr[i]);
    }
    printf("%lld\n",mx);
}
void Change(int p,int x){
    x=x-a[p];
    rep(i,1,cnt){
        S[i].erase(S[i].find(num[i][p%pr[i]]));
        num[i][p%pr[i]]+=x;
        S[i].insert(num[i][p%pr[i]]);
    }
    a[p]+=x;
}

int main(){
    rd(t);
    while(t--){
        rd(n);rd(q);
        int cur=n;cnt=0;
        rep(i,2,cur)
            if(cur%i==0){
                while(cur%i==0)cur/=i;
                pr[++cnt]=n/i;
                rep(j,0,pr[cnt]-1)num[cnt][j]=0;
            }
        rep(i,0,n-1){
            rd(a[i]);
            rep(j,1,cnt)num[j][i%pr[j]]+=a[i];
        }
        rep(i,1,cnt){
            S[i].clear();
            rep(j,0,pr[i]-1)S[i].insert(num[i][j]);
        }
        query();
        rep(i,1,q){
            int p,x;rd(p);rd(x);
            p--;
            Change(p,x);
            query();
        }
    }
    return 0;
}