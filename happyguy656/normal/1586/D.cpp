#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

int nx[103];
int n,X;
int b[103],d[103],ans[103];
int ask(){printf("? ");for(int i=1;i<=n;++i)printf("%d ",b[i]+1);puts("");fflush(stdout);int x;scanf("%d",&x);return x;}

int main(){
    cin>>n;
    for(int i=1;i<=n;++i)b[i]=1,d[i]=ask(),b[i]=0;
    for(int i=1;i<=n;++i)if(d[i]!=i&&d[i])nx[d[i]]=i;
    X=n;
    for(int i=1;i<=n;++i)if(!d[i]){
        for(int j=i;j;j=nx[j])ans[j]=X--;
    }
    while(X){
        for(int i=1;i<=n;++i)b[i]=0;
        for(int i=1;i<=n;++i)if(!ans[i])b[i]=1;
        int k=ask();
        for(;k;k=nx[k])ans[k]=X--;
    }
    printf("! ");for(int i=1;i<=n;++i)printf("%d ",ans[i]);puts("");
    return 0;
}