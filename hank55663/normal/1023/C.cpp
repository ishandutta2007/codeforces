#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	char c[200005];
	scanf("%s",c);
	vector<int> l,r;
	for(int i=0;c[i]!=0;i++){
		if(c[i]=='(')
		l.pb(i);
		else
		r.pb(i);
	}
	int print[200005];
	MEM(print);
	for(int i=0;i<k/2;i++){
		print[l[i]]=1;
		print[r[i]]=1;
	}
	for(int i=0;i<n;i++){
		if(print[i])
		printf("%c",c[i]);
	}
	printf("\n");
}