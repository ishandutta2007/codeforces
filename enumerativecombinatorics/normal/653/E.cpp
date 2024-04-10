#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-9;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
int p[310000];
int q[310000];
set<pair<int,int> >S;
int v[310000];
set<int>rem;
void dfs(int a){
	v[a]=1;
	vector<int>nx;
	for(set<int>::iterator it=rem.begin();it!=rem.end();it++){
		int to=*it;
		if(S.count(make_pair(to,a)))continue;
		nx.push_back(to);
	}
	for(int i=0;i<nx.size();i++)rem.erase(nx[i]);
	for(int i=0;i<nx.size();i++)dfs(nx[i]);
}
int main(){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<b;i++){
		scanf("%d%d",p+i,q+i);p[i]--;q[i]--;
		S.insert(make_pair(p[i],q[i]));
		S.insert(make_pair(q[i],p[i]));
	}
	int can=0;
	int have=0;
	bool ok=true;
	for(int i=1;i<a;i++)rem.insert(i);
	for(int i=1;i<a;i++){
		if(S.count(make_pair(0,i)))continue;
		can++;
		if(!rem.count(i))continue;
		have++;
		rem.erase(i);
		dfs(i);
	}
	if(!rem.empty())ok=false;
	if(have>c||can<c||!ok){
		printf("im");
	}
	printf("possible\n");
}