#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long ll;
int n,len,wmax;
ll ans;
vector<int> L,R;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>len>>wmax;
	for(int i=1;i<=n;++i){
		int x,v;
		cin>>x>>v;
		if(v>0)L.push_back(x);
		else R.push_back(x);
	}
	sort(L.begin(),L.end());
	sort(R.begin(),R.end());
	for(int i=0,j=0;i<(int)L.size();++i){
		while(j<(int)R.size()&&llabs((ll)L[i]+R[j]+len)>=1LL*wmax*((ll)R[j]-L[i]+len))++j;
		ans+=(int)R.size()-j;
	}
	cout<<ans<<'\n'; 
	return 0;
}