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
int main(){
	int n;
	scanf("%d",&n);
	int s[105];
	for(int i=0;i<n;i++)
	scanf("%d",&s[i]);
	int ans=0;
	int zero=0;
	for(int i=0;i<n;i++){
		int sum=n;
		if(s[i]==0){
			zero++;
			continue;
		}
		for(int j=0;j<i;j++){
			if(s[j]==1)
			sum--;
		}
		for(int j=i+1;j<n;j++)
			if(s[j]==0)
			sum--;
		ans=max(ans,sum);
	}
	if(ans==0)
	ans=n;
	printf("%d\n",max(ans,zero));
}