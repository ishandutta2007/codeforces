#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
bool cmp(const pair<int,pii> &a,const pair<int,pii> &b){
	return a.y.y-a.y.x<b.y.y-b.y.x;
}
int main(){
	int n,s;
	scanf("%d %d",&n,&s);
	pair<int,pii> p[100005];
	LL sum=0;
	for(int i=0;i<n;i++){
		scanf("%d %d %d",&p[i].x,&p[i].y.x,&p[i].y.y);
		sum+=p[i].x;
	}
	sort(p,p+n,cmp);
	LL ans=0;
	LL a=0,b=0;
	LL suma=0,sumb=0;
	int middle=-1;
	for(int i=0;i<n;i++){
		if(p[i].y.y-p[i].y.x>0){
			if(middle==-1)
			middle=i;
			if(b>p[i].x){
				b-=p[i].x;
				ans+=(LL)p[i].x*p[i].y.y;
			}
			else{
				ans+=(LL)p[i].x*p[i].y.y;
				sumb+=(p[i].x-b+s-1)/s;
				b=s-(p[i].x-b)%s;
				if(b==s){
					b=0;
				}
			}
		}
		else{
			if(a>p[i].x){
				a-=p[i].x;
				ans+=(LL)p[i].x*p[i].y.x;
			}
			else{
				ans+=(LL)p[i].x*p[i].y.x;
				suma+=(p[i].x-a+s-1)/s;
				a=s-(p[i].x-a)%s;
				if(a==s)
				{
					a=0;
				}
			}
		}
	}
	if(suma+sumb==(sum+s-1)/s){
		printf("%I64d\n",ans);
	}
	else{
		assert(suma+sumb-(sum+s-1)/s==1);
		LL ans1=ans;
		for(int i=middle;;i++){
			if(b+p[i].x>=s){
				ans+=(LL)(s-b)*(p[i].y.x-p[i].y.y);
				break;
			}
			else{
				ans+=(LL)p[i].x*(p[i].y.x-p[i].y.y); 
				b+=p[i].x;
			}
		}
		for(int i=middle-1;;i--){
			if(a+p[i].x>=s){
				ans1+=(LL)(s-a)*(p[i].y.y-p[i].y.x);
				break; 
			}
			else{
				ans1+=(LL)p[i].x*(p[i].y.y-p[i].y.x);
				a+=p[i].x;
			}
		}
		printf("%I64d\n",max(ans,ans1));
	}
}