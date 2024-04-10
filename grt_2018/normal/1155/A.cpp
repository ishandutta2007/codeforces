#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long LL;
#define PB push_back
#define ST first
#define ND second

int n;
string s;
pii x[3*100*1000+1];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>s;
    for(int i=0; i<n;i++) {
        x[i] = {s[i]-'a',i+1};
    }
    sort(x,x+n);
    int m = 0,pos=-1;
    for(int i=0; i<n;i++) {
        if(m>x[i].ND&&pos<x[i].ST) {
            cout<<"YES\n"<<x[i].ND<<" "<<m<<"\n";
            return 0;
        }
        if(m<x[i].ND) {
            m=x[i].ND;
            pos=x[i].ST;
        }
    }
    cout<<"NO";
}