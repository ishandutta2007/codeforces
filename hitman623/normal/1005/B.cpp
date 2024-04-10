#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
string a,b;
int cnt=0;
void solve(){
    cin>>a>>b;
    int p1=a.size()-1,p2=b.size()-1;
    while(p1>=0 and p2>=0){
        if(a[p1]==b[p2]) p1--,p2--;
        else break;
        cnt++;
    }
    cout<<a.size()+b.size()-2*cnt<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}