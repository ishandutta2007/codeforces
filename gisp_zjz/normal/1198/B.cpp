#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=5e5+3;
typedef long long ll;
typedef pair<int,int> pi;
int n,m,d,cnt,a[maxn],mx[maxn],t[maxn],o;

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t[i]=0;
    }
    scanf("%d",&m);
    for (int i=1;i<=m;i++){
        scanf("%d",&o);
        if (o==2) scanf("%d",&mx[i]);
        else {
            int x; scanf("%d",&x);
            t[x]=i; scanf("%d",&a[x]);
        }
    }
    for (int i=m;i;i--) mx[i-1]=max(mx[i-1],mx[i]);
    for (int i=1;i<=n;i++) printf("%d ",max(a[i],mx[t[i]])); puts("");
    return 0;
}