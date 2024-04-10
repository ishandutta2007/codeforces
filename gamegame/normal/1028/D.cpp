#include<iostream>
#include<set>
#include<vector>
using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll ans=1;
int q;
set<pair<int,int> >s;
int a[400001];
int mini[1048576],maxi[1048576];
vector<pair<pair<int,int>,int> >v;
void build(int id,int l,int r){
	if(l==r){
		if(a[l]==-1){
			mini[id]=1e9;
			maxi[id]=0;
		}
		else mini[id]=maxi[id]=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	mini[id]=min(mini[id*2],mini[id*2+1]);
	maxi[id]=max(maxi[id*2],maxi[id*2+1]);
}
int qmin(int id,int l,int r,int ll,int rr){
	if(l>rr || r<ll) return 1e9;
	if(ll<=l && r<=rr) return mini[id];
	int mid=(l+r)/2;
	return min(qmin(id*2,l,mid,ll,rr),qmin(id*2+1,mid+1,r,ll,rr));
}
int qmax(int id,int l,int r,int ll,int rr){
	if(l>rr || r<ll) return 0;
	if(ll<=l && r<=rr) return maxi[id];
	int mid=(l+r)/2;
	return max(qmax(id*2,l,mid,ll,rr),qmax(id*2+1,mid+1,r,ll,rr));
}
int main(){
	ios::sync_with_stdio(false);
	int lastv=0;
	int lastx=0;
	cin >> q;
	for(int i=1; i<=q ;i++){
		string t;
		cin >> t;
		int x;
		cin >> x;
		if(t.size()==3){
			a[i]=-1;
			s.insert({x,i});
		}
		else{
			a[i]=x;
			lastv=i;
			lastx=x;
			auto it=s.lower_bound({x,0});
			v.push_back({{it->second,i},x});
			s.erase(it);
		}
	}
	build(1,1,q);
	if(lastv==0){
		cout << q+1 << endl;
		return 0;
	}
	for(auto cur:v){
		int mi=qmin(1,1,q,cur.first.first,cur.first.second-1),ma=qmax(1,1,q,cur.first.first,cur.first.second-1);
		if(mi<cur.second && ma>cur.second){
			cout << 0 << endl;
			return 0;
		}
		if(mi>cur.second && ma<cur.second) ans=ans*2%mod;
	}
	int mini=0,maxi=1e9;
	for(auto it=s.begin(); it!=s.end() ;++it){
		if(it->second<lastv){
			int mi=qmin(1,1,q,it->second,q),ma=qmax(1,1,q,it->second,q);
			if(mi<it->first && ma>it->first){
				cout << 0 << endl;
				return 0;
			}
			if(it->first<lastx) mini=max(mini,it->first);
			else maxi=min(maxi,it->first);
			if(mi>it->first && ma<it->first) ans=ans*2%mod;
		}
	}
	int cnt=1;
	for(auto it=s.begin(); it!=s.end() ;++it){
		if(it->second>lastv){
			if(it->first>mini && it->first<maxi) cnt++;
		}
	}
	cout << ans*cnt%mod << endl;
}