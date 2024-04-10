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

const int N=3e5+11;
char s[N];
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		int u,d,l,r;
		u=d=l=r=0;
		int x,y;
		cin>>x>>y>>s;
		int n=strlen(s);
		For(i,0,n)if(s[i]=='U')++u;
			else if(s[i]=='D')++d;
			else if(s[i]=='L')++l;
			else ++r;
		puts((x>=-l&&x<=r&&y>=-d&&y<=u)?"YES":"NO");
	}
}