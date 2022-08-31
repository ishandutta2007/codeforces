#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll m1=2*998244353;
const ll m2=2*998244853;
const int iu=1e5;
int n,k;
int a[100001];
ll h1[101],h2[101];
ll r1[100001],r2[100001];
ll t1[100001],t2[100001];
ll t3[100001],t4[100001];
int cnt=0;
map<pair<pair<ll,ll>,pair<ll,ll> >,int>mp;
bool ff[100001];
ll ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<=k/2 ;i++){
		ll h=1LL*rand()*32767+rand();
		h1[i]=h%m1;h2[i]=h%m2;
		h1[k-i]=m1-h1[i];h2[k-i]=m2-h2[i];
	}
	for(int i=1; i<=iu ;i++){
		ll r=1LL*rand()*32767+rand();
		if(r%2==0) r++;
		r1[i]=r%m1;
		r2[i]=r%m2;
	}
	if(k%2==0) h1[k/2]=m1/2,h2[k/2]=m2/2;
	for(int i=2; i<=iu ;i++){
		if(ff[i]) continue;
		for(int j=i; j<=iu ;j+=i){
			ff[j]=true;
			int cnt=0;
			int kk=j;
			while(kk%i==0){
				kk/=i;cnt++;
			}
			cnt%=k;
			if(cnt*2!=k){
				t1[j]=(t1[j]+r1[i]*h1[cnt])%m1;
				t2[j]=(t2[j]+r2[i]*h2[cnt])%m2;
			}
			else{
				t3[j]=(t3[j]+r1[i])%m1;
				t4[j]=(t4[j]+r2[i])%m2;
			}
		}
	}
	for(int i=1; i<=n ;i++){
		ans+=mp[{{(m1-t1[a[i]])%m1,(m2-t2[a[i]])%m2},{t3[a[i]],t4[a[i]]}}];
		mp[{{t1[a[i]],t2[a[i]]},{t3[a[i]],t4[a[i]]}}]++;
	}
	cout << ans << endl;
}