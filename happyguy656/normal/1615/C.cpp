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

const int mxn=1e5+3;
int n;char s1[mxn],s2[mxn];

int sol(){
    scanf("%d%s%s",&n,s1+1,s2+1);
    int x=0,y=0;for(int i=1;i<=n;++i)x+=s1[i]=='0'&&s2[i]=='1',y+=s1[i]=='1'&&s2[i]=='0';
    int re=2e9;
    if(x==y)re=2*x;
    for(int i=1;i<=n;++i)s1[i]=s1[i]=='1'?'0':'1';
    x=0,y=0;for(int i=1;i<=n;++i)x+=s1[i]=='0'&&s2[i]=='1',y+=s1[i]=='1'&&s2[i]=='0';
    if(x==y+1)re=min(re,x+y);
    if(re>2e8)return -1;return re;
}

int main(){
    int ca;cin>>ca;while(ca--)printf("%d\n",sol());
    return 0;
}