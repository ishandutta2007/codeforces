#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mo 998244353
#define N 1100010
using namespace std;
ll w[N],n,k,x,ansn,m,ma,lo,A[N],B[N],dp[N][2];
bool v[12];
ll po(ll x,ll y){ll z=1;while (y){if(y%2)z=x*z%mo;x=x*x%mo;y/=2;}return z;}
ll pa(ll x){if (x<0)x+=mo;if (x>=mo)x-=mo;return x;}
vector<int> s;
void ntt(ll *a,int fh){
	for (int i=0;i<n;i++)if(w[i]<i)swap(a[i],a[w[i]]);
	for (int i=1;i<n;i*=2){
		ll W=po(3,(mo-1)/(i*2));
		for (int j=0;j<n;j+=i*2){
			ll w=1;
			for (int k=0;k<i;k++,w=w*W%mo){
				ll x=a[j+k],y=a[j+k+i]*w%mo;
				a[j+k]=pa(x+y),a[j+k+i]=pa(x-y);
			}
		}
	}
	if (fh==-1){reverse(a+1,a+n);ll x=po(n,mo-2);for (int i=0;i<n;i++)a[i]=a[i]*x%mo;}
}
vector<ll> operator *(vector<ll> a,vector<ll> b){
	for (unsigned i=0;i<a.size();i++)A[i]=a[i];
	for (unsigned i=0;i<b.size();i++)B[i]=b[i];
	for (n=1,lo=0;n<=a.size()+b.size()-2;n*=2,lo++);
	for (int i=a.size();i<n;i++)A[i]=B[i]=0;
	for (int i=0;i<n;i++)w[i]=w[i/2]/2+(i&1)*(1<<(lo-1));
	ntt(A,1);ntt(B,1);
	for (int i=0;i<n;i++)A[i]=A[i]*B[i]%mo;
	ntt(A,-1);
	vector<ll> an;an.clear();
	for (int i=0;i<=a.size()+b.size()-2;i++)an.pb(A[i]);
	return an;
}
vector<ll> get(int x){
	if (x==0){vector<ll> s;s.clear();s.pb(1);return s;}
	vector<ll> la=get(x/2);
	la=la*la;
	if (x%2==1){
		int p=la.size();
		for (int i=0;i<p;i++)dp[i][0]=la[i];
		for (int i=0;i<p;i++)
			for (int j=0;j<=9;j++)
				if (v[j])dp[i+j][1]=pa(dp[i+j][1]+dp[i][0]);
		la.clear();
		for (int i=0;i<p+ma;i++){la.pb(dp[i][1]);dp[i][1]=0;}
	}
	return la;
}
int main(){
	cin>>m;cin>>k;
	for (int i=1;i<=k;i++){cin>>x;v[x]=1;ma=max(ma,x);}
	vector<ll> no=get(m/2);
	for (unsigned i=0;i<no.size();i++)ansn=(ansn+no[i]*no[i])%mo;
	cout<<ansn<<endl;
	return 0;
}