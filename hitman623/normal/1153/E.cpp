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
using namespace std;
int n;
vi col,row;
int query(int ax,int ay,int bx,int by){
	if(ax>bx) swap(ax,bx);
	if(ay>by) swap(ay,by);
	cout<<"? "<<ax<<" "<<ay<<" "<<bx<<" "<<by<<endl;
	cin>>ax;
	return ax;
}
void solve(){
    cin>>n;
    int f=1;
    for(int i=n-1;i>=1;i--){
	    int w=query(1,1,n,i);
	    if(w%2==f) col.pb(i+1),f^=1;
    }
    if(f==0) col.pb(1),f=1;
    for(int i=n-1;i>=1;i--){
	    int w=query(1,1,i,n);
	    if(w%2==f) row.pb(i+1),f^=1;
    }
    if(f==0) row.pb(1),f=1;
    sort(all(row));
    sort(all(col));
    if(sz(row)==2 and sz(col)==2){
    	if(query(row[0],col[0],row[0],col[0])%2 and query(row[1],col[1],row[1],col[1])%2){
    		cout<<"! "<<row[0]<<" "<<col[0]<<" "<<row[1]<<" "<<col[1]<<endl;
    	}
    	else{	
    		cout<<"! "<<row[0]<<" "<<col[1]<<" "<<row[1]<<" "<<col[0]<<endl;
    	}
    }
    else if(sz(row)==2){
    	int lo=1,hi=n;
    	while(hi-lo>1){
    		int mid=(lo+hi)/2;
    		if(query(row[0],1,row[0],mid)%2) hi=mid;
    		else lo=mid;
    	}
    	if(query(row[0],1,row[0],lo)%2) col.pb(lo);
    	else if(query(row[0],1,row[0],hi)) col.pb(hi);
    	cout<<"! "<<row[0]<<" "<<col[0]<<" "<<row[1]<<" "<<col[0]<<endl;
    }
    else if(sz(col)==2){
    	int lo=1,hi=n;
    	while(hi-lo>1){
    		int mid=(lo+hi)/2;
    		if(query(1,col[0],mid,col[0])%2) hi=mid;
    		else lo=mid;
    	}
    	if(query(1,col[0],lo,col[0])%2) row.pb(lo);
    	else if(query(1,col[0],hi,col[0])) row.pb(hi);
    	cout<<"! "<<row[0]<<" "<<col[0]<<" "<<row[0]<<" "<<col[1]<<endl;
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