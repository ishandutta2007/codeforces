/*
AuThOr Gwj
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
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXV = 2e6;
int V;// 
vector<int> g[MAXV+10],rg[MAXV+10],v;
bool used[MAXV+10];
int cmp[MAXV+10];//
void addedge(int from,int to){
	g[from].PB(to);
	rg[to].PB(from);
} 
void dfs(int now){
	used[now]=1;
	for(auto it:g[now]){
		if(!used[it]) dfs(it);
	}
	v.PB(now);
}
void rdfs(int now,int k){
	used[now]=1;
	cmp[now]=k;
	for(auto it:rg[now]){
		if(!used[it]) rdfs(it,k);
	}
}
int t,T,n,m,cnt,l[100001],r[100001],teacher[100001][2];
int scc(){
	//scc 
	V=cnt;
	rb(i,1,V)
		if(!used[i]) dfs(i);
	memset(used,0,sizeof(used));
	int k=0;
	reverse(ALL(v));
	for(auto it:v){
		if(!used[it]){
			rdfs(it,++k);
		}
	}
	return k;
}
map<int,int> :: IT ite;
map<int,int> M[2];
void newnode(int col,int x){
	if(M[col][x]) return;
	M[col][x]=++cnt;
}
int res[100001];
int id[100001]; 
bool Cmp(int X,int Y){
	return r[X]<r[Y];
}
int z[100001][2];
bool need[100001];
int main(){
	fastio;
	cin>>t>>T>>n>>m;
	rb(i,1,n){
		
		cin>>l[i]>>r[i],r[i]=min(r[i],T),teacher[i][0]=++cnt,teacher[i][1]=++cnt;

	}
	rb(i,1,n)
		id[i]=i;
	sort(id+1,id+1+n,Cmp);
	rb(i,1,n){
		int l_bound,r_bound;
		l_bound=1,r_bound=i;
		if(r[id[1]]>=l[id[i]]){
			continue;
		}
		else{
			while(l_bound+1<r_bound){
				int mid=(l_bound+r_bound)>>1;
				if(r[id[mid]]<l[id[i]]){
					l_bound=mid;
				}
				else{
					r_bound=mid;
				}
			}
			need[l_bound]=1;
		}
	}
	int Last=0;
	int TMPTMP=-INF;
	rb(i,1,n){
		TMPTMP=max(TMPTMP,l[i]);
	}//
//	if(n==100000)
//	cout<<r[id[1]]<<" "<<TMPTMP<<endl;
	rb(i,1,n){
		if(need[i]) {
		z[i][0]=++cnt;
		z[i][1]=++cnt;
		if(Last){
		addedge(z[Last][1],z[i][1]);
		addedge(z[Last][0],z[i][0]);
		addedge(z[i][1],z[Last][1]);
		addedge(z[i][0],z[Last][0]);
		}
		rb(j,Last+1,i){
			addedge(teacher[id[j]][1],z[i][1]);
			addedge(z[i][1],teacher[id[j]][1]);
			addedge(teacher[id[j]][0],z[i][0]);
			addedge(z[i][0],teacher[id[j]][0]);
		}
		Last=i;
		}
		int l_bound,r_bound;
		l_bound=1,r_bound=i;
		if(r[id[1]]>=l[id[i]]){
			continue;
		}
		else{
			while(l_bound+1<r_bound){
				int mid=(l_bound+r_bound)>>1;
				if(r[id[mid]]<l[id[i]]){
					l_bound=mid;
				}
				else{
					r_bound=mid;
				}
			}
			addedge(teacher[id[i]][1],z[l_bound][0]);
			addedge(z[l_bound][0],teacher[id[i]][1]);
			addedge(teacher[id[i]][0],z[l_bound][1]);
			addedge(z[l_bound][1],teacher[id[i]][0]);
			
		}
	}
	rb(i,1,m)
	{
		int X,Y;
		cin>>X>>Y;
		addedge(teacher[X][0],teacher[Y][1]);
		addedge(teacher[X][1],teacher[Y][0]);
		swap(X,Y);
		addedge(teacher[X][0],teacher[Y][1]);
		addedge(teacher[X][1],teacher[Y][0]);
	}
	rb(i,1,n){
		int L,R;
		L=l[i];
		R=r[i];
		if(L>T){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
		if(L<=R) {
		newnode(0,L);
		newnode(1,R+1);
		newnode(1,L);
		newnode(0,R+1);
		addedge(teacher[i][0],M[0][L]);
		addedge(teacher[i][0],M[1][R+1]);
		addedge(M[1][L],teacher[i][1]);
		addedge(M[0][R+1],teacher[i][1]);
		}
		L=max(0,t-r[i]);
		R=T-l[i];
		if(L<=R){//
//		cout<<t-r[i]<<" "<<T-l[i]<<endl;
		newnode(0,L);
		newnode(1,R+1);
		newnode(1,L);
		newnode(0,R+1);
		addedge(teacher[i][1],M[0][L]);
		addedge(teacher[i][1],M[1][R+1]);
		addedge(M[1][L],teacher[i][0]);
		addedge(M[0][R+1],teacher[i][0]);
		}
	}
//	newnode(1,0);
//	newnode(0,0);
//	addedge(M[1][0],M[0][0]);
	int prev=-INF;
	for(ite=M[0].begin();ite!=M[0].end();ite++){
		int now=ite->FIR;
		if(prev!=-INF){
		addedge(M[1][prev],M[1][now]);
		addedge(M[0][now],M[0][prev]);
//		addedge(M[0][now])
		}
		prev=now;
	}
	scc();
	rb(i,1,n){
		if(cmp[teacher[i][0]]==cmp[teacher[i][1]]){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
	}
	for(ite=M[1].begin();ite!=M[1].end();ite++){
		if(cmp[ite->SEC]==cmp[M[0][ite->FIR]]){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
	}
	pair<int,int> arr;
	arr=II(-INF,INF);
	rb(i,1,n){
//		cout<<cmp[teacher[i][0]]<<" "<<cmp[teacher[i][1]]<<endl;
		if(cmp[teacher[i][0]]>cmp[teacher[i][1]]){
			res[i]=1;
		}
		else{
			res[i]=2;
		}
	}
	for(ite=M[1].begin();ite!=M[1].end();ite++){
		if(cmp[ite->SEC]<cmp[M[0][ite->FIR]]){
			arr.FIR=max(arr.FIR,ite->FIR); 
		}
		else{
			arr.SEC=min(arr.SEC,ite->FIR-1);
		}
	}
	cout<<"POSSIBLE\n";
	int cnt1,cnt2;
	cnt1=arr.FIR;
	arr=II(-INF,INF);
	rb(i,1,n){
		if(res[i]==2){
			arr.FIR=max(arr.FIR,l[i]);
			arr.SEC=min(arr.SEC,r[i]);
		}
	}
	if(arr.FIR==-INF){
		arr.FIR=0;
	}
//	debug_pair(arr);	

	cnt2=max(t-cnt1,arr.FIR);
	cout<<cnt1<<" "<<cnt2<<endl;
	rb(i,1,n) cout<<res[i];
	return 0;
}
/*
300064 1334309
3 0
306608 352641
457190 662663
303334 323725

10 20
2 0
3 6
4 9
*/