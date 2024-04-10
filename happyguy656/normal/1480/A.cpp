#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

char s[103];

int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%s",s+1);int n=strlen(s+1);
        for(int i=1;i<=n;i+=2){
            if(s[i]!='a')s[i]='a';else s[i]='b';
            if(i!=n){
                if(s[i+1]!='z')s[i+1]='z';else s[i+1]='y';
            }
        }
        puts(s+1);
    }
    return 0;
}