#include <bits/stdc++.h>
#define pb push_back
#define LL long long
#define x first
#define y second
#define pii pair<int,int>
#define mp make_pair
#define MEM(x) memset(x,0,sizeof(x))
#define pi acos(-1)
using namespace std;
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int group = m;
	if(group==0)group=1;
	n-=m;
	printf("%d\n",min(group,n));
	return 0;
}