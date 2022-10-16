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
int n,qn,vv;char s[mxn];
bool chk(int x){if(x<1||x+2>n)return 0;return s[x]=='a'&&s[x+1]=='b'&&s[x+2]=='c';}
int main(){
    cin>>n>>qn;scanf("%s",s+1);for(int i=1;i<=n;++i)vv+=chk(i);while(qn--){
        int x;char ss[6];scanf("%d%s",&x,ss);vv-=chk(x-2)+chk(x-1)+chk(x);s[x]=ss[0];vv+=chk(x-2)+chk(x-1)+chk(x);
        printf("%d\n",vv);
    }
    return 0;
}