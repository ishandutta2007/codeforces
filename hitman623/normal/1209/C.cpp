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
int n,col[200005];
string s;
void solve(){
    cin>>n>>s;
    if(is_sorted(all(s))){
    	rep(i,0,n) cout<<1;
    	cout<<endl;
    	return;
    }
    rep(i,0,10){
    	string s1,s2;
    	int last=-1,firs=-1,f=1;
    	rep(j,0,n){
    		if(s[j]-'0'<i) s1+=s[j],col[j]=1,last=j;
    		else if(s[j]-'0'>i){
    			s2+=s[j],col[j]=2;
    			if(firs==-1) firs=j;
    		}
    	}
    	rep(j,0,n){
    		if(s[j]-'0'==i){
    			if(j>last) col[j]=1;
    			else if(j<firs) col[j]=2;
    			else f=0;
    		}
    	}
    	if(f and is_sorted(all(s1)) and is_sorted(all(s2))){
    		rep(j,0,n) cout<<col[j];
    		cout<<endl;
    		return;
    	}
    }
    cout<<'-'<<endl;
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