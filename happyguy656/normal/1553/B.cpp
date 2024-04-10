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

char s1[5555],s2[5555];
bool chk1(int x,int y,int z){
    int c=0;for(int i=x;i<=y;++i)if(s1[i]!=s2[++c])return 0;
    for(int i=y-1;i>=z;--i)if(s1[i]!=s2[++c])return 0;
    return 1;
}
bool chk(){
    int l1=strlen(s1+1),l2=strlen(s2+1);
    for(int x=1;x<=l1;++x)for(int y=x;y<=l1;++y){
//        y-x+1+y-z==l2
        int z=y-x+1+y-l2;
        if(z<=y&&z>0&&chk1(x,y,z))return 1;
    }return 0;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%s%s",s1+1,s2+1);
        puts(chk()?"YES":"nO");    
    }
    return 0;
}