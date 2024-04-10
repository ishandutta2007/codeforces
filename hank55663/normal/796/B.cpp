//#include<stdio.h>
//#include<stdlib.h>
#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define MEM(x) memset(x,0,sizeof(x))
//#define N 200005
#define M
#define pi 3.14159265359
using namespace std;
typedef long long LL;
int main(){
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	set<int> s;
	for(int i=0;i<m;i++){
		int a;
		scanf("%d",&a);
		s.insert(a);
	}
	int now=1;
	for(int i=0;i<k;i++){
		if(s.find(now)!=s.end())
		break;
		int a,b;
		scanf("%d %d",&a,&b);
		if(now==a)
		now=b;
		else if(now==b)
		now=a;
	}
	printf("%d\n",now);
}