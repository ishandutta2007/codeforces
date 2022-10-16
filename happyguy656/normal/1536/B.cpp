#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a14=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int a14;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

int n,a[1003],cn[26],cc[26][26],ct[26][26][26];char s[1003];
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d%s",&n,s+1);
        memset(cn,0,sizeof(cn)),memset(cc,0,sizeof(cc));
        for(int i=1;i<=n;++i)a[i]=s[i]-'a',++cn[a[i]];
        for(int i=0;i<26;++i)if(!cn[i]){printf("%c\n",i+'a');goto tb;}
        for(int i=1;i<n;++i)++cc[a[i]][a[i+1]];
        for(int i=0;i<26;++i)for(int j=0;j<26;++j)if(!cc[i][j]){printf("%c%c\n",i+'a',j+'a');goto tb;}
        memset(cn,0,sizeof(cn));
        for(int i=1;i+2<=n;++i)++ct[a[i]][a[i+1]][a[i+2]];
        for(int i=0;i<26;++i)for(int j=0;j<26;++j)for(int k=0;k<26;++k)if(!ct[i][j][k]){
            for(int t=1;t+2<=n;++t)--ct[a[t]][a[t+1]][a[t+2]];
            printf("%c%c%c\n",i+'a',j+'a',k+'a');goto tb;
        }
        tb:;
    }
    return 0;
}