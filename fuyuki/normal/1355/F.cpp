#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define FOR(i,a,b) for(int i=a;i<=b;i++)
ll table[17]={921101769090347257ll,973682079860402231ll,835452586140385109ll,885924792533002661ll,996866032532292401ll,998157007126755907ll,947595208606408289ll,975589797044851393ll,996342762869045369ll,878835235457968301ll,733364240194092706ll,618710474572733555ll,765046742445625459ll,997804397813471821ll,950319561489139551ll,858304435969956329ll,35010049619772217ll};
const int N=1000,INF=1e9;
int T,val,ans,input,n,tot,a[N];
ll gcd(ll x,ll y){return!y?x:gcd(y,x%y);}
I query(ll x){
	cout<<"? "<<x<<endl;
	return cin>>x,x;
}
V solve(int x){FOR(i,2,N)if(x%i==0)x/=i,a[++n]=i;}
I Pow(int x,ll s=1){
	while(s*x<=INF)s*=x;
	return s;
}
V answer(int x){cout<<"! "<<x<<endl;}
V work(){
	val=ans=1,n=tot=0;
	FOR(i,0,16)val*=query(table[i]);
	solve(val),tot=n;
	while(n)
		if(n==1)val/=a[n],val*=query(Pow(a[n])),n--;
		else val/=a[n]*a[n-1],val*=query(1ll*Pow(a[n])*Pow(a[n-1])),n-=2;
	FOR(i,1,tot){
		ll x=a[i],y=1;
		while(val%x==0)x*=a[i],y++;
		ans*=y;
	}
	if(val<=2)answer((val+1)*(val+1));
	else answer(ans<<1);
}
int main(){for(cin.tie(0),cin>>T;T--;work());}