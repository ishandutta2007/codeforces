// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int a,b,c,d;
string s;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>a>>b>>c>>d;
		cin>>s;
		
		int cnta=0;
		for (auto it:s) if (it=='A') cnta++;
		
		if (cnta!=a+c+d){
			cout<<"NO"<<endl;
			continue;
		}
		
		int curr=0;
		s+=s.back();
		
		vector<int> vc,vd;
		int tot=0;
		rep(x,0,sz(s)){
			if (s[x]==s[x+1]){
				//cout<<curr<<" "<<x<<endl;
				int len=x-curr+1;
				
				if (len%2==0){
					if (s[curr]=='A') vc.pub(len/2);
					else vd.pub(len/2);
				}
				tot+=(len-1)/2;
				
				curr=x+1;
			}
		}
		
		sort(all(vc)); reverse(all(vc));
		sort(all(vd)); reverse(all(vd));
		
		int C=c,D=d;
		while (!vc.empty() && vc.back()<=c){
			c-=vc.back();
			vc.pob();
			tot++;
		}
		while (!vd.empty() && vd.back()<=d){
			d-=vd.back();
			vd.pob();
			tot++;
		}
		
		if (tot>=C+D) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}