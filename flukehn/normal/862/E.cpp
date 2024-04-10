#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define Es(x,i) for(Edge *i=G[x];i;i=i->nex)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=1e9+7;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x=0,c=0,f=1;
	for(; c<'0'||c>'9'; c=getchar())f=c!='-';
	for(; c>='0'&&c<='9'; c=getchar())x=x*10+c-'0';
	return f?x:-x;
}
const int N=1e5+11;
int n,m,q;
int a[N],b[N];
ll s[N],t[N],c[N];
int sz;
ll query(ll now){
	ll *f=lower_bound(c+1,c+sz+1,now);
	if(f==c+sz+1)f--;
	else if(f==c)f++;
	return f==c+1?abs(*f-now):min(abs(*f-now),abs(*(f-1)-now));
}
int main(){
	n=rd(),m=rd(),q=rd();
	rep(i,1,n){
		a[i]=rd();
		s[i]=s[i-1]+((i)%2?a[i]:-a[i]);
	}
	rep(i,1,m){
		b[i]=rd();
		t[i]=t[i-1]+((i)%2?b[i]:-b[i]);
	}
	//ll mx=-LONG_LONG_MAX,mi=LONG_LONG_MAX;
	sz=m-n+1;
	ll now=LONG_LONG_MAX;
	rep(i,0,m-n){
		c[i+1] = s[n] + (i%2?t[i+n]-t[i]:t[i]-t[i+n]);
		now = min(now, abs(c[i+1]));
		//cout << c[i+1] << endl;
		/*mx = max(c[i+1], mx);
		mi = min(c[i+1], mi);*/
	}
	cout<<now<<endl;
	sort(c+1,c+sz+1);
	ll tot=0;
	while(q--){
		int l=rd(),r=rd(),x=rd();
		if(r-l&1)printf("%lld\n",now);
		else {
			if(l&1)tot+=x;
			else tot-=x;
			printf("%lld\n",now=query(-tot));
		}
	}
}