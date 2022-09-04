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
	char c[15];
	scanf("%s",c);
	vector<int> v;
	for(LL i=1;i*i<=2e9;i++){
		v.pb(i*i);
	}
	int ans=-1;
	for(auto it:v){
		char c1[15];
		sprintf(c1,"%d",it);
		int j=0;
		for(int i=0;c[i]!=0;i++){
			if(c[i]==c1[j])
			j++;
		}
		if(c1[j]==0)
		ans=strlen(c)-strlen(c1);
	}
	printf("%d\n",ans);
}