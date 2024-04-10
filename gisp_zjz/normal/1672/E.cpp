#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
const int M=998244353;
int n,r,l;
int ask(int x){
    printf("? %d\n",x); fflush(stdout);
    int y; scanf("%d",&y);
    return y;
}
int main(){
    scanf("%d",&n);
    l=0; r=5000000;
    while (r-l>1){
        int mid=(l+r)>>1;
        if (ask(mid)==1) r=mid; else l=mid;
    }
    int ans=r;
    for (int i=2;i<=n;i++){
        int h=ask(r/i);
        if (h==i) ans=min(ans,r/i*i);
    }
    printf("! %d\n",ans);
    return 0;
}