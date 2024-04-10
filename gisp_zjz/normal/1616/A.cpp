#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int M=998244353;
const int maxn=1e6+10;
int a[105],_,n,ans;
int main(){
    cin >> _;
    while (_--){
        cin >> n; ans=0;
        memset(a,0,sizeof(a));
        for (int i=0;i<n;i++){
            int x; cin >> x;
            a[abs(x)]++;
        }
        if (a[0]) ++ans;
        for (int i=1;i<=100;i++) ans+=min(a[i],2);
        printf("%d\n",ans);
    }
}