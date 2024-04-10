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
int _,n,m,ans;
int main(){
    cin >> _;
    while (_--){
        cin >> n >> m;
        ans=(n>1)+(m>1);
        cout << ans << endl;
    }
}