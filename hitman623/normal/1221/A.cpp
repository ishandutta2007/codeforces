#include <bits/stdc++.h>

#define int         long long
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
int n;
void solve(){
    cin>>n;
    priority_queue<int,vi,greater<int>> pq;
    rep(i,0,n){
    	int x;
    	cin>>x;
    	pq.push(x);
    }
    while(!pq.empty()){
    	int d=pq.top();
    	pq.pop();
    	if(d==2048){
    		cout<<"Yes"<<endl;
    		return;
    	}
    	if(pq.empty()) break;
    	int dd=pq.top();
    	pq.pop();
    	if(dd==2048){
    		cout<<"Yes"<<endl;
    		return;
    	}
    	if(d==dd) pq.push(d+dd);
    	else pq.push(dd);
    }
    cout<<"No"<<endl;
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