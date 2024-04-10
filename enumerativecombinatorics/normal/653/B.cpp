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
int ret=0;
int to[6][6];
char in1[10];
char in2[10];
int p[10];
int q[10];
void dfs(int a,int b){
	if(a==0){
		for(int i=0;i<b;i++)q[i]=p[i];
		bool ok=true;
		for(int i=0;i<b-1;i++){
			if(to[q[i]][q[i+1]]==-1){
				ok=false;break;
			}
			q[i+1]=to[q[i]][q[i+1]];
		}
		if(q[b-1]!=0)ok=false;
		if(ok)ret++;
		return;
	}
	for(int i=0;i<6;i++){
		p[b]=i;
		dfs(a-1,b+1);
	}
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<6;i++)for(int j=0;j<6;j++)to[i][j]=-1;
	for(int i=0;i<b;i++){
		scanf("%s%s",in1,in2);
		to[in1[0]-'a'][in1[1]-'a']=in2[0]-'a';
	}
	dfs(a,0);
	printf("%d\n",ret);
}