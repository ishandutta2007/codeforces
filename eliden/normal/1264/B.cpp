#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
bool good(const vector<int> &seq) {
    int n = seq.size();
    rep(i,0,n-1) if(abs(seq[i]-seq[i+1])!=1) return false;
    return true;
}
void output(const vector<int> &seq) {
    cout<<"YES\n";
    for(int x:seq) cout<<x<<" ";
    cout<<"\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    bool found = false;
    int n = a+b+c+d;
    rep(x,0,2) {
        vector<int> seq(n);
        if(x==0) {
            if(b+d!=a+c && b+d!=a+c-1) continue;
            rep(i,0,a) seq[2*i] = 0;
            rep(i,a,a+c) seq[2*i] = 2;
            rep(i,0,b) seq[2*i+1] = 1;
            rep(i,b,b+d) seq[2*i+1] = 3;
            if(good(seq)) {
                found = true;
                output(seq);
                break;
            }
        }
        else {
            if(b+d!=a+c && b+d!=a+c+1) continue;
            rep(i,0,a) seq[2*i+1] = 0;
            rep(i,a,a+c) seq[2*i+1] = 2;
            rep(i,0,b) seq[2*i] = 1;
            rep(i,b,b+d) seq[2*i] = 3;
            if(good(seq)) {
                found = true;
                output(seq);
                break;
            }            
        }
    }
    if(!found) cout<<"NO\n";
}