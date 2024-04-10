#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n;
string s;
vector<int> v1,v2,v3;
int num,supA,supB;
ll ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>s>>x;
		if(s=="11"){
			num++;
			supA++;
			supB++;
			ans+=x;
		}else if(s=="01"){
			v1.pb(x);
		}else if(s=="10"){
			v2.pb(x);
		}else{
			v3.pb(x);
		}
	}
	sort(v1.begin(),v1.end(),greater<int>());
	sort(v2.begin(),v2.end(),greater<int>());
	int n2 = min(v1.size(),v2.size());
	for(int i=0;i<n2;i++){
		num+=2;
		supA++;
		supB++;
		ans+=v1[i];
		ans+=v2[i];
	}
	for(int i=n2;i<v1.size();i++) v3.pb(v1[i]);
	for(int i=n2;i<v2.size();i++) v3.pb(v2[i]);
	sort(v3.begin(),v3.end(),greater<int>());
	for(int i=0;i<v3.size();i++){
		if(supA*2 > num){
			num++;
			ans+=v3[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}