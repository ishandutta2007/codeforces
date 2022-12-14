#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>
#define MN 100000
#define N 131072
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct data{int l,r,t,x;
	data(int _l,int _r,int _t,int _x){l=_l;r=_r;t=_t;x=_x;}
	data(int k){l=k;r=0;}
	bool operator <(const data&b)const{return l==b.l?r<b.r:l<b.l;}
};
set<data> s;long long Ans[MN+5],T1[N*2+5],T2[N*2+5];
int n,m,top,a[MN+5],mx[MN+5],R[MN+5],rk[MN+5],tms[MN+5];
struct ques{int l,r,t,id;}q[MN*10+5];
int Calc(int t,int x,int r,int m){return (int)min((long long)m,x+1LL*r*t);}
bool cmp(const ques&a,const ques&b){return a.t<b.t;}
bool cmp2(int x,int y){return tms[x]<tms[y];}
void Renew(long long*T,int x,int v){for(T[x+=N]+=v;x>>=1;)T[x]=T[x<<1]+T[x<<1|1];}
long long Query(long long*T,int l,int r)
{
	long long sum=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) sum+=T[l+1];
		if( r&1) sum+=T[r-1];
	}	
	return sum;
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();mx[i]=read();R[i]=read();tms[i]=R[i]?(int)ceil((double)mx[i]/R[i]):2e9;
	//	printf("mx=%d r=%d tms=%d\n",mx[i],R[i],tms[i]);
		s.insert(data(i,i,0,a[i]));	rk[i]=i;
	}
	m=read();
	for(int i=1;i<=m;++i)
	{
		int t=read(),l=read(),r=read();
		set<data>::iterator it=s.lower_bound(data(l));	
		for(;it!=s.end()&&it->l<=r;it=s.lower_bound(data(l)))
		{
		//	cout<<"Find"<<it->l<<" "<<it->r<<" "<<it->t<<" "<<it->x<<endl;
			if(it->r>r) s.insert(data(r+1,it->r,it->t,it->x));
			if(it->r==it->l) Ans[i]+=Calc(t-it->t,it->x,R[it->r],mx[it->r]);
			else q[++top]=(ques){it->l,min(it->r,r),t-it->t,i};
			s.erase(it);
		}
		for(;it!=s.begin()&&(--it)->r>=l;it=s.lower_bound(data(l)))
		{
			if(it->r>r) s.insert(data(r+1,it->r,it->t,it->x));
			if(it->l<l) s.insert(data(it->l,l-1,it->t,it->x));
			q[++top]=(ques){max(it->l,l),min(r,it->r),t-it->t,i};
			s.erase(it);
		}	
		s.insert(data(l,r,t,0));
	}
//	for(int i=1;i<=top;++i) printf("%d %d %d %d\n",q[i].l,q[i].r,q[i].t,q[i].id);
	sort(rk+1,rk+n+1,cmp2);
	sort(q+1,q+top+1,cmp);
	for(int i=1;i<=n;++i) Renew(T1,i,R[i]);
	for(int i=1,j=1;i<=top;)
		if(j<=n&&tms[rk[j]]<=q[i].t)
		{
			Renew(T1,rk[j],-R[rk[j]]);
			Renew(T2,rk[j],mx[rk[j]]);	
			++j;
		}
		else 
		{
			Ans[q[i].id]+=1LL*q[i].t*Query(T1,q[i].l,q[i].r)+Query(T2,q[i].l,q[i].r);
			++i;
		}
	for(int i=1;i<=m;++i) printf("%lld\n",Ans[i]);
	return 0;
}