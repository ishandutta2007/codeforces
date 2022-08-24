#include<iostream>
#include<map>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
int ptr=0;
ll p[501],q[501],r[501],pq[501];
map<ll,int>mp,mpq;
ll pwr(int k,ll num){
	ll res=1;
	for(int i=1; i<=k ;i++) res*=num;
	return res;
}
ll rt(int k,ll l,ll r,ll x){
	ll mid;
	while(l!=r){
		ll mid=(l+r+1)/2;
		if(pwr(k,mid)<=x) l=mid;
		else r=mid-1;
	}
	return l;
}
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		ll x;
		cin >> x;
		ll num3=rt(2,1,2e9,x),num4=rt(3,1,1.5e6,x),num5=rt(4,1,5e4,x);
		if(pwr(4,num5)==x){
			p[i]=num5;
			q[i]=1;
			r[i]=4;
		}
		else if(pwr(3,num4)==x){
			p[i]=num4;
			q[i]=1;
			r[i]=3;
		}
		else if(pwr(2,num3)==x){
			p[i]=num3;
			q[i]=1;
			r[i]=2;
		}
		else pq[i]=x;
		if(q[i]!=1){//trying to factor i
			for(int j=1; j<=i ;j++){
				if(q[j]==0){//j is unfactored semiprime
					ll num=gcd(pq[j],pq[i]);
					if(num==1 || num==pq[i]) continue;
					p[i]=pq[i]/num;
					q[i]=num;
					break;
				}
				if(q[j]!=0){
					if(pq[i]%p[j]==0){
						p[i]=p[j];
						q[i]=pq[i]/p[j];
					}
				}
				if(q[j]>1){
					if(pq[i]%q[j]==0){
						q[i]=q[j];
						p[i]=pq[i]/q[j];
					}
				}
			}
		}
		if(q[i]!=0){//trying to get i factor other shit
			for(int j=1; j<=i ;j++){
				if(q[j]==0 && pq[j]%p[i]==0){
					p[j]=p[i];
					q[j]=pq[j]/p[j];
				}
			}
		}
		if(q[i]>1){//trying to get i factor other shit
			for(int j=1; j<=i ;j++){
				if(q[j]==0 && pq[j]%q[i]==0){
					q[j]=q[i];
					p[j]=pq[j]/q[j];
				}
			}
		}
	}
	for(int i=1; i<=n ;i++){
		if(q[i]==0) mpq[pq[i]]++;
		else if(r[i]==0) mp[p[i]]++,mp[q[i]]++;
		else mp[p[i]]+=r[i];
	}
	ll ans=1;
	for(auto cur:mp){
		ans=ans*(cur.se+1)%998244353;
	}
	for(auto cur:mpq){
		ans=ans*(cur.se+1)*(cur.se+1)%998244353;
	}
	cout << ans << endl;
}