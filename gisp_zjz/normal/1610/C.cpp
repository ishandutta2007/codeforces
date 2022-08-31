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
int a[maxn],b[maxn],l[maxn],r[maxn],L,R,mid,n,_;
bool check(int k){
    for (int i=1;i<=n;i++) l[i]=k-a[i],r[i]=b[i]+1;
    int p=1;
    for (int i=1;i<=n;i++)
        if (l[i]<=p&&p<=r[i]) p++;
    return p>k;
}
int main(){
    cin >> _;
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d%d",&a[i],&b[i]);
        L=1; R=n+1;
        while (R-L>1){
            int mid=(L+R)>>1;
            if (check(mid)) L=mid; else R=mid;
        }
        printf("%d\n",L);
    }
}