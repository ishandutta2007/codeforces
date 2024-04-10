#include <bits/stdc++.h>
#define mp make_pair
#define LL long long 
#define pii pair<int,int>
#define x first
#define y second
#define pb push_back
#define sqr(x) ((x)*(x))
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
struct treap{
	treap *l,*r;
	LL sum;
	int val;
	int Size;
	treap(int k):l(NULL),r(NULL),Size(1),sum(k),val(k){

	}
}*root;
int Size(treap *t){
	return t?t->Size:0;
}
LL sum(treap *t){
	return t?t->sum:0;
}
void pull(treap *t){
	t->sum=sum(t->l)+sum(t->r)+t->val;
	t->Size=Size(t->l)+Size(t->r)+1;
}
treap *merge(treap *l,treap *r){
	if(!l||!r)return l?l:r;
	if(rand()%(Size(l)+Size(r))<Size(l)){
		l->r=merge(l->r,r);
		pull(l);
	}
	else{
		r->l=merge(l,r->l);
		pull(r);
	}
}
void split_size(treap *t,int k,treap *&l,treap *&r){
	//printf("!%d\n",k);
	if(!t)l=r=NULL;
	else if(Size(t->l)<k){
		//printf("!%d %d\n",Size(t->l),k);
		l=t;
		split_size(t->r,k-Size(t->l)-1,l->r,r);
		pull(l);
	}
	else{
		//printf("?%d %d\n",Size(t->l),k);
		r=t;
		split_size(t->l,k,l,r->l);
		pull(r);
	}
}
void split_val(treap *t,int k,treap *&l,treap *&r){
	if(!t)l=r=NULL;
	else if(t->val<k){
		l=t;
		split_val(t->r,k,l->r,r);
		pull(l);
	}
	else{
		r=t;
		split_val(t->l,k,l,r->l);
		pull(r);
	}
}
void add(int k){
	treap *l,*r;
	split_val(root,k,l,r);
	root=merge(l,merge(new treap(k),r));
}
int main() {
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	LL cnt1[200005];
	LL cnt2[200005];
	vector<pii> v1,v2,v3,v4;
	for(int i = 0;i<n;i++){
		int t,a,b;
		scanf("%d %d %d",&t,&a,&b);
		if(a==1&&b==1){
			v3.pb(mp(t,i+1));
		}
		else if(a==1){
			v1.pb(mp(t,i+1));
		}
		else if(b==1){
			v2.pb(mp(t,i+1));
		}
		else{
			v4.pb(mp(t,i+1));
		}
	}
	sort(v3.begin(),v3.end());
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	sort(v4.begin(),v4.end());
	for(auto it:v4){
		root=merge(root,new treap(it.x));
		//printf("?%d",Size(root));
	}
	fill(cnt1,cnt1+200005,1e18);
	cnt1[0]=0;
	for(int i = 0;i<v1.size();i++){
		cnt1[i+1]=cnt1[i]+v1[i].x;
	}
	fill(cnt2,cnt2+200005,1e18);
	cnt2[0]=0;
	for(int i = 0;i<v2.size();i++){
		cnt2[i+1]=cnt2[i]+v2[i].x;
	}
	for(int i = k;i<v2.size();i++){
		add(v2[i].x);
		//printf("!%d",Size(root));
	}
	for(int i = k;i<v1.size();i++){
		add(v1[i].x);
	//	printf("!%d",Size(root));
	}
	LL ans=3e18;
	LL ansi;
//	printf("%d\n",Size(root));
	if(2*k<=m&&Size(root)>=m-2*k){
		treap *l,*r;
		split_size(root,m-2*k,l,r);
		ans=cnt1[k]+cnt2[k]+sum(l);
		//printf("%d %d %d %d\n",sum(l),Size(r),Size(l),m-2*k);
		root=merge(l,r);
		ansi=0;
	}
	LL tmp=0;
	for(int i = 0;i<v3.size()&&i<m;i++){
		tmp+=v3[i].x;
	//	printf("%d %d\n",tmp,k-i);
		if(k-i-1>=0){
			if(k-i-1<v1.size()&&k-i-1>=0){
				
				add(v1[k-i-1].x);
			}
			if(k-i-1<v2.size()&&k-i-1>=0){
				add(v2[k-i-1].x);
			}
		}
		if(i+1+2*(k-i-1)<=m){
	//		printf("%d\n",Size(root));
			if(Size(root)>=max(m-i-1-max(2*(k-i-1),0),0)){
				treap *l,*r;
				split_size(root,max(m-i-1-max(2*(k-i-1),0),0),l,r);
				//printf("%d %d\n",max(2*(k-i-1),0),max(m-i-1,0));

				LL val;
				//printf("%d\n",i+1);
				if(k-i-1>=0){
				//	printf("%lld %lld %lld %lld\n",sum(l),tmp,cnt1[k-i-1],cnt2[k-i-1]);
				val=sum(l)+tmp+cnt1[k-i-1]+cnt2[k-i-1];
				}
				else{
				//	printf("%lld %lld\n",sum(l),tmp);
					val=sum(l)+tmp;
				}
				if(val<ans){
					ans=min(ans,val);
					ansi=i+1;
				}
				root= merge(l,r);
			}
		}
	}
	if(ans>1e17){ans=-1;
		printf("%lld\n",ans);
	}
	else{
		printf("%lld\n",ans);
		for(int i = 0;i<ansi;i++){
			printf("%d ",v3[i].y);
		}
		for(int i = 0;i<k-ansi;i++){
			printf("%d ",v1[i].y);
			printf("%d ",v2[i].y);
		}
		vector<pii> tmp;
		for(auto it:v4)tmp.pb(it);
		for(int i = ansi;i<v3.size();i++)tmp.pb(v3[i]);
		for(int i = max(k-ansi,0ll);i<v1.size();i++)tmp.pb(v1[i]);
		for(int i = max(k-ansi,0ll);i<v2.size();i++)tmp.pb(v2[i]);
		sort(tmp.begin(),tmp.end());
		for(int i = 0;i<m-ansi-max(2*(k-ansi),0ll);i++){
			printf("%d ",tmp[i].y);
		}
		printf("\n");
	}
	return 0;
}