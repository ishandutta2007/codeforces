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
int n,a,b,re[mxn],nn;

bool chk(){
    if(abs(a-b)>1)return 0;
    if(a+b>n-2)return 0;
    nn=0;
    if(a==b){
        nn=0;for(int i=1;i<=a+1;++i)re[++nn]=i,re[++nn]=i+a+1;
        while(nn!=n)++nn,re[nn]=nn;
    }else if(a==b+1){
        int t=n-a-b-2;
        for(int i=1;i<=a+1;++i)re[++nn]=i+t,re[++nn]=i+a+t+1;
        --nn;for(int i=t;i;--i)re[++nn]=i;
    }else{
        swap(a,b);
        int t=n-a-b-2;
        for(int i=1;i<=a+1;++i)re[++nn]=i+t,re[++nn]=i+a+t+1;
        --nn;for(int i=t;i;--i)re[++nn]=i;
        for(int i=1;i<=n;++i)re[i]=n-re[i]+1;
    }
    for(int i=1;i<=n;++i)printf("%d ",re[i]);puts("");
    return 1;
}

int main(){
    int ca;cin>>ca;while(ca--){
        cin>>n>>a>>b;if(!chk())puts("-1");
    }
    return 0;
}