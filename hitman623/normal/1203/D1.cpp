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
string s,t;
int pre[200005];
int suf[200005];
bool check(int mid){
	rep(i,0,sz(s)-mid+1){
		int d=(i?pre[i-1]:0)+suf[i+mid];
		if(d>=sz(t)) return 1;
	}
	return 0;
}
void solve(){
    cin>>s>>t;
    int cur=0;
    rep(i,0,sz(s)){
    	if(cur<sz(t) and s[i]==t[cur]) cur++;
    	pre[i]=cur;
    }
    cur=sz(t)-1;
    for(int i=sz(s)-1;i>=0;i--){
    	if(cur>=0 and s[i]==t[cur]) cur--;
    	suf[i]=sz(t)-cur-1;
    }
    int lo=0,hi=sz(s);
    while(hi-lo>1){
    	int mid=(lo+hi)/2;
    	if(check(mid)) lo=mid;
    	else hi=mid;
    }
    cout<<lo<<endl;
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