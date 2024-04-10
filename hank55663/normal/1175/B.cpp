#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
	int n;
	scanf("%d",&n);
	LL x;
	vector<LL> v;
	vector<LL> tmp;
	tmp.pb(0);
	for(int i = 0;i<n;i++){
		char c[5];
		scanf("%s",c);
		if(c[0]=='a'){
			tmp.back()++;
		}
		if(c[0]=='f'){
			int x;
			scanf("%d",&x);
			v.pb(x);
			tmp.pb(0);
		}
		if(c[0]=='e'){
			LL x=tmp.back();
			x*=v.back();
			tmp.pop_back();
			v.pop_back();
			tmp.back()+=x;
			if(tmp.back()>=2147483648ll*2){
				printf("OVERFLOW!!!\n");
				return 0;
			}
		}
	}
	if(tmp.back()>=2147483648ll*2){
		printf("OVERFLOW!!!\n");
			return 0;
	}
	printf("%lld\n",tmp.back());
}