#include<bits/stdc++.h>
using namespace std;
#define N 888
typedef long long ll;
int n,a[N],g[N],mod,pos[N];
inline int Ask(vector<int> A){
	cout<<"? "<<A.size();
	for(auto x:A)cout<<" "<<x;
	cout<<endl;
	int t;cin>>t;
	return t;
}
vector<int> D(vector<int> a,int x){
	a.erase(lower_bound(a.begin(),a.end(),x));
	return a;	
}
void Find(int l,int r){
	vector<int> v;
	for(int i=1;i<=n;++i)if(!a[i])v.push_back(i);
	for(int i=1;i<=n;++i){
		if(!a[i]&&g[i]==l%mod&&Ask(D(v,i))){
			a[i]=l;pos[l]=i;break;
		}
	}
	for(int i=1;i<=n;++i){
		if(!a[i]&&g[i]==r%mod&&Ask(D(v,i))){
			a[i]=r;pos[r]=i;break;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	if(n==2){
		cout<<"! "<<1<<" "<<2<<endl;return 0;
	}
	mod=1;
	Find(1,n);
	mod=2;
	for(int i=1;i<=n;++i){
		if(!a[i])g[i]=Ask({pos[1],i});
	}
	for(int i=2;(i<<1)<=n;++i){
		Find(i,n-i+1);
		if(i==(mod<<1)){
			for(int j=1;j<=n;++j){
				if(!a[j]){
					vector<int> tmp({j});
					for(int k=1;k<=(mod<<1);++k){
						if(k%(mod<<1)!=g[j])tmp.push_back(pos[k]);
					}
					if(Ask(tmp))g[j]+=mod;
				}	
			}
			mod<<=1;		
		}
	}
	if(a[1]>n/2){
		for(int i=1;i<=n;++i)a[i]=n+1-a[i];
	}
	cout<<"! ";
	for(int i=1;i<=n;++i)cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}