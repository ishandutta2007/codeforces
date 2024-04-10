#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define ull unsigned long long
#define ldb long double
#define pb push_back
#define fir first
#define sec second
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define pll pair<ll,ll>
#define mp make_pair
#define inl inline
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)
inl int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}
int n,q,a[410],tim[11000];
vector<int> S;
int main(){
	q=read();
	while(q--){
		S.clear();
		for(int i=1;i<=10000;i++) tim[i]=0;
		n=read();
		int flag=1;
		for(int i=1;i<=4*n;i++) a[i]=read(),tim[a[i]]++;
		for(int i=1;i<=10000 && flag;i++){
			if(tim[i]&1) puts("NO"),flag=0;
			tim[i]>>=1;
		}if(flag){
			for(int i=1;i<=10000;i++) for(int j=1;j<=tim[i];j++) S.pb(i);
			int Mul=S[0]*S[S.size()-1],l=0,r=S.size()-1;
			while(l<r){
				if(S[l]*S[r]!=Mul) {flag=0;puts("NO");break;}
				l++,r--;
			}if(flag) puts("YES");
		}
	}
	return 0;
}