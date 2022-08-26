#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
typedef vector<int>vi;
const int maxn=1e6+100;
const int M=1000000007;
int _,n,tot[maxn],a[maxn];
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        a[0]=a[1]; a[n+1]=a[n];
        for (int i=1;i<=n;i++) tot[i]=0;
        int sum=0;
        for (int i=1;i<=n;i++){
            if (a[i]==a[i-1]) ++tot[a[i]],sum++;
            if (a[i]==a[i+1]) ++tot[a[i]],sum++;
        }
        int MX=1;
        for (int i=2;i<=n;i++) if (tot[MX]<tot[i]) MX=i;
        int res=0;
        for (int i=1;i<n;i++){
            if (a[i]!=a[i+1]&&a[i]!=MX&&a[i+1]!=MX) res++;
        }
        while (res>0&&tot[MX]>sum/2+1) res--,sum+=2;
        if (tot[MX]<=sum/2+1) printf("%d\n",sum/2-1); else puts("-1");
    }
    return 0;
}