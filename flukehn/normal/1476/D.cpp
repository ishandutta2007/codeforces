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
int n;
char s[N];
int f[N<<1],sz[N<<1];
int fa(int i){
	return f[i]==i?i:f[i]=fa(f[i]);
}
void uni(int i,int j){
//	cerr<<i<<" "<<j<<endl;
	i=fa(i),j=fa(j);
	if(i!=j){
		f[j]=i;
		sz[i]+=sz[j];
	}
}
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>s+2;
		++n;
		For(i,1,n*2+2)sz[i]=1,f[i]=i;
		For(i,2,n+1){
			if(s[i]=='L')uni(i<<1,(i-1)<<1|1);
			else uni(i<<1|1,(i-1)<<1);
		}
		For(i,1,n+1)cout<<sz[fa(i<<1)]<<" \n"[i==n];
	}
}