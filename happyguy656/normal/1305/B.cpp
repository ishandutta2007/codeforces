#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef pair<int,int>pii;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e5+3;
char s[mxn];int n;

int main(){ 
    cin>>s+1;n=strlen(s+1);
    int P=0;for(int i=1;i<=n;++i)if(s[i]==')')P=i;bool ok=1;for(int i=1;i<=P;++i)ok&=s[i]==')';if(ok)return puts("0"),0;
    int c0=0,c1=0;for(int i=1;i<=n;++i)c0+=s[i]=='(';
    for(int i=n;~i;--i){
        if(c0==c1){
            puts("1");printf("%d\n",c0+c1);
            for(int j=1;j<=i;++j)if(s[j]=='(')printf("%d ",j);
            for(int j=i+1;j<=n;++j)if(s[j]==')')printf("%d ",j);puts("");
        }
        if(s[i]==')')++c1;else --c0;
    }
    return 0;
}