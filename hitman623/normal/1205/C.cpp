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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define y1 dsfdf
#define y2 dsf
using namespace std;
int n;
int query(int x1,int y1,int x2,int y2){
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	cin>>x1;
	return x1;
}
int vis[55][55],a[55][55];
void dfs(int x,int y){
	vis[x][y]=1;
	if(x+2<=n and vis[x+2][y]==0){
		a[x+2][y]=a[x][y]^query(x,y,x+2,y)^1;
		dfs(x+2,y);
	}
	if(y+2<=n and vis[x][y+2]==0){
		a[x][y+2]=a[x][y]^query(x,y,x,y+2)^1;
		dfs(x,y+2);
	}
	if(x+1<=n and y+1<=n and vis[x+1][y+1]==0){
		a[x+1][y+1]=a[x][y]^query(x,y,x+1,y+1)^1;
		dfs(x+1,y+1);
	}
}
void flip(){
	rep(i,1,n+1){
		rep(j,1,n+1){
			if((i+j)%2) a[i][j]^=1;
		}
	}
}
void disp(){
	cout<<"!"<<endl;
	rep(i,1,n+1){
		rep(j,1,n+1){
			cout<<a[i][j];
		}
		cout<<endl;
	}
	exit(0);
}

void solve(){
	cin>>n;
	a[1][1]=1;
	a[n][n]=0;
	vis[n][n]=1;
	dfs(1,1);
	a[1][2]=0;
	dfs(1,2);
	for(int i=2;i<=n;i+=2){
		if(query(i,1,i+1,2)) a[i][1]=a[i+1][2];
		else a[i][1]=a[i+1][2]^1;
	}
	rep(i,1,n+1){
		rep(j,1,n+1){
			if(i+2<=n and j+1<=n and a[i][j]==a[i+2][j+1] and a[i+1][j]==a[i+2][j]){
				if(query(i,j,i+2,j+1));
				else flip();
				disp();
			}
			if(i+2<=n and j+1<=n and a[i][j]==a[i+2][j+1] and a[i][j+1]==a[i+1][j+1]){
				if(query(i,j,i+2,j+1));
				else flip();
				disp();
			}
			if(i+1<=n and j+2<=n and a[i][j]==a[i+1][j+2] and a[i+1][j]==a[i+1][j+1]){
				if(query(i,j,i+1,j+2));
				else flip();
				disp();
			}
			if(i+1<=n and j+2<=n and a[i][j]==a[i+1][j+2] and a[i][j+1]==a[i][j+2]){
				if(query(i,j,i+1,j+2));
				else flip();
				disp();
			}
		}
	}
	flip();
	rep(i,1,n+1){
		rep(j,1,n+1){
			if(i+2<=n and j+1<=n and a[i][j]==a[i+2][j+1] and a[i+1][j]==a[i+2][j]){
				if(query(i,j,i+2,j+1));
				else flip();
				disp();
			}
			if(i+2<=n and j+1<=n and a[i][j]==a[i+2][j+1] and a[i][j+1]==a[i+1][j+1]){
				if(query(i,j,i+2,j+1));
				else flip();
				disp();
			}
			if(i+1<=n and j+2<=n and a[i][j]==a[i+1][j+2] and a[i+1][j]==a[i+1][j+1]){
				if(query(i,j,i+1,j+2));
				else flip();
				disp();
			}
			if(i+1<=n and j+2<=n and a[i][j]==a[i+1][j+2] and a[i][j+1]==a[i][j+2]){
				if(query(i,j,i+1,j+2));
				else flip();
				disp();
			}
		}
	}
}

signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}