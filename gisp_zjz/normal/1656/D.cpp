#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
int _;
ll p,x;
int main(){
    cin >> _;
    while (_--){
        scanf("%lld",&x);
        p=1; 
        while (x%2==0) p<<=1,x>>=1;
        if (x==1) puts("-1");
        else if (p==1) puts("2");
        else {
            ll ans=min(p*2,x);
            printf("%lld\n",ans);
        }
    }
    return 0;
}