#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
int _,n,a[maxn];
int main(){
    cin >> _;
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1); 
        bool zero=0,one=0;
        for (int i=1;i<=n;i++){
            if (!a[i]) zero=1;
            if (a[i]==1) one=1;
        }
        if (!one) puts("YES");
        else {
            bool ok=1;
            for (int i=1;i<n;i++) 
                if (a[i+1]-a[i]==1) ok=0;
            if (ok) puts("YES"); else puts("NO");
        }
    }
    return 0;
}