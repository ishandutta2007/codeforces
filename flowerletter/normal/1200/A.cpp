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
int n,a[20];
char s[100010];
inl int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0' || c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9') {x=x*10+c-'0';c=getchar();}
	return x*f;
}

int main(){
	scanf("%d%s",&n,s+1);
	for(int i=1;i<=n;i++){
		if(s[i]=='L') {
			for(int j=0;j<10;j++) {
				if(a[j]==0) {
					a[j]=1;
					break;
				}
			}
		}
		else if(s[i]=='R'){
			for(int j=9;j>=0;j--) {
				if(a[j]==0) {
					a[j]=1;
					break;
				}
			}
		}
		else {
			int tmp=s[i]-'0';
			a[tmp]=0;
		}
	}for(int i=0;i<10;i++) cout<<a[i];
	return 0;
}