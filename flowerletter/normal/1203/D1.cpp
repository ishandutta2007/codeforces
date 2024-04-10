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
const int MAXN = 210;
char s[MAXN],t[MAXN],x[MAXN];
int n,m,ans;
inline bool check(int l,int r){
	int i=1,j=1;
	for(;i<=n && j<=m;j++,i++){
		while(x[i]!=t[j] && i<=n) i++;
	}
	if(i==n+2 || (i==n+1 && j<=m)) return false;
	else return true;
}
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=n;k++) x[k]=s[k];
			for(int k=i;k<=j;k++) x[k]='#';
			if(check(i,j)) ans=max(ans,j-i+1);
		}
	}cout<<ans<<'\n';
	return 0;
}