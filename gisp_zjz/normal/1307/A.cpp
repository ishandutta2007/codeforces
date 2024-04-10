#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int> pi;
const int maxn=1e5+10;
int _,ans,a[maxn],n,d;
int main(){
    cin >> _;
    while (_--){
        cin >> n >> d;
        for (int i=0;i<n;i++) cin >> a[i];
        ans=a[0];
        for (int i=1;i<n;i++){
            int res=min(a[i],d/i);
            d-=res*i; ans+=res;
        }
        cout << ans << endl;
    }
    return 0;
}