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

int n,m,t;
#define Maxn 55
char c1[Maxn],c2[Maxn];

int main(){
    rd(t);
    while(t--){
        rd(n);rd(m);
        scanf("%s",c1+1);scanf("%s",c2+1);
        bool fl=false;
        rep(i,1,n-m+1)
            if(c1[i]==c2[1])fl=true;
        bool gg=true;
        rep(i,n-m+2,n)
            if(c1[i]!=c2[i-n+m])gg=false;
        if(gg&&fl)puts("YES");
        else puts("NO");
    }
    return 0;
}