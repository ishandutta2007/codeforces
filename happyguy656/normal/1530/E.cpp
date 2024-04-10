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

const int mxn=2e5+3;
char s[mxn];int ss[mxn];int n,cs[26];
void sol(){
    for(int c=0;c<26;++c)if(cs[c]==1){
        for(int i=0;i<n;++i)if(s[i]==c+'a')swap(s[i],s[0]);
        sort(s+1,s+n);printf("%s\n",s);return;
    }
    for(int c=0;c<26;++c)if(cs[c]==n)return printf("%s\n",s),void();
    int c1,c2;
    for(c1=0;c1<26;++c1)if(cs[c1])for(c2=0;c2<26;++c2)if(cs[c2]){
        if(c1!=c2)goto tb;
        if(n-cs[c1]>=cs[c1]-2)goto tb;
    }
    tb:;
    --cs[c1],--cs[c2];
    ss[0]=c1,ss[1]=c2;
    #define tc for(int i=0;i<n;++i)putchar(ss[i]+'a');puts("");return;
    int k=2;
    if(c1!=c2){
        for(int c=c1+1;c<26;++c)if(c!=c2&&cs[c]){
            while(cs[c1]--)ss[k++]=c1;
            ss[k++]=c,--cs[c];
            for(int c=c1+1;c<26;++c)while(cs[c]--)ss[k++]=c;
            tc
        }
        for(int c=c1+1;c<26;++c)while(cs[c]--)ss[k++]=c;
        while(cs[c1]--)ss[k++]=c1;
        tc
    }
    ++cs[c1],k=1;
    while(cs[c1]){
        ss[k++]=c1,--cs[c1];for(int c=c1+1;c<26;++c)if(cs[c]){ss[k++]=c,--cs[c];break;}
    }
    for(int c=0;c<26;++c)while(cs[c]--)ss[k++]=c;
    tc
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%s",s);n=strlen(s);memset(cs,0,sizeof(cs));for(int i=0;s[i];++i)++cs[s[i]-'a'];
        sol();
    }
    return 0;
}