// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
int arr[55][55];

int ask(int x1,int y1,int x2,int y2){
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	int temp;
	cin>>temp;
	return temp;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	arr[1][1]=1;
	
	rep(x,1,n+1) rep(y,1,n+1) if ((x+y)%2==0){
		if (x+y==2) continue;
		
		if (y==1){
			arr[x][y]=arr[x-2][y];
			if (!ask(x-2,y,x,y)) arr[x][y]^=1;
		}
		else if (y==2){
			arr[x][y]=arr[x-1][y-1];
			if (!ask(x-1,y-1,x,y)) arr[x][y]^=1;
		}
		else{
			arr[x][y]=arr[x][y-2];
			if (!ask(x,y-2,x,y)) arr[x][y]^=1;
		}
	}
	
	rep(y,4,n+1) if ((1+y)%2==1){
		arr[1][y]=arr[1][y-2];
		if (!ask(1,y-2,1,y)) arr[1][y]^=1;
	}
	rep(x,2,n+1){
		rep(y,n+1,2) if ((x+y)%2==1){
			arr[x][y]=arr[x-1][y-1];
			if (!ask(x-1,y-1,x,y)) arr[x][y]^=1;
		}
		if ((x+1)%2==1){
			arr[x][1]=arr[x][3];
			if (!ask(x,1,x,3)) arr[x][1]^=1;
		}
	}
	
	vector<ii> v;
	rep(x,1,n+1) v.pub({1,x});
	rep(x,2,n+1) v.pub({x,n});
	
	int curr=0;
	rep(x,0,4) curr^=arr[v[x].fi][v[x].se];
	
	int X=0;
	rep(x,0,sz(v)-3){
		if (curr==0){
			if (ask(v[x].fi,v[x].se,v[x+3].fi,v[x+3].se) != (arr[v[x].fi][v[x].se]==arr[v[x+3].fi][v[x+3].se])){
				X=1;
			}
			break;
		}
		
		curr^=arr[v[x].fi][v[x].se];
		curr^=arr[v[x+4].fi][v[x+4].se];
	}
	
	rep(x,1,n+1) rep(y,1,n+1) if ((x+y)%2==1) arr[x][y]^=X;
	
	cout<<"!"<<endl;
	rep(x,1,n+1){
		rep(y,1,n+1) cout<<arr[x][y];
		cout<<endl;
	}
}