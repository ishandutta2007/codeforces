#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>
#include<set>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
int b[32];
int vis[410][410];
bool f[410][410][30][8];
int dx[]={1,1,0,-1,-1,-1,0,1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int D=200;
int main(){
	int a,b;scanf("%d%d",&a,&b);
	int t=(240-b)/5;
	for(int i=a;i>=0;i--){
		if(i*(i+1)/2<=t){
			printf("%d\n",i);
			return 0;
		}
	}
}