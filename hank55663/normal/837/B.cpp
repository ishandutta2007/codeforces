#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-9
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
using namespace std;
typedef long long LL;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	char c[105][105];
	for(int i=0;i<n;i++){
		scanf("%s",c[i]);
	}
	char ans[105][105];
	if(n%3==0){
		set<char> s;
		int ok=1;
		for(int i=0;i<n/3;i++)
		for(int j=0;j<m;j++)
		if(c[i][j]!=c[0][0]){
			ok=0;
		}
	//	printf("%d",ok);
		s.insert(c[0][0]);
		for(int i=n/3;i<n/3*2;i++){
			for(int j=0;j<m;j++)
				if(c[i][j]!=c[n/3][0])
				ok=0;
		}
	//	printf("%d",ok);
		s.insert(c[n/3][0]);
		for(int i=n/3*2;i<n;i++)
			for(int j=0;j<m;j++)
				if(c[i][j]!=c[n/3*2][0])
					ok=0;
	//	printf("%d",ok);
		s.insert(c[n/3*2][0]);
		if(s.size()!=3)
		ok=0;
		if(ok){
			printf("YES\n");
			return 0;
		}		
	}
	if(m%3==0){
		set<char> s;
		int ok=1;
		for(int i=0;i<m/3;i++)
		for(int j=0;j<n;j++)
		if(c[j][i]!=c[0][0]){
			ok=0;
		}
	//	printf("%d",ok);
		s.insert(c[0][0]);
		for(int i=m/3;i<m/3*2;i++){
			for(int j=0;j<n;j++)
				if(c[j][i]!=c[0][m/3])
				ok=0;
		}
	//	printf("%d",ok);
		s.insert(c[0][m/3]);
		for(int i=m/3*2;i<m;i++)
			for(int j=0;j<n;j++)
				if(c[j][i]!=c[0][m/3*2])
					ok=0;
		s.insert(c[0][m/3*2]);
	//	printf("%d\n",ok);
		if(s.size()!=3)
		ok=0;
		if(ok){
			printf("YES\n");
			return 0;
		}		
	}
	printf("NO\n");
}