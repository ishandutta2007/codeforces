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
char query(int x,int y){
	cout<<"? "<<x<<" "<<y<<endl;
	char ch;
	cin>>ch;
	return ch;
}
void solve(){
    string s;
    while(cin>>s and s=="start"){
    	int lo=0,hi=0;
    	rep(i,-1,30){
    		if(query(max(0,1<<i),1<<(i+1))=='x'){
    			lo=1<<i;
    			hi=1<<(i+1);
    			break;
    		}
    	}
    	while(hi-lo>1){
    		int mid=(lo+hi)/2;
    		if(query(mid,mid/2)=='x') lo=mid;
    		else hi=mid;
    	}
    	cout<<"! "<<hi<<endl;
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