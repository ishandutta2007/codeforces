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
int n,q,sum;
string s;
void solve(){
	cin>>n>>s;
	for(auto i:s){
		if(i=='?') q++;
		else sum+=(i=='(')-(i==')');
	}
    // o+c=q
    // o-c+s=0
	if((q-sum)%2 or q-sum<0){
		cout<<":(";
		return;
	}
	int o=(q-sum)/2;
	int c=q-o;
	if(c<0){
		cout<<":(";
		return;    	
	}
	rep(i,0,n){
		if(s[i]=='?'){
			if(o){
				s[i]='(';
				o--;
			}
			else{
				s[i]=')';
			}
		}
	}
	int cur=0;
	rep(i,0,n){
		if(s[i]=='(') cur++;
		else cur--;
		if(cur<0 or (cur==0 and i!=n-1)){
			cout<<":(";
			return;
		}
	}
	if(cur){
		cout<<":(";
		return;		
	}
	cout<<s<<endl;
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