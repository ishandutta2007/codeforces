#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=3e5+12;
char s[maxn];
int n,l,r;
vector <int> ans;
int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    l=1; r=n;
    while (l<=r){
        while (l<=n&&s[l]!='(') ++l;
        while (r>=1&&s[r]!=')') --r;
        if (l<=r) ans.pb(l),ans.pb(r),l++,r--;
        else break;
    }
    sort(ans.begin(),ans.end());
    if (ans.size()){
        cout << 1 << endl << ans.size() << endl;
        for (auto x:ans) cout << x << ' '; cout << endl;
    } else {
        puts("0");
    }
}