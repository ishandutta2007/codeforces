#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 200*1000+1;
int n,x,y,ans;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>x>>y>>s;
    for(int i=n-x; i<n;i++) {
        if(n-i-1==y) {
            if(s[i]=='0') ans++;
        }
        else {
            if(s[i]=='1') ans++;
        }
    }
    cout<<ans;
}