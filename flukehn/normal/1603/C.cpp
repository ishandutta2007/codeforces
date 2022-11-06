#include<bits/stdc++.h>
using namespace std;
const int mo=998244353;
const int N=1e5+11;
int a[N];
int n;
int work(){
	long long ans=0;
	//unordered_map<int,int> f;
	//map<int,int> f;
	vector<pair<int,int> >f;
	for(int i=n;i>=1;--i){
		auto g=f;
		f.clear();
		int tot=n-i;
		for(auto w:g){
			int t=w.first;
			if(t>=a[i]){
				break;
			}
			ans += 1ll*(a[i]-1)/t * i %mo * w.second % mo;
			
			t=a[i]/((a[i]+t-1)/t);
			
			tot-=w.second;
			if(!f.empty() && f.back().first==t)
				f.back().second+=w.second;
			else
				f.emplace_back(t,w.second);
		}
	//	long long s=0;
		/*for(int i=r-1;i>=1;--i){
			ans += 1ll * (a[i]-1)/t * i % mo;
			if(a[i]<=t)t=a[i];
			else t=min(t-(a[i]%t>0),a[i]/2);
		
		}*/
		f.emplace_back(a[i],tot+1);
		//f[a[i]]+=1+tot;
		//cerr<<l<<" "<<r<<" "<<s<<endl;
		
	}
	return ans%mo;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
	cin>>T;
	while(cin>>n){
		for(int i=1;i<=n;++i)cin>>a[i];
		cout<<work()<<"\n";
	}
}