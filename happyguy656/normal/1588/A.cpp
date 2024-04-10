#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define uu unsigned
int abc;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

int a[103],b[103],n;
bool chk(){
    cin>>n;for(int i=1;i<=n;++i)scanf("%d",a+i);for(int i=1;i<=n;++i)scanf("%d",b+i);
    sort(a+1,a+n+1),sort(b+1,b+n+1);for(int i=1;i<=n;++i)if(a[i]>b[i]||a[i]<b[i]-1)return 0;
    return 1;
}
int main(){
    int ca;cin>>ca;while(ca--)puts(chk()?"yes":"no");
    return 0;
}