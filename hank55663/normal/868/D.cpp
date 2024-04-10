#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define MAXN 100005
#define MAXD 2
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int s[205][12][4096];
int main(){
	int n;
	scanf("%d",&n);
	string st[205];
	MEM(s);
	for(int i=0;i<n;i++){
		cin>>st[i];
		for(int j=0;j<st[i].size();j++){
			int sum=0;
			for(int k=0;k<12&&k+j<st[i].size();k++){
				sum<<=1;
				sum+=st[i][j+k]-'0';
				s[i][k][sum]=1;
			}	
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		a--;
		b--;
		st[i+n]=st[a]+st[b];
		for(int j=0;j<12;j++)
			for(int k=0;k<4096;k++){
				s[i+n][j][k]=s[a][j][k]|s[b][j][k];
			}
		for(int j=0;j<st[i+n].size();j++){
			int sum=0;
			for(int k=0;k<12&&k+j<st[i+n].size();k++){
				sum<<=1;
				if(st[i+n][j+k]=='2')
				break;
				sum+=st[i+n][j+k]-'0';
				s[i+n][k][sum]=1;
			}	
		}
		int print=0;
		for(int j=0;j<12;j++){
			int ok=1;
			for(int k=0;k<(1<<(j+1));k++){
				if(!s[i+n][j][k]){
					ok=0;
					break;
				}
			}
			if(!ok){
				print=1;
				printf("%d\n",j);
				break;
			}
		} 
		assert(print);
		if(st[i+n].size()>40){
			st[i+n]=st[i+n].substr(0,13)+"2"+st[i+n].substr(st[i+n].size()-13,13);
		}
	}
} 
//200 2048 11
//10 
//01 
//1001 
//10011