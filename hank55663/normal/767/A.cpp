#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stack> 
#include<set>
#include<map>
#include<iostream>
#include<assert.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
int visit[100005];
int main(){
	int n;
	scanf("%d",&n);
	stack<int> s;
	s.push(0);
	memset(visit,0,sizeof(visit));
	int num=n;
	for(int i=0;i<n;i++){
		int a;
		scanf("%d",&a);
		visit[a]=1;
		if(a==num)
		printf("%d",num--);
		while(visit[num])
		printf(" %d",num--);
		printf("\n");
	}
}