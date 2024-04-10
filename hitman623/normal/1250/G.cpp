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
#define bb          __builtin_popcount
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,n1,n2,f[1<<14][14][1<<7];
ll ans[1<<13];
string a[14];
int get(int mask,int last,int s){
	if(!mask) return 1;
	int &an=f[mask][last][s];
	if(an!=-1) return an;
	an=0;
	rep(i,0,n) if((mask>>i)&1 and s%2==a[last][i]-'0') an+=get(mask^(1<<i),i,s/2);
	return an;
}
void solve(){
	memset(f,-1,sizeof f);
    cin>>n;
    rep(i,0,n) cin>>a[i];
    n1=n/2+1;
    n2=n-n1+1;
    rep(i,0,1<<n){
    	if(bb(i)==n1){
    		int mask1=i;
    		int mask2=(1<<n)-1-i;
    		rep(j,0,n){
    			if((mask1>>j)&1){
    				rep(k,0,1<<(n-1)){
    					ans[k]+=1LL*get(mask1^(1<<j),j,k>>(n2-1))*get(mask2,j,k%(1<<(n2-1)));
    				}
    			}
    		}
    	}
    }
    rep(i,0,1<<(n-1)){
    	int m1=i,m2=0;
    	int w=i%(1<<(n2-1));
    	rep(j,0,n2-1){
    		m2=m2*2+w%2;
    		w/=2;
    	}
    	m2|=(m1>>(n2-1))<<(n2-1);
    	if(m1<m2) swap(ans[m1],ans[m2]); 
    }
    rep(i,0,1<<(n-1)) cout<<ans[i]<<" ";
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