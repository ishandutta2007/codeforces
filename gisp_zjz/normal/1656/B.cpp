#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
int _,n,k,p,q,a[maxn];
int main(){
    cin >> _;
    while (_--){
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1); p=1;
        bool ok=0;
        for (int i=1;i<=n;i++){
            while (p<=n&&a[i]+k>a[p]) ++p;
            if (p<=n&&a[i]+k==a[p]) ok=1;
        }
        if (ok) puts("YES"); else puts("NO");
    }
    return 0;
}