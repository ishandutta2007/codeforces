#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}
void NC(ull k){cout<<(k>>20)<<endl;}

const int mxn=1e5+3;
int n,po[26][mxn],ee[26];
struct arrrr{
    int a[mxn];
    void clr(){for(int i=0;i<=n;++i)a[i]=0;}
    void add(int x){for(;x;x&=x-1)++a[x];}
    int ask(int x){int r=0;for(;x<=n;x+=x&-x)r+=a[x];return r;}
}ar;
char s1[mxn],s2[mxn],s[mxn];
bool chk(){
    for(int i=1;i<=n;++i)if(s1[i]!=s2[i])return s1[i]<s2[i];return 0;
}
int cal(int x,int p){return x-p+ar.ask(x);}
ll sol(){
    scanf("%d%s%s",&n,s1+1,s2+1);for(int i=1;i<=n+1;++i)s[i]=s1[i];sort(s1+1,s1+n+1);
    ar.clr();
    if(!chk())return -1;
    for(int i=1;i<=n;++i)s[i]-='a',s2[i]-='a';
    for(int c=0;c<26;++c)po[c][0]=0;
    for(int i=1;i<=n;++i)po[s[i]][++po[s[i]][0]]=i;
    memset(ee,0,sizeof(ee));
    ll re=9e18,nw=0;
    for(int i=1;i<=n;++i){
        int c=s2[i],p=n+1;
        for(int j=0;j<c;++j)if(ee[j]!=po[j][0])p=min(p,po[j][ee[j]+1]);
        if(p<=n)re=min(re,nw+cal(p,i));
        if(ee[c]==po[c][0])return re;
        p=po[c][++ee[c]];
        nw+=cal(p,i),ar.add(p);
    }
    return re;
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%lld\n",sol());
    return 0;
}