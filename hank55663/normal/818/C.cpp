#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#define Min(a,b,c) min((a),min((b),(c)))
#define Max(a,b,c) max((a),max((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define EPS 1e-11
//#define N 505
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define sqr(x) ((x)*(x))
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long LL;
struct sofa{
	int x1,y1,x2,y2;
	sofa(){
	}
	sofa(int a,int b,int c,int d):x1(a),y1(b),x2(c),y2(d){
	}
};
int main(){
	int D;
	scanf("%d",&D);
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> x1,y1,x2,y2;
	sofa s[100005];
	for(int i=0;i<D;i++){
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		if(a>c)
		swap(a,c);
		if(b>d)
		swap(b,d);
				s[i]=sofa(a,b,c,d);
		//printf("%d %d %d %d",s[i].x1,s[i].x2,s[i].y1,s[i].y2);
		x1.pb(a);
		y1.pb(b);
		x2.pb(c);
		y2.pb(d);
	} 
	sort(x1.begin(),x1.end());
	sort(x2.begin(),x2.end());
	sort(y1.begin(),y1.end());
	sort(y2.begin(),y2.end());
	int l,r,t,b;
	scanf("%d %d %d %d",&l,&r,&t,&b);
	for(int i=0;i<D;i++){
		int ll=lower_bound(x1.begin(),x1.end(),s[i].x2)-x1.begin();
		int rr=x2.end()-upper_bound(x2.begin(),x2.end(),s[i].x1);
		int tt=lower_bound(y1.begin(),y1.end(),s[i].y2)-y1.begin();
		int bb=y2.end()-upper_bound(y2.begin(),y2.end(),s[i].y1);
	//	printf("%d %d %d %d %d %d %d %d\n",ll,rr,bb,tt,s[i].x1,s[i].x2,s[i].y1,s[i].y2);
		if(s[i].x1!=s[i].x2){
			ll--;
			rr--;
		}
		if(s[i].y1!=s[i].y2){
			bb--;
			tt--;
		} 
	//	printf("%d %d %d %d %d %d %d %d\n",ll,rr,tt,bb,l,r,t,b);
		if(ll==l&&rr==r&&bb==b&&tt==t){
			printf("%d\n",i+1);
			return 0;
		}
	}
	printf("-1\n");
	 
}
//Axyz=xy+yz+zx
// Y k  
// S k+y|k+y+a
//P k+p/k+p+b
// S k+p+s+0~2=k+y+0~1
// 3*k+y+p+a+b=12+j