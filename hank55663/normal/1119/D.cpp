#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
LL mod=3e18;
LL f_pro(LL a,LL b){
	LL res=0,temp=a;
	while(b){
		if(b&1)res = (res+temp)%mod;
		temp=(temp+temp)%mod;
		b>>=1;
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	LL s[100005];
	for(int i = 0;i<n;i++){
		scanf("%lld",&s[i]);
	}
	sort(s,s+n);
	vector<LL> v;
	for(int i = 0;i<n-1;i++){
		v.pb(s[i+1]-s[i]);
	}
	sort(v.begin(),v.end());
	//for(auto it:v)
	//printf("%d ",it);
	vector<LL> pre;
	//if(n!=1)
	pre.pb(0);
	for(int i = 0;i<v.size();i++)
	pre.pb(pre.back()+v[i]);
	int q;
	scanf("%d",&q);
	while(q--){
		LL l,r;
		scanf("%lld %lld",&l,&r);
		int index=lower_bound(v.begin(),v.end(),r-l+1)-v.begin();
		//printf("%d %lld\n",index,pre[index]);
		printf("%lld ",(f_pro((r-l+1),(n-index))+pre[index]+mod)%mod);
	}
}
//1 1 3 4 5 5 9
// 0 2 1 1 0 4
//y-x^2 = bx+c
// A= Bb+Cc
// D= Eb+Fc