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

int n;

void slv(){
    scanf("%d",&n);int x,y,v1,v2,v3;for(int t=1;t<=n;++t){
        int l,r,v;scanf("%d%d%d",&l,&r,&v);
        if(t==1)x=l,y=r,v1=v2=v3=v;else{
            if(l<x)x=l,v3=v1=2e9;if(r>y)y=r,v3=v2=2e9;
            if(x==l)v1=min(v1,v);if(y==r)v2=min(v2,v);if(x==l&&y==r)v3=min(v3,v);
        }
        printf("%d\n",min(v1+v2,v3));
    }
}

int main(){
    int ca;cin>>ca;while(ca--)slv();
    return 0;
}