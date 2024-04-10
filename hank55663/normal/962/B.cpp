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
int main(){
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);
	if(a>b)
	swap(a,b);
	char c[200005];
	MEM(c);
	scanf("%s",c);
	c[n]='*';
	int last=0;
	int ans=0;
	for(int i=0;c[i]!=0;i++){
		if(c[i]=='*'){
			int num=i-last;
			last=i+1;
			ans+=min(a,num/2);
			ans+=min(b,num/2);
			a-=num/2;
			b-=num/2;
			//printf("%d\n",ans);
			if(a<0)a=0;
			if(b<0)b=0;
			if(num%2==1&&b!=0){
				b--;
				ans++;
			}
			if(a>b)
			swap(a,b);
		}
	}
	printf("%d\n",ans);
}