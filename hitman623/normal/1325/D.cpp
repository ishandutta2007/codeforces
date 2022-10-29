#include <bits/stdc++.h>

#define int         long long
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

void solve(){
	int u,v;
	cin>>u>>v;
	if(u+v==0) cout<<0<<endl;
	else if(u==v) cout<<1<<endl<<u<<endl;
	else if(v<u or (v-u)%2) cout<<-1<<endl;
	else{
		int d=(v-u)/2;
		if((u&d)==0){
			cout<<2<<endl<<(u^d)<<" "<<d<<endl;
			return;
		}
		else cout<<3<<endl<<u<<" "<<d<<" "<<d<<endl;
	}    
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