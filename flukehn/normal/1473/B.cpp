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

const int N=1e5+11;
int a[N];
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		string s,t;
		cin>>s>>t;
		if(s.length()>t.length())swap(s,t);
		int n=s.length(),m=t.length();
		string ans="";
		int flag=0;
		int w=0;
		for(;;){
			if(w<m||w%m)w+=n,ans+=s;
			For(i,w,w+n)if(s[i%n]!=t[i%m]){flag=1;break;}
			if((w>=m&&w%m==0)||flag)break;
		}
		if(flag)cout<<"-1\n";
		else cout<<ans<<"\n";
	}
}