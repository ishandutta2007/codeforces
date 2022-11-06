#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a,i##_end=b;i<i##_end;++i)
using ll=long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int mo=998244353;
int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
//template<typename T>
void inc(int &x,int y){x=(x+y>=mo?x+y-mo:x+y);}
template<typename T>T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
mt19937 rnd(time(0));

ll sqr(int x){return 1ll*x*x;}
const int N=2e5+11;
char s[N];
int n,t[N],la[N],lb[N];
int e[N],ra[N],rb[N];
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		int q;
		cin>>n>>q>>s+1;
		For(i,1,n+1)s[i]=(s[i]=='-'?-1:+1);
		For(i,1,n+1){
			t[i]=t[i-1]+s[i];
			la[i]=max(la[i-1],t[i]);
			lb[i]=min(lb[i-1],t[i]);
		}
		e[n+1]=0;
		ra[n+1]=0;
		rb[n+1]=0;
		for(int i=n;i>=1;--i){
			e[i]=e[i+1]+s[i];
			ra[i]=max(ra[i+1],e[i]);
			rb[i]=min(rb[i+1],e[i]);
		}
		while(q--){
			int l,r;
			cin>>l>>r;
			--l;
			++r;
			int mx=max(la[l],t[l]+e[r]-rb[r]);
			int mn=min(lb[l],t[l]+e[r]-ra[r]);
			cout<<mx-mn+1<<"\n";
		}
	}
}