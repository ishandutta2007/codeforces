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
int q,mxx,mxy;
void solve(){
    cin>>q;
    while(q--){
    	char ch;
    	cin>>ch;
    	if(ch=='+'){
    		int x,y;
    		cin>>x>>y;
    		if(x>y) swap(x,y);
    		mxx=max(mxx,x);
    		mxy=max(mxy,y);
    	}
    	else{
    		int h,w;
    		cin>>h>>w;
    		if(h>w) swap(h,w);
    		if(mxx<=h and mxy<=w) cout<<"YES"<<endl;
    		else cout<<"NO"<<endl;
    	}
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