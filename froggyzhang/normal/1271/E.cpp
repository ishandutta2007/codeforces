#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 111
typedef long long ll;
ll n,k,l,r,ans,ppp;
int a[N],an,b[N],bn;
void chan(ll x){
	while(x){
		a[++an]=(x&1);
		x>>=1;
	}
}
ll check(ll x){
	if(x>n)return 0;
	ll y=x,tot=0;
	bn=0;
	while(y){
		b[++bn]=(y&1);
		y>>=1;
	}
	int ok=1;
	for(int i=bn,j=an;i>=1;i--,j--){
		if(b[i]^a[j]){
			if(b[i]>a[j])ok=0;
			else ok=2;
			break;
		}
	}
	if(ok==1){
		tot+=n-(x<<(an-bn))+1;
	}
	else if(ok==2){
		tot+=(1LL<<(an-bn));
	}
	for(int i=an-bn-1;i>=0;i--){
		tot+=(1LL<<i);
	}
	return tot;
}
int main(){
	cin>>n>>k;
	if(k==1){
		cout<<n<<endl;
		return 0;
	}
	if(k==n){
		cout<<1<<endl;
		return 0;
	}
	chan(n);
	l=1,r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid*2)+check(mid*2+1)>=k){
			l=mid+1;
			ans=mid*2;
		}
		else{
			r=mid;
		}
	}
	l=1,r=n;
	while(l<r){
		ll mid=(l+r)>>1;
		if(check(mid*2+1)>=k){
			l=mid+1;
			ppp=mid*2+1;
		}
		else{
			r=mid;
		}
	}
	cout<<max(ans,ppp)<<endl;
	return 0;
}