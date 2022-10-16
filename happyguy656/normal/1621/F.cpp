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

const int mxn=2e5+3;
int n,m,b[mxn],d[mxn],nn,h[mxn],c1,c2,c3;ll A,B,C;
char s[mxn];

ll sol(int x,int y){
    if(x<0)return -9e18;
    int k=min(x,y);
    ll re=k*(A+B);x-=k,y-=k;
    //x 1   y 0
    if(C>=B){
        if(y)re+=A;return re;
    }
    int p=1,c=0;for(int i=1;i<=nn;++i)h[i]=d[i];
    for(int i=1;i<=nn;++i){int t=min(k,h[i]);h[i]-=t,k-=t;c+=!h[i];}
    re+=c*(B-C);
    if(!x){if(y)re+=A;return re;}
    assert(!y);
    return re+min(c3,x)*(B-C);
}


ll slv(){
    cin>>n>>A>>B>>C;scanf("%s",s+1);
    m=nn=0;
    c1=c2=c3=0;
    for(int i=1;i<=n;){
        int c=0;while(s[i]=='1')++i,++c;
        b[++m]=c;
        c=0;while(s[i]=='0')++i,++c;b[++m]=c;
    }
    c3=s[1]=='0';c3+=s[n]=='0';
    for(int i=b[1]?2:4;i<m;i+=2)d[++nn]=b[i]-1;sort(d+1,d+nn+1);
    for(int i=1;i<=m;i+=2)if(b[i])c1+=b[i]-1;
    for(int i=2;i<=m;i+=2)if(b[i])c2+=b[i]-1;
    return max(sol(c1,c2),sol(c1-1,c2)+B);
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%lld\n",slv());
    return 0;
}