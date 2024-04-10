#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int _,n,l,r,cl,cr;
map<pi,int>f;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        l=1e9+1; r=-1; f.clear();
        for (int i=1;i<=n;i++){
            int x,y,z; scanf("%d%d%d",&x,&y,&z);
            if (f.find((pi){x,y})==f.end()) f[(pi){x,y}]=z;
            else f[(pi){x,y}]=min(f[(pi){x,y}],z);
            if (x<l) l=x,cl=z;
            else if (x==l) cl=min(cl,z);
            if (y>r) r=y,cr=z;
            else if (y==r) cr=min(cr,z);
            int ans=cl+cr;
            if (f.find((pi){l,r})!=f.end()) ans=min(ans,f[(pi){l,r}]);
            printf("%d\n",ans);
        }
    }
    return 0;
}