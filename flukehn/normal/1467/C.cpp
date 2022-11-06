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

const int N=3e5+11,oo=~0u>>2;
int n[3];
int a[3][N];
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	//int T;cin>>T;
	while(cin>>n[0]>>n[1]>>n[2]){
		ll ans=0;
		ll t[3]={0};
		For(i,0,3){
			For(j,0,n[i]){
				cin>>a[i][j];
				t[i]+=a[i][j];
			}
			ans+=t[i];
			sort(a[i],a[i]+n[i]);
		}
		int b[3];
		For(i,0,3)b[i]=a[i][0];
		sort(b,b+3);
		ll tmp=min( min(t[0], t[1]), 
			min(t[2],(ll)(b[0]+b[1]))
			);
		cout<<ans-2*tmp<<"\n";
	}
}