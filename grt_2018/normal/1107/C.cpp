#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2*100000+1;

int n,k;
long long ans;
pair<int,int> a[MAXN];
int cnt[MAXN];

string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    for(int i=0; i<n;i++) cin>>a[i].first;
    cin>>s;
    int block = 1;
    for(int i=1; i<n;i++) {
        a[i-1].second = block;
        if(s[i]!=s[i-1]) block++;
    }
    a[n-1].second=block;
    sort(a,a+n);
    for(int i=n-1; i>=0;i--) {
        if(cnt[a[i].second]<k) {
            ans+=a[i].first;
            cnt[a[i].second]++;
        }
    }
    cout<<ans;
    return 0;
}