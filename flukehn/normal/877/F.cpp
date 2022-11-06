#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
#define pb push_back
#define I inline
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
const int N=100007;

int n,k,blo,t[N],s[N],u[N],v[N],cu[N*2],cv[N*2];
ll p[N],g[N],vt[N*2],ans[N];

struct query
{
	int l,r,id;
	inline bool operator<(const query&v)const
	{
		return l/blo<v.l/blo||(l/blo==v.l/blo&&r<v.r);
	}
}q[N];

int main()
{
//	in,n,k;
	n=rd(),k=rd();
	blo=sqrt(n);
	rep(i,1,n)t[i]=rd();
	rep(i,1,n)s[i]=rd();
	rep(i,1,n)p[i]=p[i-1]+(t[i]==1?s[i]:-s[i]);
	rep(i,0,n)g[i]=p[i]-k;
	int c=0;
	rep(i,0,n)vt[c++]=p[i];
	rep(i,0,n)vt[c++]=g[i];
	sort(vt,vt+c);
	c=unique(vt,vt+c)-vt;
	rep(i,0,n)u[i]=std::upper_bound(vt,vt+c,p[i])-vt;
	rep(i,0,n)v[i]=std::upper_bound(vt,vt+c,g[i])-vt;
	int m=rd();
	rep(i,1,m){
		q[i].l=rd(),q[i].r=rd();
		q[i].l--;
		q[i].id=i;
	}
	sort(q+1,q+m+1);
	int l=1,r=0;
	ll ta=0;
	rep(i,1,m){
		while(r<q[i].r){
			++r;
			ta+=cu[v[r]];
			cv[v[r]]++;
			cu[u[r]]++;
		}
		while(l>q[i].l){
			--l;
			ta+=cv[u[l]];
			cv[v[l]]++;
			cu[u[l]]++;
		}
		while(r>q[i].r){
			cu[u[r]]--;
			ta-=cu[v[r]];
			cv[v[r]]--;
			--r;
		}
		while(l<q[i].l){
			cv[v[l]]--;
			ta-=cv[u[l]];
			cu[u[l]]--;
			++l;
		}
		//out,q[i].l,' ',q[i].r,'\n';
		ans[q[i].id]=ta;
	}
	rep(i,1,m)printf("%lld\n",ans[i]);//ans[i],'\n';
}