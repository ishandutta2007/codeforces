#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
int abc;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
typedef pair<int,int>pii;
int rd(int l,int r){return rand()%(r-l+1)+l;}

ll n,m;

int main(){
    int ca;scanf("%d",&ca);while(ca--){
        cin>>n>>m;--m;
        while(m--){ll x=n,t1=0,t2=10;while(x)t1=max(t1,x%10),t2=min(t2,x%10),x/=10;n+=t1*t2;if(t2==0)break;}
        cout<<n<<endl;
    }
    return 0;
}