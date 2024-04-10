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
vector<int> each[1000+10];
int dis[1000+10][1000+10];

int main(){
	memset(dis,0x3f,sizeof(dis));
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	rep(i,m){
		int xi,yi;
		cin>>xi>>yi;
		each[xi].PB(yi),each[yi].PB(xi);
	}
	rb(i,1,n){
		queue<int> Q;
		Q.push(i);
		dis[i][i]=0;
		int v[1001]={0};
		while(!Q.empty()){
			int now=Q.front();
			Q.pop();
			if(v[now]) continue;
			v[now]=1;
//			Q.pop();
			int SZ=each[now].size();
			rep(j,SZ){
				int to=each[now][j];
				if(!v[to]&&dis[i][to]>dis[i][now]+1){
					dis[i][to]=dis[i][now]+1;
					Q.push(to);
				}
			}
		}
	} 
	int res=0;
	rb(i,1,n){
		rb(j,i+1,n){
			if(dis[i][j]!=1)
			if(min(dis[s][i]+1+dis[j][t],dis[s][j]+1+dis[i][t])>=dis[s][t]) {
//				cout<<i<<" "<<j<<endl;
				res++;
			}
		}
	}
	cout<<res<<endl;
	return 0;
}