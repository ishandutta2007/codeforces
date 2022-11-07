#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 300000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define Pi acos(-1.)
#define eps 1e-8
using namespace std;
int n,x,y,nw;
multiset<int>s1,s2;
struct pr{int x,l,r;bool f;}a[N];
bool cmp(pr x,pr y){
	if(x.x==y.x)return x.f<y.f;return x.x<y.x;
}
void wr(int x,int y){;
	printf("%d %d",x,y);exit(0);
}
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d%d%d",&a[i].x,&x,&a[i+n].x,&y);
		a[i].l=a[i+n].l=x;a[i].r=a[i+n].r=y;a[i+n].f=1;
	}
	sort(a+1,a+n*2+1,cmp);
	rep(i,1,n*2){
		if(a[i].f){nw--;
			s1.erase(s1.lower_bound(a[i].l));
			s2.erase(s2.lower_bound(a[i].r));
		}else{nw++;
			s1.insert(a[i].l);s2.insert(a[i].r);
		}
		if((nw>=n-1)&&(!s1.empty())){
			auto p=--s1.end(),q=s2.begin();
			if((nw==n)&&(p!=s1.begin())){
				p--;if(*p<=*q)wr(a[i].x,*p);p++;
				q++;if(*p<=*q)wr(a[i].x,*p);q--;
			}
			if(*p<=*q)wr(a[i].x,*p);
		}
	}
}