#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int>pi;
const int maxn=1e6+10;
const int M=998244353;
int _,n,m,ans,a[maxn],b[maxn],c[maxn];
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n); m=0;
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if (a[i]==b[m]) c[m]++;
            else b[++m]=a[i],c[m]=1;
        }
        ans=c[m];
        for (int i=1;i<m;i++){
            int cnt=c[i]+1,u=b[i],v=b[i+1];
            while (1){
                int w=v*2-u;
                int pos=lower_bound(b+1,b+m+1,w)-b;
                if (pos<=m) cnt++,v=b[pos]; else break;
            }
            ans=max(ans,cnt);
        }
        printf("%d\n",n-ans);
    }
    return 0;
}