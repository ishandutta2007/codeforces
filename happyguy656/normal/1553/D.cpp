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

const int mxn=2e5+3;
char s1[mxn],s2[mxn];
bool chk(){
    int n1=strlen(s1+1),n2=strlen(s2+1);
    for(int i=n2,j=n1;i;--i){
        while(j>0&&s2[i]!=s1[j])j-=2;
        if(j<=0)return 0;
        --j;
    }
    return 1;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%s%s",s1+1,s2+1);
        puts(chk()?"yEs":"nO");
    }
    return 0;
}