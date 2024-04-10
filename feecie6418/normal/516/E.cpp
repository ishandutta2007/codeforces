#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+9;
int n,m,s,G;
ll ans=0;
set<int> is1,is2;
map<int,vector<int> > t;
void Exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1,y=0;
		return ;
	}
	ll xx,yy;
	Exgcd(b,a%b,xx,yy),x=yy,y=xx-(a/b)*yy;
}
ll Find(int x,int y,int n,int m){// k  x+kn=y (mod m)
	ll k,k2,g=__gcd(n,m);
	assert((y-x)%g==0);
	Exgcd(n,m,k,k2),k*=(y-x)/g,k=(k%(m/g)+(m/g))%(m/g);
	return 1ll*k*n+x;
}
void Solve(){
	//n 
	int g=__gcd(n,m);
	for(int i:is1)t[i%g].push_back(i%n);
	for(int i:is2)t[i%g].push_back(i%n);
	if(t.size()<g)puts("-1"),exit(0);
	ll d=1ll*n*m/g;
	for(auto it:t){
		G=it.first;
		vector<int> v=it.second;
		sort(v.begin(),v.end()),v.resize(unique(v.begin(),v.end())-v.begin());
		vector<pair<ll,ll> > v2;
		v2.resize(v.size());
		for(int i=0;i<v.size();i++)v2[i]=make_pair(Find(G,v[i],m,n),v[i]);
		sort(v2.begin(),v2.end());
		v2.push_back(*v2.begin());
		for(int i=0;i<v2.size()-1;i++)
			if(v2[i].second!=v2[i+1].second){
				ll tmp=v2[i+1].first-v2[i].first;
				tmp=(tmp%d+d)%d+v2[i].second-m;
				if(tmp!=v2[i].second)ans=max(ans,tmp);
			}
			else if(n!=m)ans=max(ans,d-m+v2[i].second);
	}
}//
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1,x;i<=s;i++)scanf("%d",&x),is1.insert(x);
	scanf("%d",&s);
	for(int i=1,x;i<=s;i++)scanf("%d",&x),is2.insert(x);
	for(int i=min(n,m)-1;i>=0&&i>=min(n,m)-100000;i--)if(!is1.count(i)||!is2.count(i)){ans=i;break;}
	Solve(),t.clear(),swap(n,m),Solve(),cout<<ans;
}