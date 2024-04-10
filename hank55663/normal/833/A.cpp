#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
//#define N 800005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
using namespace std;
typedef long long LL;
int main()
{
	map<LL,LL> s;
	for(LL i=1;i<=1e6;i++)
	s[i*i*i]=i;
	int n;
	scanf("%d",&n);
	while(n--){
		LL a,b;
		scanf("%I64d %I64d",&a,&b);
		if(s.find(a*b)==s.end()){
			printf("No\n");
		}
		else{
			if(a%s[a*b]!=0||b%s[a*b]!=0){
				printf("No\n");
			}
			else
			printf("Yes\n");
		}
	}
}