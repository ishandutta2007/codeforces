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

char s[13];
int cal(int z){
    for(int i=0;i<10;++i){
        int x=z>>i&1;if(s[i]!='?'&&s[i]-'0'!=x)return 11;
    }
    int c1=0;
    for(int i=0;i<10;++i){
        int k=(9-i)/2;
        if(i%2==0){c1+=z>>i&1;if(c1-k-1>0)return i+1;if(c1+k<0)return i+1;}
        else{c1-=z>>i&1;if(c1-k>0)return i+1;if(c1+k<0)return i+1;}
    }
    return 10;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%s",s);int re=10;for(int z=0;z<(1<<10);++z)re=min(re,cal(z));printf("%d\n",re);
    }
    return 0;
}