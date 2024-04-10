#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int>pi;
typedef vector<int>vi;
#define ST first
#define ND second
#define PB push_back

const int MAXN = 100*1000+1;
int n,q;
LL s[MAXN];
LL diff[MAXN];
LL pref[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=0; i<n;i++) {
        cin>>s[i];
    }
    cin>>q;
    sort(s,s+n);
    for(int i=1; i<n;i++) diff[i-1] = s[i] - s[i-1];
    sort(diff,diff+n-1);
    for(int i=0; i<n-1;i++) {
        pref[i]=diff[i];
        if(i>0) pref[i]+=pref[i-1];
    }
    while(q--) {
        LL l,r,lenq;
        cin>>l>>r;
        lenq = r-l+1;
        int pocz=0,kon=n-2,sr;
        while(pocz<=kon) {
            sr=(pocz+kon)/2;
            if(diff[sr]<=lenq) pocz=sr+1;
            else kon=sr-1;
        }
        pocz--;
        cout<<(LL)pref[pocz] + (LL)lenq*(n-pocz-1)<<" ";
    }
}