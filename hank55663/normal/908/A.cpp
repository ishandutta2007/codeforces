#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
using namespace std;
typedef long long LL;
int main(){
	char c[105];
	scanf("%s",c);
	int cnt=0;
	for(int i=0;c[i]!=0;i++){
		if(c[i]=='a'||c[i]=='e'||c[i]=='i'||c[i]=='o'||c[i]=='u'){
			cnt++;
		}
		if(c[i]=='1'||c[i]=='3'||c[i]=='5'||c[i]=='7'||c[i]=='9'){
			cnt++;
		}
	}
	printf("%d\n",cnt);
}