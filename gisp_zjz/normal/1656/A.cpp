#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef vector<int>vi;
const int maxn=1e6+10;
int _,n,p,q,a[maxn];
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        p=q=1;
        for (int i=1;i<=n;i++) {
            if (a[i]<a[p]) p=i;
            if (a[i]>a[q]) q=i;
        }
        cout << p << ' ' << q << endl;
    }
}