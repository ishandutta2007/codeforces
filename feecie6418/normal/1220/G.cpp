#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 LL;
typedef pair<LL,LL> pr;
struct P{
	LL x,y;
}a[100005];
int n,m;
LL d[100005],sx,sy;
void Print(LL x){
	int c[52]={0};
	if(x<0)return putchar('-'),Print(-x);
	if(!x)return putchar('0'),void();
	while(x)c[++c[0]]=x%10,x/=10;
	while(c[0])putchar(c[c[0]--]+'0');
}
const int mod=1e9+7;
int Power(int x,int y){
	int ret=1;
	while(y) {
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return ret;
}
namespace ECSY {
	int w;
	mt19937_64 rng(time(0));
	struct Complex {
		int a,b;
		Complex(){a=1,b=0;}
		Complex(int aa,int bb){a=aa,b=bb;}
		Complex operator *(const Complex yy) const {
			return Complex((1ll*a*yy.a+1ll*b*yy.b%mod*w)%mod,(1ll*a*yy.b+1ll*b*yy.a)%mod);
		}
	};
	Complex Power(Complex x,int y){
		Complex ret;
		while(y) {
			if(y&1)ret=ret*x;
			x=x*x,y>>=1;
		}
		return ret;
	}
	vector<int> Cipolla(int n){
		if(!n)return (vector<int>){0};
		if(::Power(n,(mod-1)/2)==mod-1)return vector<int>();
		int a;
		do a=rng()%mod; while(::Power((1ll*a*a-n+mod)%mod,(mod-1)/2)!=mod-1);
		w=(1ll*a*a-n+mod)%mod;
		int res=Power(Complex(a,1),(mod+1)/2).a;
		return (vector<int>){res,mod-res};
	}
};
int m2m1,m1m2;
vector<LL> Solve(LL P,LL Q,LL R,int modn){
	int a=P%mod,b=Q%mod,c=R%mod;
	b=(b+mod)%mod,c=(c+mod)%mod;
	int t1=1ll*b*b%mod,t2=4ll*a*c%mod,dlt=(t1-t2+mod)%mod;
	vector<int> t=ECSY::Cipolla(dlt);
	vector<LL> res;
	int inv=Power(2*a%mod,mod-2);
	for(int d:t){
		int x=1ll*inv*(d-b+mod)%mod;
		//mod 10^9+7=x; mod n=modn;
		//cout<<x<<' ';
		LL s1=((LL)x*n*m2m1+(LL)modn*mod*m1m2)%((LL)n*mod);
		if(s1>0)res.push_back(s1-(LL)n*mod);
		res.push_back(s1);
	}
	//puts("");
	return res;
}
void Solve(){
	LL sumdis=0;
	multiset<LL> o;
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		d[i]=x,d[i]*=n,d[i]*=n,sumdis+=d[i]-a[i].x*a[i].x-a[i].y*a[i].y;
		o.insert(d[i]);
	}
	LL r1=sumdis/n;
	if(d[1]==r1)swap(d[1],d[2]);
	vector<pr> might;
	for(int i=1;i<=n;i++){
		LL k1=a[i].x,k2=a[i].y,r2=d[1];
		if(k1==0&&k2==0)continue;
		LL A=(r1-r2+k1*k1+k2*k2)/2;
		A%=mod;
		LL P=k1*k1+k2*k2,Q=-2*k1*A,R=A*A-r1%mod*k2%mod*k2;
		vector<LL> tx=Solve(P,Q,R,(n-sx%n)%n);
		P=k1*k1+k2*k2,Q=-2*k2*A,R=A*A-r1%mod*k1%mod*k1;
		vector<LL> ty=Solve(P,Q,R,(n-sy%n)%n);
		for(auto j:tx){
			for(auto k:ty){
				if(j*j+k*k==r1&&(j-k1)*(j-k1)+(k-k2)*(k-k2)==r2){
					might.push_back(pr(j,k));
				}
			}
		}
	}
	sort(might.begin(),might.end());
	might.resize(unique(might.begin(),might.end())-might.begin());
	vector<pr> fin;
	for(auto [u,v]:might){
		//cerr<<(ll)(u+sx)/n<<' '<<(ll)(v+sy)/n<<'\n';
		auto oo=o;
		int ok=1; 
		for(int i=1;i<=n;i++){
			LL w=(u-a[i].x)*(u-a[i].x)+(v-a[i].y)*(v-a[i].y);
			if(oo.find(w)==oo.end()){
				ok=0;
				break;
			}
			oo.erase(oo.find(w));
		}
		if(ok)fin.push_back(pr(u,v));
	}
	cout<<fin.size()<<' ';
	for(auto [u,v]:fin)cout<<(ll)(u+sx)/n<<' '<<(ll)(v+sy)/n<<' ';
	puts("");
}
ll Exgcd(ll a,ll b,ll &x,ll &y){
	if(!b)return x=1,y=0,a;
	ll ret=Exgcd(b,a%b,y,x);
	return y-=x*(a/b),ret;
}
ll inv(ll x,ll y){
	ll a,b;
	Exgcd(x,y,a,b);
	return (a%y+y)%y;
} 
int main(){
	/*auto i=Solve(1,-3,2);
	for(auto j:i){
		cout<<(ll)j<<'\n';
	}*/
	//freopen("2.out","w",stdout);
	scanf("%d",&n),sx=0,sy=0,m2m1=Power(n,mod-2),m1m2=inv(mod,n);
	for(int i=1;i<=n;i++){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		x*=n,y*=n,a[i]={x,y},sx+=x,sy+=y;
	}
	sx/=n,sy/=n;
	for(int i=1;i<=n;i++)a[i].x-=sx,a[i].y-=sy;
	scanf("%d",&m);
	while(m--)Solve();
}