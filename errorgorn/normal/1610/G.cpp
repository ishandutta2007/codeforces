//
//

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

string solve(string s){
	vector<deque<char> > v;
	string ans="";
	
	rep(x,0,sz(s)){
		if (s[x]=='('){
			v.pub({'('});
		}
		else{
			deque<char> temp;
			
			bool added=false;
			while (!v.empty()){
				if (sz(v.back())==1){
					temp.puf('(');
					temp.pub(')');
					
					v.pob();
					
					//kill anyone in front here
					while (true){
						// for (auto &it:v.back()) cout<<it;
						// cout<<" ";
						// for (auto &it:temp) cout<<it;
						// cout<<endl;
						
						if (v.empty()){
							v.pub(temp);
							break;
						}
						
						int idx=0;
						while (idx<sz(v.back()) && idx<sz(temp) && 
								v.back()[idx]==temp[idx]) idx++;
								
						if (idx==sz(v.back()) || idx==sz(temp) || temp[idx]==')'){
							// cout<<"adding: ";
							// for (auto &it:temp) cout<<it;
							// cout<<endl;
							
							//DEQUE INSERTION IS A DEEP COPY
							v.pub({});
							swap(temp,v.back());
							break;
						}
						else{
							v.pob();
						}
					}
					
					added=true;
					break;
				}
				else{
					if (sz(v.back())<sz(temp)){
						rep(x,sz(v.back()),0){
							temp.puf(v.back()[x]);
						}
					}
					else{
						swap(temp,v.back());
						rep(x,0,sz(v.back())){
							temp.pub(v.back()[x]);
						}
					}
					v.pob();
				}
			}
			
			if (!added){
				for (auto &it:temp) ans+=it;
				ans+=')';
			}
		}
		
		// cout<<"debug: "<<ans<<endl;
		// for (auto &it:v) {for (auto &it2:it) cout<<it2; cout<<" ";} cout<<endl;
	}
	
	while (!v.empty()){
		if (sz(v.back())==1) ans+='(';
		v.pob();
	}
	
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	string s;
	cin>>s;
	
	cout<<solve(s)<<endl;
}