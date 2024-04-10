#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007LL
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;

void solve(){
    string a,b,A,B;
    cin>>a>>b;
    int i=0,n=sz(a),m=sz(b);
    while(a[i]=='0') i++;
    rep(j,i,n){
        A+=a[j];
    }
    i=0;
    while(b[i]=='0') i++;
    rep(j,i,m){
        B+=b[j];
    }
    n=A.size(),m=B.size();
    if(n<m) cout<<"<";
    else if(n>m) cout<<">";
    else{
        rep(i,0,n){
            if(A[i]!=B[i]){
                if(A[i]<B[i]) {cout<<"<";return;}
                else {cout<<">";return;}
            }
        }
        cout<<"=";
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}