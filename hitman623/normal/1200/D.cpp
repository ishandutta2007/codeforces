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
int n,k,p[2002][2002];
string s[2002];
int row[2002][2002];
int col[2002][2002];
int get(int l1,int r1,int l2,int r2){
	l2=min(l2,n);
	r2=min(r2,n);
	return p[l2][r2]-p[l1-1][r2]-p[l2][r1-1]+p[l1-1][r1-1];
}
void solve(){
	cin>>n>>k;
	rep(i,0,n) cin>>s[i];
	rep(i,1,n+1){
		rep(j,1,n+1){
			p[i][j]=(s[i-1][j-1]=='B')+p[i-1][j]+p[i][j-1]-p[i-1][j-1];
		}
	}
	int ans=0;
	rep(i,1,n+1){
		if(get(i,1,i,n)==0) ans++;
		if(get(1,i,n,i)==0) ans++;
	}
	rep(i,1,n+1){
		rep(j,1,n+1){
			if(get(i,j,i,j+k-1)==get(i,1,i,n) and get(i,1,i,n)) row[i][j]=1;
			if(get(i,j,i+k-1,j)==get(1,j,n,j) and get(1,j,n,j)) col[i][j]=1;
		}
	}
	rep(i,1,n+1){
		rep(j,1,n+1){
			row[i][j]+=row[i-1][j];
			col[i][j]+=col[i][j-1];
		}
	}
	int res=0;
	rep(i,1,n+1){
		rep(j,1,n+1){
			res=max(res,row[min(n,i+k-1)][j]-row[i-1][j]+col[i][min(n,j+k-1)]-col[i][j-1]);
		}
	}
	cout<<ans+res<<endl;
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