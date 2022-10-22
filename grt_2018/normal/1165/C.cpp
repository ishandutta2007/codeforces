#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

const int nax = 200*1000+1;
int n;
string s;
char S[nax];
int r;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    S[r++]=s[0];
    int ind=1;
    while(ind<n) {
        while(ind<n&&S[r-1]==s[ind]) {
            ind++;
        }
        if(ind<n) {
            S[r++]=s[ind++];
        }
        if(ind<n) {
            S[r++]=s[ind++];
        }
    }
    r = r-(r&1);
    cout<<n-r<<"\n";
    for(int i=0; i<r;i++) {
        cout<<S[i];
    }
}