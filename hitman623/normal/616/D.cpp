#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii 		vector<pii>
#define mi 			map<int,int>
#define mii			map<int,pii>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000000007LL
#define endl        '\n'
#define rep(i,a,b)	for(int i=a;i<b;i++)
using namespace std;
int n,k,a[500005],mp[1000006],S=0;
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        cin>>a[i];
    }
    int cur1=0,cur2=0;
    while(cur2<n && S<=k){
        mp[a[cur2]]++;
        if(mp[a[cur2]]==1) S++;
        if(S<=k)
        cur2++;
    }
    int l=cur1,r=cur2;
    while(cur2<n){
        while(cur1<n && S>k){
            mp[a[cur1]]--;
            if(mp[a[cur1]]==0) S--;
            cur1++;
        }
        while(cur2<n && S<=k){
            cur2++;
            mp[a[cur2]]++;
            if(mp[a[cur2]]==1) S++;
        }
        if(cur2-cur1>r-l) l=cur1,r=cur2;
    }
    cout<<l+1<<" "<<r<<endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int t=1;
//	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}