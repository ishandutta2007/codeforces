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
int a,b,diff;

int main() {_
    cin>>t;
    while(t--) {
        cin>>a>>b;
        if(a>b) swap(a,b);
        int ans = 0;
        while(1) {
            if(ans*(ans+1)/2>=b-a) {
                if((ans*(ans+1)/2)%2==(b-a)%2) {
                    break;
                }
            }
            ans++;
        }
        cout<<ans<<"\n";


    }




}