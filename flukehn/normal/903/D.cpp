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
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,MOD=1e9+7;
inline int rd() {
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=2e5+11;
int n,a[N];map<int,int> M;
int main(){
	n=rd();
	rep(i,1,n)a[i]=rd();
	long double sum=0,ans=0;
	rep(i,1,n){
		ans+=1ll*a[i]*(i-1)-sum;
		if(M.count(a[i]+1)){
			ans+=M[a[i]+1];
		}if(M.count(a[i]-1)){
			ans-=M[a[i]-1];
		}
		sum+=a[i];
		M[a[i]]++;//-9999999990000000000
	}
	cout << fixed << setprecision(0) << ans << '\n' ;
}