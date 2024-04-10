#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

string s;
int cnt,n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    n=s.size();
    for(int i=0; i<n;i++) {
        if(s[i]=='a') {
            cnt++;
        }
    }
    cout<<min(n,cnt*2-1);
}