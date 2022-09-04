#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
bool cmp(const pii &a,const pii &b){
	if((LL)abs(a.x)*abs(b.y)==(LL)abs(b.x)*abs(a.y)){
		if((a.y^b.y)<0){
			return a.y>b.y;
		}
		return a.y<b.y;
	}
	return (LL)abs(a.x)*abs(b.y)<(LL)abs(b.x)*abs(a.y);
}
bool cmp2(const pii &a,const pii &b){
	return (LL)abs(a.x)*abs(b.y)<(LL)abs(b.x)*abs(a.y);
}
LL ans=0;
pii p[1000005];
pii temp[1000005];
void merge(int l,int mid,int r){
	int i=l,j=mid;
	int now=l;
	while(1){
		if(now==r+1)
		break;
		if(i==mid)
		temp[now++]=p[j++];
		else if(j==r+1)
		temp[now++]=p[i++];
		else if(cmp2(p[i],p[j]))
		temp[now++]=p[i++];
		else{
			temp[now++]=p[j++];
			ans+=mid-i;
		}
	}
	for(int i=l;i<=r;i++)
	p[i]=temp[i];
}
void merge_sort(int l,int r){
	if(l==r)
	return;
	int mid=(l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	merge(l,mid+1,r);
}
int main(){
	int n,w;
	scanf("%d %d",&n,&w);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
	//	a=rand()%100000+w+1;
	//	b=rand()%100000+w+1;
		b+=w;
		p[i]=mp(a,b);
	}
	stable_sort(p,p+n,cmp);
	for(int i=0;i<n;i++){
		p[i].y-=2*w;
	}
	merge_sort(0,n-1);
	printf("%lld\n",ans);
}