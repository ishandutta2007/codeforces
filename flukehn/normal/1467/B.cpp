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
int a[N],n;
int cal(int i){
	if(i<1||i>n-2) return 0;
	return (a[i]>a[i-1]&&a[i]>a[i+1]) || (a[i]<a[i-1]&&a[i]<a[i+1]);
}
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		For(i,0,n)cin>>a[i];
		int ans=0;
		For(i,0,n)ans+=cal(i);
		int ori=ans;
		For(i,0,n){
			int tmp=ori-cal(i-1)-cal(i)-cal(i+1);
			int w=a[i];
			a[i]=-oo;
			ans=min(ans,tmp+cal(i-1)+cal(i)+cal(i+1));
			a[i]=+oo;
			ans=min(ans,tmp+cal(i-1)+cal(i)+cal(i+1));
			if(i)a[i]=a[i-1];
			ans=min(ans,tmp+cal(i-1)+cal(i)+cal(i+1));
			a[i]=a[i+1];
			ans=min(ans,tmp+cal(i-1)+cal(i)+cal(i+1));
			a[i]=w;
		}
		cout<<ans<<"\n";
	}
}