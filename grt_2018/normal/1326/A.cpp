#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

int t,n;

int main() {_
    cin >> t;
    while(t--) {
        cin >> n;
        if(n==1) cout<<"-1\n";
        else {
            if((n-1)%3==0) {
                for(int i=1; i<=n-2; i++) cout<<"2";
                cout<<"33\n";
            } else {
                for(int i=1; i<=n-1; i++) cout<<"2";
                cout<<"3\n";
            }
        }
    }

}