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

int n,a[103];

bool chk(int x){
    for(int i=2;i*i<=x;++i)if(x%i==0)return 1;return 0;
}

int main(){
    int ca;cin>>ca;while(ca--){
        cin>>n;int s=0;for(int i=1;i<=n;++i)cin>>a[i],s+=a[i];
        if(chk(s)){printf("%d\n",n);for(int i=1;i<=n;++i)printf("%d ",i);puts("");continue;}
        int p=0;for(int i=1;i<=n;++i)if(a[i]&1)p=i;
        printf("%d\n",n-1);for(int i=1;i<=n;++i)if(i!=p)printf("%d ",i);puts("");
    }
    return 0;
}