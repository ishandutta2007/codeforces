#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m,k;
deque<pair<int,int> >v,f,l;
vector<pair<int,int> >fin;
int a[100001];
ll ans;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> m;
	v.push_back(make_pair(0,0));
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(a[i]!=v.back().first) v.push_back(make_pair(a[i],1));
		else{
			v.back().second++;
			if(v.back().second==k) v.pop_back();
		}
	}
	if(m==1){
		int ans=0;
		for(int i=1; i<v.size() ;i++) ans+=v[i].second;
		cout << ans << endl;
		return 0;
	}
	v.pop_front();
	f=l=v;
	while(v.size()>1){
		if(v[0].first!=v.back().first) break;
		if(v[0].second+v.back().second==k){
			v.pop_front();
			v.pop_back();
			f.pop_back();
			l.pop_front();
		}
		else if(v[0].second+v.back().second>k){
			int rem=v[0].second+v.back().second-k;
			f.pop_back();
			v[0].second=rem;
			v.pop_back();
			l[0].second=rem;
		}
		else break;
	}
	if(v.size()==1){
		int mid=1LL*v[0].second*(m-2)%k;
		v[0].second=mid;
		if(mid==0) v.pop_back();
	}
	if(v.size()<=1){
		fin.push_back(make_pair(0,0));
		for(int i=0; i<f.size() ;i++){
			if(f[i].first==fin.back().first){
				fin.back().second=(fin.back().second+f[i].second)%k;
			}
			else{
				fin.push_back(f[i]);
			}
			if(fin.back().second==0) fin.pop_back();
		}
		for(int i=0; i<v.size() ;i++){
			if(v[i].first==fin.back().first){
				fin.back().second=(fin.back().second+v[i].second)%k;
			}
			else{
				fin.push_back(v[i]);
			}
			if(fin.back().second==0) fin.pop_back();
		}
		for(int i=0; i<l.size() ;i++){
			if(l[i].first==fin.back().first){
				fin.back().second=(fin.back().second+l[i].second)%k;
			}
			else{
				fin.push_back(l[i]);
			}
			if(fin.back().second==0) fin.pop_back();
		}
		long long int ans=0;
		for(int i=1; i<fin.size() ;i++){
			ans+=fin[i].second;
		}
		cout << ans << endl;
	}
	else{
		long long int ans=0;
		for(int i=0; i<f.size() ;i++){
			ans+=f[i].second;
		}
		long long int ans2=0;
		for(int i=0; i<v.size() ;i++){
			ans2+=v[i].second;
		}
		ans+=ans2*(m-2);
		for(int i=0; i<l.size() ;i++){
			ans+=l[i].second;
		}
		cout << ans << endl;
	}
}