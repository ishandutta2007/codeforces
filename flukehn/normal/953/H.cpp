#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
#define debug(...) fprintf(stderr, __VA_ARGS__)
typedef double db;
typedef long long ll;
typedef vector<int> Vi;
typedef pair<int,int> pii;
const int inf=~0u>>1,mo=1e9+7;
inline int rd(){
    int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=200011;
ll a[N],b[N],c[N];
int t1,t2,t3;
char s[N];int f[N];
int cmp(ll i,ll j){return i>j;}
int main(){
	int n=rd(),k=rd();
	rep(i,1,n)f[i]=rd();
	scanf("%s",s+1);
	rep(i,1,n)if(s[i]=='O')a[++t1]=f[i];else if(s[i]=='R')b[++t2]=f[i];
	else c[++t3]=f[i];
	sort(a+1,a+t1+1,cmp),sort(b+1,b+t2+1,cmp),sort(c+1,c+t3+1,cmp);
	For(i,2,N)a[i]+=a[i-1];For(i,2,N)b[i]+=b[i-1];For(i,2,N)c[i]+=c[i-1];
	if(!t1||!(t2+t3)||k<2||t1+max(t2,t3)<k){puts("-1");return 0;}
	ll ans=0;
	rep(i,1,min(k-1,t1)){
		if(t2>=k-i)ans=max(ans,a[i]+b[k-i]);
		if(t3>=k-i)ans=max(ans,a[i]+c[k-i]);
	}
	cout<<ans<<endl;
}