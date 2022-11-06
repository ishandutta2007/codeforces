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
const int N=3e5+11;
mt19937 rnd(time(0));

int n,x;
int a[N];
ll b[N];
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>x;
		ll ans=0;
		For(i,0,n){
			cin>>a[i];
			b[i]=1;
		}
		int i=n;
		while(i==n){
			for(i=0;i<n;++i){
				if(a[i]%x)break;
				ans+=b[i]*a[i];
				b[i]*=x;
				a[i]/=x;
			}
		}
		for(i=0;i<n;++i)ans+=b[i]*a[i];
		cout<<ans<<endl;
	}
}