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
template<typename T>int upmn(T &x,T y){return x>y?x=y,1:0;}
mt19937 rnd(time(0));
ll sqr(int x){return 1ll*x*x;}
const int N=2e5+11,M=(N<<2)+11;

int n,k;
int p[N];
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>k;
		For(i,1,k+1)p[i]=i;
		reverse(p+2*k-n,p+k+1);
	//	cerr<<2*k-n-1<<endl;
		For(i,1,k+1){
			cout<<p[i]<<" \n"[i==k];
		}
	}
}