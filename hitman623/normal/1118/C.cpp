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
int n,a[10001],f[10001],cnt4,cnt2,cnt1,b[1001][1001];
vi fours,twos,ones;
void solve(){
    cin>>n;
    rep(i,0,n*n) cin>>a[i],f[a[i]]++;
    int m=(n/2)*(n/2);
    rep(i,1,1001){
    	int temp=f[i];
    	rep(j,0,f[i]/4) fours.pb(i);
    	cnt4+=f[i]/4;
    	f[i]%=4;
    	rep(j,0,f[i]/2) twos.pb(i);
    	cnt2+=f[i]/2;
    	f[i]%=2;
    	rep(j,0,f[i]) ones.pb(i);
    	cnt1+=f[i];
    	f[i]=temp;
    }
    if(n%2==0 and cnt1){
    	cout<<"No"<<endl;
    	return;
    }
    if(n%2 and cnt1>1){
    	cout<<"No"<<endl;
    	return;
    }
    if(cnt2>n-1){
    	cout<<"No"<<endl;
    	return;
    }
    if(cnt4<m){
    	cout<<"No"<<endl;
    	return;
    }
    rep(i,0,m){
    	b[(i/(n/2))][i%(n/2)]=fours.back();
    	fours.pop_back();
    }
    while(sz(fours)){
    	twos.pb(fours.back());
    	twos.pb(fours.back());
    	fours.pop_back();
    }
    if(n%2){
    	rep(i,0,n/2){
    		b[n/2][i]=twos.back();
    		twos.pop_back();
    	}
    	rep(i,0,n/2){
    		b[i][n/2]=twos.back();
    		twos.pop_back();
    	}
    	b[n/2][n/2]=ones[0];
    }
    cout<<"Yes"<<endl;
    rep(i,0,n){
    	rep(j,0,n){
    		cout<<b[min(i,n-i-1)][min(j,n-j-1)]<<" ";
    	}
    	cout<<endl;
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