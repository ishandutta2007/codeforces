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
string s;
int a[5][5],vis[5][5];
void disp(){
	rep(i,1,5){
		rep(j,1,5){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
void balance(){
	memset(vis,0,sizeof vis);
	rep(i,1,5){
		int f=1,g=1;
		rep(j,1,5){
			if(a[i][j]==0) f=0;
			if(a[j][i]==0) g=0;
		}
		if(f){
			rep(j,1,5){
				vis[i][j]=1;
			}
		}
		if(g){
			rep(j,1,5){
				vis[j][i]=1;
			}
		}
	}
	rep(i,1,5){
		rep(j,1,5){
			if(vis[i][j]) a[i][j]=0;
		}
	}
	// disp();
}
void get_vertical(){
	rep(i,1,3){
		rep(j,1,5){
			if(a[i][j]==0 and a[i+1][j]==0){
				cout<<i<<" "<<j<<endl;
				a[i][j]=1;
				a[i+1][j]=1;
				balance();
				return;
			}
		}
	}
}
void get_horizontal(){
	rep(i,3,5){
		rep(j,1,5){
			if(a[i][j]==0 and a[i][j+1]==0){
				cout<<i<<" "<<j<<endl;
				a[i][j]=1;
				a[i][j+1]=1;
				balance();
				return;
			}
		}
	}
}
void solve(){
    cin>>s;
    for(auto i:s){
    	if(i=='0') get_vertical();
    	else get_horizontal();
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