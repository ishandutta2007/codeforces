#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=3e5+12;
int a[maxn],b[maxn],n;

int main(){
    int _; cin >> _;
    while (_--){
        cin >> n;
        for (int i=0;i<n;i++) cin >> a[i]; sort(a,a+n);
        for (int i=0;i<n;i++) cin >> b[i]; sort(b,b+n);
        for (int i=0;i<n;i++) cout << a[i] << ' '; cout << endl;
        for (int i=0;i<n;i++) cout << b[i] << ' '; cout << endl;
    }
}