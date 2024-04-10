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
int n,f[3];
string s;
void solve(){
    cin>>n>>s;
    for(auto i:s) f[i-'0']++;
    for(auto &i:s){
    	if(f[i-'0']>n/3){
    		rep(j,0,3){
    			if(f[j]<n/3 and j<i-'0'){
    				f[i-'0']--;
    				f[j]++;
    				i=j+'0';
    				break;
    			}
    		}
    	}
    }
    reverse(all(s));
    for(auto &i:s){
    	if(f[i-'0']>n/3){
    		for(int j=2;j>=0;j--){
    			if(f[j]<n/3 and j>i-'0'){
    				f[i-'0']--;
    				f[j]++;
    				i=j+'0';
    				break;
    			}
    		}
    	}
    }
    reverse(all(s));
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