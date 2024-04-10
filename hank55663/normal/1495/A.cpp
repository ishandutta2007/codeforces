#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
bool solve(){
	int n;
	scanf("%d",&n);
	vector<LL> x,y;
	for(int i = 0;i<2*n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a==0)y.pb(abs(b));
		else x.pb(abs(a));
	}
	sort(x.begin(),x.end());
	sort(y.begin(),y.end());
	double ans=0;
	for(int i = 0;i<n;i++){
		ans+=sqrt(x[i]*x[i]+y[i]*y[i]);
	}
	printf("%.12f\n",ans);
}
/*
5 5
2 8
*/
int main(){
		//MEMS(dp);
	int t=1;//000000;//000000;
    scanf("%d",&t);
    //MEMS(dp);
	while(t--)solve();
}