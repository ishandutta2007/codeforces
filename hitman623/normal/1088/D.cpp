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
int query(int c,int d){
	cout<<"? "<<c<<" "<<d<<endl;
	cin>>c;
	return c;
}
void sol(int bit,int c,int d,int cur){
	if(bit==-1){
		cout<<"! "<<c<<" "<<d<<endl;
		return;
	}
	int q1=query(c^(1<<bit),d);
	int q2=query(c,d^(1<<bit));
	if(q1<0 and q2>0) sol(bit-1,c^(1<<bit),d^(1<<bit),cur);
	else if(q1>0 and q2<0) sol(bit-1,c,d,cur);
	else if(cur<0) sol(bit-1,c,d^(1<<bit),q1);
	else sol(bit-1,c^(1<<bit),d,q1);
}
void solve(){
    sol(29,0,0,query(0,0));
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