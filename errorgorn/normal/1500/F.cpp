//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
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

int n,k;
int arr[1000005];
int back[1000005];
//-2 means previous has arr[x]
//-1 means top guy has nothing
//x means top guy reflects back to x

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	rep(x,0,n-2) cin>>arr[x];
	
	memset(back,-1,sizeof(back));
	
	deque<ii> dq={{0,arr[0]}};
	int glob=0;
	//real values are x+glob
	
	rep(x,0,n-2){
		int check=(x%2==0?arr[x]:-arr[x]);
		//[l,r] inside dq such that l<=check<=r
		auto it=lower_bound(all(dq),ii(check-glob+1,-1e18));
		if (it!=dq.begin() && (*prev(it)).fi<=check-glob && check-glob<=(*prev(it)).se){
			back[x]=-2;
			if (x%2==0) dq={{-arr[x]-glob,0-glob}};
			else dq={{0-glob,arr[x]-glob}};
		}
		else{
			if (x%2==0){
				if (arr[x] < dq.front().fi+glob){
					cout<<"NO"<<endl;
					return 0;
				}
				back[x]=dq.front().fi+glob;
				
				glob-=arr[x];
				while (!dq.empty() && 0<dq.back().se+glob){
					if (0<dq.back().fi+glob) dq.pob();
					else dq.back().se=-glob;
				}
				
				if (dq.front().fi+glob!=-arr[x]) dq.puf({-arr[x]-glob,-arr[x]-glob});
			}
			else{
				if (dq.back().se+glob < -arr[x]){
					cout<<"NO"<<endl;
					return 0;
				}
				back[x]=-(dq.back().se+glob);
				
				glob+=arr[x];
				
				while (!dq.empty() && dq.front().fi+glob<0){
					if (dq.front().se+glob<0) dq.pof();
					else dq.front().fi=-glob;
				}
				
				if (dq.back().se+glob!=arr[x]) dq.pub({arr[x]-glob,arr[x]-glob});
			}
		}
	}
	
	//rep(x,0,n-2) cout<<back[x]<<" "; cout<<endl;
	
	vector<int> ans={0,dq[0].fi+glob};
	rep(x,n-2,0){
		int diff=abs(ans[sz(ans)-2]-ans.back());
		int dir=ans[sz(ans)-2]<ans.back();
		
		if (back[x]==-2){
			if (dir) ans.pub(ans.back()-arr[x]);
			else ans.pub(ans.back()+arr[x]);
		}
		else if (back[x]!=-1 && diff==arr[x]){
			if (dir) ans.pub(ans.back()-back[x]);
			else ans.pub(ans.back()+back[x]);
		}
		else{
			if (dir) ans.pub(ans.back()+(arr[x]-diff));
			else ans.pub(ans.back()-(arr[x]-diff));
		}
	}
	
	reverse(all(ans));
	int mn=*min_element(all(ans));
	
	cout<<"YES"<<endl;
	for (auto it:ans) cout<<it-mn<<" "; cout<<endl;
}