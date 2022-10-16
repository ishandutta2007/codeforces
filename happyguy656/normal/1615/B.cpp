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
//mt19937 rnd(time(0));
//int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

int gg(int x,int k){
    int v=1<<k;
    int e=x/v;if(e&1)return (e+1)/2*v;
    return e/2*v+x%v+1;
}

int sol(){
    int l,r,re=2e9;cin>>l>>r;for(int i=0;i<=25;++i)re=min(re,gg(r,i)-gg(l-1,i));
    return re;
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%d\n",sol());
    return 0;
}