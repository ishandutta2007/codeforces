#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
//#define INF 0x7fffffff
#define N 500005
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;
typedef long long LL;
struct ask{
	int l,r;
	LL ans;
	int i;
};
int SZ;
bool cmp1(const ask &a,const ask &b){
	if(a.l/SZ==b.l/SZ){
		return a.r<b.r;
	}
	return a.l<b.l;
}
bool cmp2(const ask &a,const ask &b){
	return a.i<b.i;
}
ask a[100005]; 
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	LL num[100005];
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d",&t);
		if(t==1)
		num[i]=1;
		else
		num[i]=-1;
	}
	num[0]=0;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		num[i]*=a;
	} 
	map<LL,int> m;
	for(int i=2;i<=n;i++){
		num[i]+=num[i-1];
	}
	int index=1;
	int add[N],sub[N];
	for(int i=0;i<=n;i++){
		if(m[num[i]]==0){
			m[num[i]]=index++;
		}
		if(m[num[i]+k]==0){
			m[num[i]+k]=index++;
		}
		if(m[num[i]-k]==0){
			m[num[i]-k]=index++;
		}
		add[m[num[i]]]=m[num[i]+k];
		sub[m[num[i]]]=m[num[i]-k];
		num[i]=m[num[i]];
	}
	int q;
	scanf("%d",&q);
	SZ=n/sqrt(q);
	for(int i=0;i<q;i++){
		int l,r;
		scanf("%d %d",&a[i].l,&a[i].r);
		a[i].l--;
		a[i].i=i;
	}
	sort(a,a+q,cmp1);
	int l=0,r=-1;
	LL ans=0;
	int cnt[N];
	MEM(cnt);
	for(int i=0;i<q;i++){
		while(l<a[i].l)cnt[num[l]]--,ans-=cnt[add[num[l]]],l++;
		while(r>a[i].r)cnt[num[r]]--,ans-=cnt[sub[num[r]]],r--;
		while(l>a[i].l)l--,ans+=cnt[add[num[l]]],cnt[num[l]]++;
		while(r<a[i].r)r++,ans+=cnt[sub[num[r]]],cnt[num[r]]++;
		a[i].ans=ans;
	}
	sort(a,a+q,cmp2);
	for(int i=0;i<q;i++)
	printf("%I64d\n",a[i].ans);
} 

//9
//      5
// 1 2 3 4     6 7 8 9