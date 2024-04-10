/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int  n,m,d,u[5000000+5],v[5000000+5];bool val[5000000+5];int VAL[5000000+5];
vector<int> each1[5000000+5];
int change(int i,int j){
	if(j>d) j=1;
	return (i-1)*d+j;
}
bool vis[5000000+5];int belong[5000000+5],cnt;
stack<int> S;
int ALL=0;
void dfs1(int now){
	ALL++;
	if(ALL>=5000000+5){
		cout<<"ONE ERRO"<<endl;
		exit(0);
	}
	vis[now]=1;
	for(auto it:each1[now]){
		if(it>=5000000+5){
			cout<<"TWO ERRO"<<endl;
			exit(0);
		}

		if(!vis[it])dfs1(it);
		
	}
	
	S.push(now);
	
}
queue<int> cc;
int  used[5000000+1]={0};
void dfs2(int now){
	vis[now]=1;
	belong[now]=cnt;
	int B=(now+d-1)/d;
	if(val[now])
	if(!used[B]){
		used[B]=1;
		cc.push(B);
		VAL[cnt]++;
	}
	for(auto it:each1[now])
		if(!vis[it]) dfs2(it);
}

int dfs_m(int now){
	if(vis[now]) return v[now];
	vis[now]=1;
	for(auto it:each1[now]){
		v[now]=max(dfs_m(it),v[now]);
	}
	v[now]+=VAL[now];
	return v[now];
}
int main(){
	fastio;
	int M=0;
	cin>>n>>m>>d;
//	int FFF=0,UUU; 
	rb(i,1,m){
		int U,V;
		cin>>U>>V;
//		if(!FFF){
//			UUU=U;
//			FFF=1;
//		}
		rb(j,1,d){
			each1[change(U,j)].PB(change(V,j+1));
//			eachrev[change(V,j+1)].PB(change(U,j));
			u[++M]=change(U,j);
			v[M]=change(V,j+1);	
		}
	}
//	UUU=INF;
	rb(i,1,n)
		{
			string s;
			cin>>s;
			rep(j,d){
				val[change(i,j+1)]=s[j]-'0';
			}
		}
//	if(UUU==27964 ){
////		cout<<"Finish 1"<<" "<<n*d;
//		for(auto it:each1[1]){
//			cout<<it<<" ";
//		}
////		return 0;
//	}
	rb(i,1,n*d){
		if(!vis[i]){//if(UUU==27964 ){
//		cout<<i<<"\n";
//	//		return 0;
//		}
			dfs1(i);
		}
		
	}
	
	rb(i,1,n*d)
		each1[i].clear();
	rb(i,1,M)
		each1[v[i]].PB(u[i]);
	memset(vis,0,sizeof(vis));
	while(!S.empty()){
		int it=S.top();
		S.pop();
		if(!vis[it]){
			cnt++;
			dfs2(it);
			while(!cc.empty()){
				int now=cc.front();
				cc.pop();
				used[now]=0;
			}
		}
	}
//	if(UUU==27964 ){
//		cout<<"Finish 2";
//	}
	rb(i,1,n*d)
		each1[i].clear();
	rb(i,1,M){
		int U,V;
		U=u[i],V=v[i];
		if(belong[U]==belong[V]){
			
		}
		else{
			each1[belong[V]].PB(belong[U]);
		}
	}
//	if(UUU==27964 ){
//		cout<<"Finish 3";
//	}
	memset(v,-63,sizeof(v));
	v[belong[change(1,1)]]=VAL[belong[change(1,1)]];
	int res=0;
	memset(vis,0,sizeof(vis));
	vis[belong[change(1,1)]]=1;
	rb(i,1,cnt){
		dfs_m(i);
		res=max(res,v[i]);
	}
	cout<<res<<endl;
	return 0;
}