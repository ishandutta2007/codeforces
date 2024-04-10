//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m,p[1000001];
int path[101][101];
/*
1.dis[i][j]
2. ... 
*/ 
int dis[101][101];
void folyd(){
	rb(k,1,n){
		rb(i,1,n){
			rb(j,1,n){
				if(path[i][k]&&path[k][j]){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
//					cout<<i<<" "<<j<<":"<<dis[i][j]<<endl;
				}
			}
		}
	}
}
int pre[1000000+10];
int main(){
	memset(dis,63,sizeof(dis));
	cin>>n;
	rb(i,1,n)
		rb(j,1,n){
			char CC;
			cin>>CC;
			path[i][j]=CC-'0';
			path[i][i]=1;
		} 
	rb(i,1,n){
		rb(j,1,n){
			if(path[i][j]) dis[i][j]=1;
		}
		dis[i][i]=0;
	}
	cin>>m;
	rb(i,1,m) scanf("%d",&p[i]);
	folyd();
	int last=p[1],PRE=1;
	for(int i=2;i<=m;){
		while(i<=m&&dis[last][p[i]]>=i-PRE){
			i++;
		}
		i--;
		pre[i]=PRE;
		PRE=i;
		last=p[i];
		i++;
//		cout<<i<<" "<<PRE<<endl;
	}
	int now=m;
	stack<int> ES;
	KEEP{
		ES.push(p[now]);
		if(now==1) break;
		now=pre[now];
	}
	cout<<ES.size()<<endl;
	while(!ES.empty()){
		printf("%d ",ES.top());
		ES.pop();
	}
	return 0;
}