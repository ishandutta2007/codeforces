#include<bits/stdc++.h>
#define mp make_pair
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first 
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
typedef long long LL;
using namespace std;
LL s[1<<20];
LL s1[1<<20];
void add(LL *ss,int x,LL add){
	for(int i=x;i<(1<<20);i+=i&-i){
	//	printf("%d %d ",i,add);
		ss[i]+=add;
	}
//	printf("\n");
}
LL query(LL *ss,int x){
	LL res=0;
	for(int i=x;i>0;i-=i&-i){
		res+=ss[i];
	}
	return res;
}
pll query2(LL *ss,int need){
	LL res=0,sum=0;
	for(int i=1<<19;i>0;i>>=1){
		if(sum+ss[res+i]<=need){
			//printf("! %d\n",i);
			sum+=ss[res+i];
			res+=i;
		}
	}
	return mp(res,sum);
}
struct pro{
	int l,r,c,p;
	pro(int a,int b,int _c,int d){
		l=a;
		r=b;
		c=_c;
		p=d;
	}
	pro(){
		
	}
};
bool cmp(const pro &a,const pro &b){
	return a.p<b.p;
}
pro p[200005];
int main(){
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	for(int i=1;i<=m;i++){
		int l,r,c,P;
		scanf("%d %d %d %d",&l,&r,&c,&P);
		p[i]=pro(l,r,c,P);
	}	
	sort(p+1,p+m+1,cmp);
	vector<pii > v;
	for(int i=1;i<=m;i++){
		v.pb(mp(p[i].l,i));
		v.pb(mp(p[i].r+1,-i));
	}
	sort(v.begin(),v.end());
	int index=0;
	LL tot=0;
	for(int i=1;i<=n;i++){
	//	printf("%d",i)
		while(index!=v.size()&&v[index].x==i){
			if(v[index].y>0){
				int x=v[index].y;
				add(s,x,(LL)p[x].c*p[x].p);
				add(s1,x,p[x].c);
			}
			else{
				int x=-v[index].y;
				add(s,x,(LL)-p[x].c*p[x].p);
				add(s1,x,-p[x].c);
			}
		//	printf("%d\n",v[index].y);
			index++;
		}
		pll pp=query2(s1,k);
		LL res=query(s,pp.x);
	//	printf("%lld ",res);
		if(pp.x<m){
			res+=p[pp.x+1].p*(k-pp.y);
		}
	//	printf("%lld %lld %lld\n",pp.x,res,pp.y);
		tot+=res;
	}
	printf("%lld\n",tot);
}