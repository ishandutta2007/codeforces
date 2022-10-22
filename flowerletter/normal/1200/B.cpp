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
int t,n,m,k,a[110];
int main(){
	t=read();while(t--){
		n=read(),m=read(),k=read();
		for(int i=1;i<=n;i++) a[i]=read();
		int flag=1;
		for(int i=1;i<n;i++){
			if(a[i]+k<a[i+1]){
				if(a[i]+k+m<a[i+1]) {
					puts("NO");
					flag=0;
					break;
				}else {
					m-=a[i+1]-a[i]-k;
				}
			}else {
				if(a[i+1]-k<0) m+=a[i];
				else m+=a[i]+k-a[i+1];
			}
		}if(flag) puts("YES");
	}
	return 0;
}