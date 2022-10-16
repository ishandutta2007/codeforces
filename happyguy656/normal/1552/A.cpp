#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int abc;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

int n;char s[43],ss[43];

int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d%s",&n,s+1);memcpy(ss+1,s+1,sizeof(char)*n);
        sort(ss+1,ss+n+1);
        int re=0;for(int i=1;i<=n;++i)re+=ss[i]!=s[i];
        printf("%d\n",re);
    }
    return 0;
}