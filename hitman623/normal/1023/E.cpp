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
int n,midx,midy;
bool query(int x1,int y1,int x2,int _y2){
	string s;
	cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<_y2<<endl;
	cin>>s;
	fflush(stdout);
	return s=="YES";
}
vii path1,path2;
void sol1(int ax,int ay,int bx,int by){
	if(abs(bx-ax)+abs(by-ay)==n-1){
		midx=bx;
		midy=by;
		return;
	}
	if(bx>1 and query(ax,ay,bx-1,by)){
		path1.pb({bx-1,by});
		sol1(ax,ay,bx-1,by);
		return;
	}
	else{
		path1.pb({bx,by-1});
		sol1(ax,ay,bx,by-1);
		return;
	}
}
void sol2(int ax,int ay,int bx,int by){
	if(abs(bx-ax)+abs(by-ay)==n-1){
		return;
	}
	if(ay<n and query(ax,ay+1,bx,by)){
		path2.pb({ax,ay+1});
		sol2(ax,ay+1,bx,by);
		return;
	}
	else{		
		path2.pb({ax+1,ay});
		sol2(ax+1,ay,bx,by);
		return;
	}
}
string ans;
void solve(){
	cin>>n;
	path1.pb({n,n});
	sol1(1,1,n,n);
	path2.pb({1,1});
	sol2(1,1,n,n);
	reverse(all(path1));
	rep(i,0,sz(path2)-1){
		if(path2[i+1].x==path2[i].x){
			ans+='R';
		}
		else ans+='D';
	}
	rep(i,0,sz(path1)-1){
		if(path1[i+1].x==path1[i].x){
			ans+='R';
		}
		else ans+='D';
	}
	cout<<"! "<<ans<<endl;
}

signed main(){
	int t=1;
    // cin>>t;
	while(t--){
		solve();
	}
	return 0;
}