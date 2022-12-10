#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

const int MOD=1000000000+7;
const int MAX=2010;
long long t[MAX+10][MAX+10];
int n,p[MAX],inv[MAX];
main(){
	scanf("%d",&n);
	memset(inv,-1,sizeof(inv));
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		if(p[i]!=-1)inv[p[i]]=i;
	}
	int single=0,longer=0;
	for(int i=1;i<=n;i++)single+=p[i]==-1&&inv[i]==-1;
	for(int i=1;i<=n;i++)longer+=p[i]==-1&&inv[i]!=-1;
	for(int i=0;i<MAX;i++)for(int j=0;j<MAX;j++){
		if(!i&&!j){
			t[i][j]=1;
			continue;
		}
		if(!i){
			t[i][j]=t[i][j-1]*j%MOD;
			continue;
		}
		t[i][j]=((i>1?t[i-2][j+1]*(i-1):0)+t[i-1][j]*j)%MOD;
	}
	printf("%d\n",t[single][longer]);
}