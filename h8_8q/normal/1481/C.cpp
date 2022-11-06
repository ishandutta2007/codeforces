#include <bits/stdc++.h>
 
using namespace std;
#define ll long long int
#define pb push_back
#define endl "\n"
 
int main() {
 
    //forItachiOfTheLeaf
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
    	ll n , m;
    	cin>>n>>m;
    	vector<ll> a(n);
    	vector<ll> b(n);
    	ll i;
    	for(i=0;i<n;i++){
    		cin>>a[i];
    	}
    	for(i=0;i<n;i++){
    		cin>>b[i];
    	}
    	vector<stack<ll>> v(n+5);
    	vector<ll> c(m);
    	for(i=0;i<m;i++){
    		cin>>c[i];
    		v[c[i]].push(i+1);
    	}
    	ll last = -1,rem = -1;
    	bool con = true;
    	vector<ll> ans(m , -1);
    	for(i=0;i<n;i++){
    		if(a[i]!=b[i]){
    			if(v[b[i]].empty()==true){
    				con = false;
    				break;
    			}
    			else{
    				ll temp = v[b[i]].top();
    				ans[temp-1] = i+1;
    				v[b[i]].pop();
    				if(temp>last){
    					last = temp;
    					rem = i+1;
    				}
 
    			}
    		}
    	}
    	if(con == false){
    		//cout<<"here"<<endl;
    		cout<<"NO"<<endl;
    	}
    	else{
    		ll afterlast = -1 , rem2 = -1;
    		for(i=1;i<=n;i++){
    			if(v[i].empty()==false){
    				ll temp = v[i].top();
    				if(temp>last){
    					if(temp>afterlast){
    						afterlast = temp;
    						rem2 = i;
    					}
    				}
    			}
    		}
    		//cout<<last<<" "<<afterlast<<" "<<rem2<<endl;
    		if(afterlast==-1){
    			cout<<"YES"<<endl;
    			for(i=0;i<m;i++){
    				if(ans[i]==-1){
    					cout<<rem<<" ";
    				}
    				else{
    					cout<<ans[i]<<" ";
    				}
    			}
    			cout<<endl;
    		}
    		else{
    			ll ansrem = -1;
    			for(i=0;i<n;i++){
    				if(a[i]==b[i]&&a[i]==rem2){
    					ansrem = i+1;
    					break;
    				}
    			}
    			if(ansrem==-1){
    				cout<<"NO"<<endl;
    			}
    			else{
    				cout<<"YES"<<endl;
    				for(i=0;i<m;i++){
    				if(ans[i]==-1){
    					cout<<ansrem<<" ";
    				}
    				else{
    					cout<<ans[i]<<" ";
    				}
    			}
    			cout<<endl;
    			}
    			
 
    		}
    	}
 
    }
 
}