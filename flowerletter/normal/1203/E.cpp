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
const int MAXN = 150010;
int n,ans,a[MAXN],vis[MAXN];
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+n+1);
	if(a[1]!=1) a[1]--;
	vis[a[1]]=1,ans++;
	for(int i=2;i<=n;i++){
		if(vis[a[i]-1]==0 && a[i]-1>=1){
			ans++;
			vis[a[i]-1]=1;
		}else if(vis[a[i]]==0){
			ans++;
			vis[a[i]]=1;
		}else if(vis[a[i]+1]==0){
			ans++;
			vis[a[i]+1]=1;
		}
	}
	cout<<ans<<'\n';
	return 0;
}