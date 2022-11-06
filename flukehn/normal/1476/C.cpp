#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a,i##_end=b;i<i##_end;++i)
using ll=long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int mo=1e9+7;
int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
//template<typename T>
void inc(int &x,int y){x=(x+y>=mo?x+y-mo:x+y);}
template<typename T>T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
mt19937 rnd(time(0));

const int N=1e5+11;
int n;
int c[N],a[N],b[N];
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		For(i,0,n)cin>>c[i];
		For(i,0,n)cin>>a[i];
		For(i,0,n)cin>>b[i];
		For(i,0,n)if(a[i]>b[i])swap(a[i],b[i]);
		ll ans=0,s=b[1]-a[1]+1;
		For(i,1,n){
			ans=max(ans,c[i]+s);
			if(a[i+1]==b[i+1]){
				s=1;
			}else{
				s=max(b[i+1]-a[i+1]+1LL,s+c[i]-b[i+1]+a[i+1]+1);
			}
		//	cerr<<i<<" "<<s<<endl;
		}
		cout<<ans<<"\n";
	}
}