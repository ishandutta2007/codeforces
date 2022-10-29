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
int a[333][333],r[333],c[333];
void solve(){
	memset(a,0,sizeof a);
	memset(r,0,sizeof r);
	memset(c,0,sizeof c);
    int n,k;
    cin>>n>>k;
    rep(i,0,n){
    	int x=i,y=0;
    	rep(j,0,n){
    		if(k==0) break;
    		a[x][y]=1;
    		r[x]++;
    		c[y]++;
    		k--;
    		x=(x+1)%n;
    		y=(y+1)%n;
    	}
    	if(k==0) break;
    }
    int rmx=0,rmn=hell,cmx=0,cmn=hell;
    rep(i,0,n){
    	rmx=max(rmx,r[i]);
    	rmn=min(rmn,r[i]);
    	cmx=max(cmx,c[i]);
    	cmn=min(cmn,c[i]);
    }
    cout<<(rmx-rmn)*(rmx-rmn)+(cmx-cmn)*(cmx-cmn)<<endl;
    rep(i,0,n){
    	rep(j,0,n){
    		cout<<a[i][j];
    	}
    	cout<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}