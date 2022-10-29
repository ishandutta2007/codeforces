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
#define left 		l
#define right		r
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,diff,left,right;
string s;
void solve(){
    cin>>n>>s;
    rep(i,0,n){
    	if(s[i]=='?'){
    		if(i<n/2) left++;
    		else right++;
    	}
    	else if(i<n/2) diff+=s[i]-'0';
    	else diff-=s[i]-'0';
    }
    if(left>right){
    	left-=right;
    	if(diff>=0) cout<<"Monocarp"<<endl;
    	else if(9*(left/2)==-diff) cout<<"Bicarp"<<endl;
    	else cout<<"Monocarp"<<endl;
    }
    else if(right>left){
    	right-=left;
    	if(diff<=0) cout<<"Monocarp"<<endl;
    	else if(9*(right/2)==diff) cout<<"Bicarp"<<endl;
    	else cout<<"Monocarp"<<endl;
	}
	else{
		if(diff==0) cout<<"Bicarp"<<endl;
		else cout<<"Monocarp"<<endl;
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