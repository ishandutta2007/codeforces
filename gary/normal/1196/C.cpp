//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;int x[100000+10],y[100000+10];
//map<mp,int> tot;
inline void solve(){
//	tot.clear();
	int n;
	int x1=-100000,x2=100000;
	int y1=-100000,y2=100000;
	scanf("%d",&n);
//	int flag=0;
	rb(i,1,n)
	{
		int f1,f2,f3,f4;
		scanf("%d %d %d %d %d %d",&x[i],&y[i],&f1,&f2,&f3,&f4);
		if(!f1){
			x1=max(x1,x[i]);
		}
		if(!f2){
			y2=min(y2,y[i]);
		}
		if(!f3){
			x2=min(x2,x[i]);
			
		}
		if(!f4){
			y1=max(y1,y[i]);
			
		}
	}if(y1>y2){
				puts("0");
				return ;
			}if(x1>x2){
				puts("0");
				return;
			}
			
	printf("1 %d %d\n",x1,y1);
}
int main(){
//	freopen("robot.out","w",stdout);
	int q;
	scanf("%d",&q);
	while(q--){
		solve();
	}
	return 0;
}