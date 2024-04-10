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

int n;
#define Maxn 500010
char s[Maxn];

int vis[Maxn],h[Maxn];
int main(){
    h[0]=h[1]=0;int mx=0;
    rep(i,2,100){
        rep(j,0,i-2)vis[h[j]^h[i-2-j]]=i;
        h[i]=0;
        while(vis[h[i]]==i)h[i]++;
    }
    rep(i,101,500000)h[i]=h[i-34];
    int t;rd(t);
    while(t--){
        rd(n);
        scanf("%s",s+1);
        int R=0,B=0;
        rep(i,1,n)
            if(s[i]=='R')R++;else B++;
        if(R>B)puts("Alice");
        else if(R<B)puts("Bob");
        else{
            int cnt=0;
            for(int l=1,r;l<=n;l=r+1){
                r=l;
                while(r+1<=n&&s[r+1]!=s[r])r++;
                cnt^=h[r-l+1];
            }
            if(cnt)puts("Alice");
            else puts("Bob");
        }
    }
    return 0;
}