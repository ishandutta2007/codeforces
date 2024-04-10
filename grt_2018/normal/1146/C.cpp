#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

int t;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int ans = 0;
        int p = 2;
        for(int i=0; i<9;i++) {
            vi s1,s2;
            for(int j=1; j<=n;j++) {
                if((j%p)<p/2) {
                    s1.PB(j);
                }
                else {
                    s2.PB(j);
                }
            }
            if(s1.size()+s2.size()<n||
               s1.size()==0||s2.size()==0) break;
            cout<<s1.size()<<" "<<s2.size()<<" ";
            for(auto it:s1) cout<<it<<" ";
            for(auto it:s2) cout<<it<<" ";
            cout<<"\n";
            fflush(stdout);
            int x;
            cin>>x;
            ans=max(ans,x);
            p*=2;
        }
        cout<<"-1 "<<ans<<"\n";
        fflush(stdout);
    }
}