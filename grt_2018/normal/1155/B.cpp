#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

int n,cnt;
string s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n;i++) {
        if(s[i]=='8') cnt++;
    }
    if((n-11)/2>=cnt) {
        cout<<"NO";
        return 0;
    }
    int cnt1=0;
    for(int i=0; i<n;i++) {
        if(s[i]=='8') cnt1++;
        if(cnt1>(n-11)/2) {
            if(i<=(n-11)) {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
}