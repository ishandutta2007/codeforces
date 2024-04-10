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
int n;char s[mxn];
void pr(int k){
    for(int i=1;i<=k;++i)putchar(s[i]);for(int i=k;i;--i)putchar(s[i]);puts("");
}
void sol(){
    scanf("%d%s",&n,s+1);
    if(n==1||s[1]==s[2])return pr(1);
    for(int i=1;i<=n;++i)if(s[i]<s[i+1]||i==n)return pr(i);
}

int main(){
    int ca;cin>>ca;while(ca--)sol();
    return 0;
}