#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N=50005,M=50005;

int mo;

struct matrix{
	int a[2][2];
	int* operator [] (const int i){
		return a[i];
	}
	const int* operator [] (const int i) const{
		return a[i];
	}
	friend matrix operator * (const matrix &a,const matrix &b){
		matrix c;
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++){
				ll s=0;
				for(int k=0;k<2;k++)
					s+=(ll)a[i][k]*b[k][j];
				c[i][j]=s%mo;
			}
		return c;
	}
};

int n,m; ll k;

int s[N];

typedef pair<ll,int> data;

data a[M];

inline int gs(ll i){
	data *it=lower_bound(a,a+m,data(i,0));
	if(it<a+m&&it->first==i) return it->second;
	return s[i%n];
}

matrix t[N*4];

void build(int cur,int beg,int end){
	if(end-beg==1){
		t[cur][1][0]=1%mo;
		t[cur][0][1]=s[beg];
		t[cur][1][1]=s[(beg+1)%n];
		return;
	}
	int mid=beg+end>>1;
	build(cur<<1,beg,mid);
	build(cur<<1|1,mid,end);
	t[cur]=t[cur<<1]*t[cur<<1|1];
}

matrix ans;

void query(int cur,int beg,int end,int L,int R){
	if(end<=L||beg>=R) return;
	if(beg>=L&&end<=R){
		ans=ans*t[cur];
		return;
	}
	int mid=beg+end>>1;
	query(cur<<1,beg,mid,L,R);
	query(cur<<1|1,mid,end,L,R);
}

ll p[M*2],*top=p;
ll q[M*2],*toq=q;

void power(ll s){
	matrix a=t[1];
	for(;s;s>>=1,a=a*a)
		if(s&1) ans=ans*a;
}

int main(){
	scanf("%I64d%d",&k,&mo);
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&s[i]),s[i]%=mo;
	scanf("%d",&m);
	for(int i=0;i<m;i++) scanf("%I64d%d",&a[i].first,&a[i].second),a[i].second%=mo;
	sort(a,a+m);
	for(int i=0;i<m;i++) p[i<<1]=a[i].first-1,p[i<<1|1]=a[i].first;
	p[m*2]=k;
	sort(p,p+m*2+1);
	top=unique(p,p+m*2+1);
	for(int i=0;i<top-p;i++) q[i]=p[i]/n;
	toq=unique(q,q+(top-p));
	build(1,0,n);
	ans[0][0]=ans[1][1]=1%mo; ans[0][1]=ans[1][0]=0;
	ll block=0;
	for(int i=0,j=0;i<toq-q;i++){
		power(q[i]-block);
		block=q[i];
		ll id=block*n;
		for(;j<top-p&&p[j]/n==block;j++){
			query(1,0,n,id%n,p[j]%n);
			id=p[j];
			if(id==k){
				printf("%d\n",ans[1][0]);
				return 0;
			}
			matrix tmp;
			tmp[0][0]=0;
			tmp[1][0]=1%mo;
			tmp[0][1]=gs(id);
			tmp[1][1]=gs(id+1);
			ans=ans*tmp;
			id++;
		}
		query(1,0,n,id-block*n,n);
		id=(++block)*n;
	}
}