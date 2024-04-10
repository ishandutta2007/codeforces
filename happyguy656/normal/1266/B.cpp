#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

char s[222];int n;

bool chk(ll x){
    if(x<=14)return 0;
    int t=x%14;
    return t>=1&&t<=6;
}

int main(){
    int ca;cin>>ca;while(ca--){
        ll x;scanf("%lld",&x);puts(chk(x)?"yes":"no");
    }
    return 0;
}