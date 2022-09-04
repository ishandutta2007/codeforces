#include<bits/stdc++.h>
#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pb(x) push_back(x)
#define x first
#define y second
#define N 100005
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define pi 3.14159265359
typedef long long LL	;
using namespace std;
vector<int> v[1000005];
LL fra[1000005];
const LL mod = 1e9+7;
int main(){
	fra[1]=1;
	for(int i=2;i<1000005;i++)
	fra[i]=fra[i-1]*i%mod;
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		int g;
		scanf("%d",&g);
		for(int j=0;j<g;j++){
			int a;
			scanf("%d",&a);
			v[a].pb(i);
		} 
	}
	map<vector<int>,int> M;
	for(int i=1;i<=m;i++) 
	M[v[i]]++;
	long long int ans=1;
	for(map<vector<int>,int> ::iterator it=M.begin();it!=M.end();it++)
	ans*=fra[it->second],ans%=mod;
	printf("%I64d\n",ans);
}