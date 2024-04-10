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
int _,n,r,l,a[maxn],c[maxn],ans[maxn];
pi b[maxn];
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=1;i<=n;i++) c[i]=0;
        for (int i=1;i<=n;i++) b[i]=(pi){a[i],i},c[a[i]]++;
        int m=0;
        for (int i=1;i<=n;i++) m=max(m,c[i]);
        sort(b+1,b+n+1);
        for (int i=1;i<=n;i++){
            int x=b[i].F;
            int y=b[(i+m-1)%n+1].S;
            ans[y]=x;
        }
        for (int i=1;i<=n;i++) printf("%d ",ans[i]);puts("");
    }
}