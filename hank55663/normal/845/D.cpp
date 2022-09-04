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
#define N 500005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define list List
using namespace std;
typedef long long LL;
using namespace std;
	pii p[400005];
int main(){
	int n;
	scanf("%d",&n);
	vector<pii> speed_limit;
	int speed,overtake_allow=0;
	int ans=0;
	for(int i=0;i<n;i++){
		int op;
		scanf("%d",&op)
		;if(op==1) {
			int a;
			scanf("%d",&a);
	//		sort(speed_limit.begin(),speed_limit.end());
			while(!speed_limit.empty()&&speed_limit.back().x<a){
				ans+=speed_limit.back().y;
				speed_limit.pop_back();
			}
			speed=a;
		}
		else if(op==2){
			ans+=overtake_allow;
			overtake_allow=0;
		} 
		else if(op==3){
			int a;
			scanf("%d",&a);
			if(a<speed){
				ans++;
				continue;
			}
			int sum=1;
			while(!speed_limit.empty()&&speed_limit.back().x<=a)
			sum+=speed_limit.back().y,speed_limit.pop_back();//sum++;
			speed_limit.pb(mp(a,sum));
		}
		else if(op==4){
			overtake_allow=0;
		}
		else if(op==5){
			speed_limit.clear();
		}
		else if(op==6){
			overtake_allow++;
		}
	//	printf("ans:%d\n",ans);
	}
	printf("%d",ans);
}
/*
14%20,15#17
20,14-18
1#5,11,4%10,14-18,20,21
11,21,20,14-18,4%10,1#5

*/