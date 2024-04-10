#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;i++)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge*i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=5011;
int a[N],f[N];
int main(){
	int n=rd();
	rep(i,1,n)a[i]=rd();
	int r=0,l=0;
	rep(i,1,n)r=__gcd(r,a[i]),l+=a[i]==1;
	if(r!=1)return puts("-1"),0;
	else if(l)return printf("%d\n",n-l),0;
	int ns=inf;
	rep(i,1,n){
		int p=a[i];
		rep(j,i+1,n){
			p=__gcd(p,a[j]);
			if(p==1){
				ns=min(ns,j-i);
				break;
			}
		}
	}
	cout<<ns+n-1<<endl;
}