/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
6.long double | 
7.!(prince and princess)
8. CSPday2 meal
9.-or
10.
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
struct edge{
	int f,t,c;
};
vector<edge> v;
vector<int> each[202];
void make_edge(int u,int V,int c){
	edge E;
	E.f=u;
	E.t=V;
	E.c=c;
	v.PB(E);
	E.c=0;
	swap(E.f,E.t);
	v.PB(E);
	each[u].PB(v.size()-2);
	each[V].PB(v.size()-1);
}
int n,m,a[200],b[200],gl[200+10],inq[200+10];
bool bfs(int s){
	rb(i,0,2*n+1) gl[i]=INF,inq[i]=0;
	queue<int> q;
	gl[0]=0;
	inq[0]=1;
	q.push(s);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(auto it:each[now]){
			int to,c;
			to=v[it].t;
			c=v[it].c;
//			cout<<now<<" "<<to<<" "<<c<<endl;
			if(!inq[to]&&c){
				q.push(to);
				inq[to]=1;
				gl[to]=gl[now]+1;
			}
		}
	}
	return gl[2*n+1]==INF;
}
int dfs(int now,int mini){
//	cout<<now<<endl;
	int tmp_flow=0;
	if(now==n+n+1){
		return mini;
	}
	else{
		for(auto it:each[now]){
			int to,c;
			to=v[it].t;
			c=v[it].c;
			if(c&&gl[to]==gl[now]+1){
				if(tmp_flow=dfs(to,min(mini,c))){
					v[it].c-=tmp_flow;
					v[it^1].c+=tmp_flow;
					return tmp_flow;
				}
			}
		}
	}
	return 0;
}
int Dinic(){
	int max_flow=0;
	while(!bfs(0)){
		int tmp;
		while(tmp=dfs(0,INF)) {
//			cout<<tmp<<"!\n";
			max_flow+=tmp;
		}
//		cout<<"\n";
	}
	return max_flow;
}
int go_to[202][202];
int main(){
	cin>>n>>m;
	int s1,s2;
	s1=s2=0;
	rb(i,1,n) cin>>a[i],s1+=a[i];
	rb(i,1,n) cin>>b[i],s2+=b[i];
	if(s1!=s2){
		cout<<"NO"<<endl;
		return 0;
	}
	rb(i,1,m){
		int u,v,c=INF;
		cin>>u>>v;
		make_edge(u,v+n,c);
		make_edge(v,u+n,c);
	}
	rb(i,1,n){
		make_edge(0,i,a[i]);
		make_edge(i+n,2*n+1,b[i]);
		make_edge(i,i+n,INF);
	}
	int MAX_FLOW=Dinic();
	if(MAX_FLOW==s1){
		cout<<"YES"<<endl;
	for(int i=1;i<v.size();i+=2){
		int f,t,c;
		f=v[i].f;
		t=v[i].t;
		c=v[i].c;
		f-=n;
		if(t<=n&&t>=1&&f<=n&f>=1)
		go_to[t][f]=c;
	}
	rb(i,1,n)
		rb(j,1,n){
			cout<<go_to[i][j];
			cout<<(j==n? '\n':' ');
		}
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}