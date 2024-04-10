#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<int> vi;
const int maxn=1e6+12;
char s[maxn];
int n,cnt[maxn];
int main(){
    cin >> n >> s+1;
    for (int i=1;i<=n;i++) {
        if (s[i]=='(') cnt[i]=cnt[i-1]+1;
        else cnt[i]=cnt[i-1]-1;
    }
    if (cnt[n]){
        puts("-1");
        return 0;
    }
    int ans=0;
    for (int i=1;i<=n;i++) if (cnt[i]<0||(cnt[i]==0&&cnt[i-1]<0)) ++ans;
    cout << ans << endl;
    return 0;
}