    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define ii pair<ll,ll>
    #define iii pair<ll,ii>
    #define endl '\n'
     
    int n,q,m;
     
    int arr[200005];
    vector<iii> v;
    int pos[105];
     
    int main(){
    	ios::sync_with_stdio(0);
        cin.tie(0);
    	
    	cin>>n>>q>>m;
    	
    	for (int x=1;x<=n;x++) cin>>arr[x];
    	
    	int a,b,c;
    	for (int x=0;x<q;x++){
    		cin>>a>>b>>c;
    		v.push_back(iii(a,ii(b,c)));
    	}
    	
    	reverse(v.begin(),v.end());
    	
    	for (int x=0;x<m;x++) cin>>pos[x];
    	
    	for (auto &it:v){
    		for (int x=0;x<m;x++){
    			if (it.first==1){
    				if (pos[x]==it.second.first) pos[x]=it.second.second;
    				else if (it.second.first<=pos[x] && pos[x]<=it.second.second) pos[x]--;
    			}
    			else{
    				if (it.second.first<=pos[x] && pos[x]<=it.second.second)
    					pos[x]=it.second.second-(pos[x]-it.second.first);
    			}
    		}
    	}
    	
    	for (int x=0;x<m;x++) cout<<arr[pos[x]]<<" ";
    }