#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

string s;
int n;
int ans=1000*1000*1000;

int distq(char a, char b) {
    return min(abs(a-b),26-abs(a-b));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n;i++) {
        if(i+3>=n) break;
        ans=min(ans,distq(s[i],'A')+distq(s[i+1],'C')+distq(s[i+2],'T')+distq(s[i+3],'G'));
    }
    cout<<ans;
}