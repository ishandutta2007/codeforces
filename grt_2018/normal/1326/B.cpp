#include <bits/stdc++.h>
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;

const int nax = 200*1000+10;
int n;
int b[nax];

int main() {_
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> b[i];
    }
    int x = 0;
    for(int i=1; i<=n; ++i) {
        int a = b[i]+x;
        x = max(x,a);
        cout<<a<<" ";
    }

}