#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pi;
map<pi,int> f;
int _,n;
long long ans;
int main(){
    scanf("%d",&_);
    while (_--){
        f.clear(); ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            int x,y,u,v;
            scanf("%d%d%d%d",&x,&y,&u,&v);
            x-=u; y-=v;
            int g=abs(__gcd(x,y));
            x/=g; y/=g;
            ans+=f[(pi){-x,-y}];
            f[(pi){x,y}]++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}