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
int _,n,k,x[maxn],y[maxn];
int main(){
    cin >> _;
    while (_--){
        cin >> n >> k;
        for (int i=1;i<=n;i++) cin >> x[i] >> y[i];
        bool flag=0;
        for (int i=1;i<=n;i++){
            bool ok=1;
            for (int j=1;j<=n;j++) ok&=abs(x[i]-x[j])+abs(y[i]-y[j])<=k;
            flag|=ok;
        }
        if (flag) puts("1"); else puts("-1");
    }
}