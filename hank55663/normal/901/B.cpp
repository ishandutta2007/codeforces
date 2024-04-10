#include<bits/stdc++.h>

#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi 3.14159265359
#define INF 0x7fffffff
#define next Next
using namespace std;
typedef long long LL;
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
//	scanf("%d",&n);
	if(n==0){
		printf("-1\n");
	}
	else{
		vector<int> v[2];
		v[0].pb(0);
		v[0].pb(1);
		v[1].pb(1);
		for(int i=1;i<n;i++){
			vector<int> temp=v[0];
			reverse(v[0].begin(),v[0].end());
			v[0].pb(0);
			reverse(v[0].begin(),v[0].end());
		//	reverse(v[1].begin(),v[1].end());
			int ok=1;
			for(int j=0;j<v[1].size();j++){
				if(v[0][j]+v[1][j]>1)
				ok=0;
				if(v[0][j]+v[1][j]<-1)
				ok=0;
			}
			if(ok){
				for(int j=0;j<v[1].size();j++)
				v[0][j]+=v[1][j];
			}
			else{
				for(int j=0;j<v[0].size();j++)
				v[0][j]=-v[0][j];
				for(int j=0;j<v[1].size();j++)
				v[0][j]+=v[1][j];
			}
			v[1]=temp;
		}
		if(v[0].back()==-1)
		for(int i=0;i<v[0].size();i++)
		v[0][i]=-v[0][i];
		if(v[1].back()==-1)
		for(int i=0;i<v[1].size();i++)
		v[1][i]=-v[1][i];
		printf("%d\n",v[0].size()-1);
		for(auto it=v[0].begin();it!=v[0].end();it++)
		printf("%d ",*it),assert(*it<=1&&*it>=-1);
		printf("\n%d\n",v[1].size()-1);
		for(auto it=v[1].begin();it!=v[1].end();it++)
		printf("%d ",*it),assert(*it<=1&&*it>=-1);
	}
	}
}