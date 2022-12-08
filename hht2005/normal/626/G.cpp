#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define id second
#define val first
const int N=2e5+10;
const double eps=1e-8,inf=1e16;
int p[N],l[N],sum[N],cnt;
double ans=0;
typedef pair<double,int> pdi;
set<pdi>s,d;
double f(int i,int c) {
	if(c<=0)return inf;
	if(c>l[i])return -inf;
	return 1.0*p[i]*l[i]/(1.0*(c+l[i])*(c+l[i]-1));
}
void add() {
	auto it=d.rbegin();
	int x=it->id;
	double v=it->val;
	if(v<0) {
		cnt++;
		return;
	}
	ans+=v;
	s.erase(mp(f(x,sum[x]),x));
	d.erase(mp(f(x,++sum[x]),x));
	s.insert(mp(f(x,sum[x]),x));
	d.insert(mp(f(x,sum[x]+1),x));
}
void del() {
	if(cnt) {
		cnt--;
		return;
	}
	auto it=s.begin();
	int x=it->id;
	double v=it->val;
	ans-=v;
	d.erase(mp(f(x,sum[x]+1),x));
	s.erase(mp(f(x,sum[x]),x));
	d.insert(mp(f(x,sum[x]),x));
	s.insert(mp(f(x,--sum[x]),x));
}
int main() {
	int n,t,q,op,x;
	scanf("%d%d%d",&n,&t,&q);
	for(int i=1;i<=n;i++)scanf("%d",p+i);
	for(int i=1;i<=n;i++)scanf("%d",l+i);
	for(int i=1;i<=n;i++) {
		d.insert(mp(f(i,1),i));
		s.insert(mp(inf,i));
	}
	for(int i=1;i<=t;i++)add();
	for(int i=1;i<=q;i++) {
		scanf("%d%d",&op,&x);
		if(op==1)op=1;
		else op=-1;
		s.erase(mp(f(x,sum[x]),x));
		d.erase(mp(f(x,sum[x]+1),x));
		ans-=1.0*p[x]*sum[x]/(sum[x]+l[x]);
		l[x]+=op;
		if(sum[x]<=l[x]) {
			ans+=1.0*p[x]*sum[x]/(sum[x]+l[x]);
			s.insert(mp(f(x,sum[x]),x));
			d.insert(mp(f(x,sum[x]+1),x));
			while(sum[x]<l[x]&&cnt)cnt--,add();
		}
		else {
			sum[x]--;
			s.insert(mp(f(x,sum[x]),x));
			d.insert(mp(f(x,sum[x]+1),x));
			add();
			ans+=p[x]*0.5;
		}
		while(d.rbegin()->val>s.begin()->val)del(),add();
		printf("%.9f\n",ans);
	}
	return 0;
}