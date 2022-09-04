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
vector<int> v[300005];
vector<int> v1[300005];
vector<int> Ma;
vector<int> Mad;
int main(){
	int n;
	scanf("%d",&n);
	int str[300005];
	int Max=-1e9-1;
	for(int i=1;i<=n;i++)
	scanf("%d",&str[i]),Max=max(str[i],Max);
	for(int i=0;i<n-1;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(str[b]==Max)
		v1[a].pb(b);
		v[a].pb(b);
		if(str[a]==Max)
		v1[b].pb(a);
		v[b].pb(a); 
	}
	for(int i=1;i<=n;i++){
		if(Max==str[i])
		{
			Ma.pb(i);
			v1[i].pb(i);
		}
		else if(Max-1==str[i]){
			Mad.pb(i);
		}
	}
	if(Ma.size()==1){
		int a=Ma[0];
		sort(v[a].begin(),v[a].end());
		for(int i=0;i<Mad.size();i++){
			if(*lower_bound(v[a].begin(),v[a].end(),Mad[i])!=Mad[i]||lower_bound(v[a].begin(),v[a].end(),Mad[i])==v[a].end())
			{
				printf("%d\n",Max+1);
				return 0;
			}
		}
		printf("%d\n",Max);
	}
	else{
		for(int i=1;i<=n;i++){
			if(v1[i].size()==Ma.size()){
			printf("%d\n",Max+1);
			return 0;
			}
		} 
		printf("%d\n",Max+2);
	}
}