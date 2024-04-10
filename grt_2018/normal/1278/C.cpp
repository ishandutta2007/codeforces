#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

int t;
const int nax = 400*1000+10,INF=1e9;
int n;
int a[nax];
int best[nax];
int ans,all1,all2;

int main() {_
    cin>>t;
    while(t--) {
        cin>>n;
        best[2*n] = INF;
        ans = INF;
        all1=all2=0;
        for(int i=0; i<2*n; i++) {
            cin>>a[i];
            best[i] = INF;
            if(a[i]==1) all1++;
            else all2++;
        }
        for(int i=2*n+1; i<=4*n; i++) best[i]=INF;
        best[2*n] = 0;
        int A=0,B=0;
        for(int i=n; i<2*n; i++) {
            if(a[i]==1) {
                A++;
            } else {
                B++;
            }
            best[A-B+2*n] = min(best[A-B+2*n],i-n+1);
        }
        ans=min(ans,best[all1-all2+2*n]);
        for(int i=n-1; i>=0; i--) {
            if(a[i]==1) all1--;
            else all2--;
            ans=min(ans,n-i+best[all1-all2+2*n]);
        }
        cout<<ans<<"\n";

    }




}