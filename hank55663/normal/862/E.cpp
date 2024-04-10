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
#define list List
using namespace std;
typedef long long LL;
int a[100005];
int b[100005];
int main(){
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	for(int i=0;i<m;i++)
	scanf("%d",&b[i]);
	set<LL> s;
	LL now=0;
	for(int i=0;i<n;i++){
		if(i&1)
		now-=a[i];
		else
		now+=a[i];
	} 
	LL temp=0;
	for(int i=0;i<n-1;i++){
		if(i&1)
		temp-=b[i];
		else
		temp+=b[i];
	}
	for(int i=n-1;i<m;i++){
		if(n&1)
			temp+=b[i];
		else
			temp-=b[i];
		//printf("%d\n",temp);
		s.insert(temp);
		temp-=b[i-n+1];
		temp=-temp;
	}
	for(int i=0;i<=q;i++){
		if(i!=0){
			int l,r,x;
			scanf("%d %d %d",&l,&r,&x);
			if((r-l+1)%2==1){
				if(l&1){
					now+=x;
				//	printf("!");
				}
				else{
					now-=x;
				//	printf("?");
				}
			//	printf("<");
			} 
		}
		set<LL>::iterator it=s.lower_bound(now);
		//printf("%I64d\n",now);
		LL ans=1e18;
		if(it!=s.end()){
			ans=min(*it-now,ans);
		}
		if(it!=s.begin()){
			it--;
			ans=min(now-*it,ans);
		}
		printf("%I64d\n",ans);
	}
}