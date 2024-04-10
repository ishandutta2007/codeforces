#include<bits/stdc++.h>
using namespace std;
#define N 606
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,vis[N],dep[N],f[N];
//int qcnt;
namespace Grader{
	int g[N][N];
	void adde(int u,int v){g[u][v]=g[v][u]=1;}
	int Ask(const vector<int> &v){
		int cnt=0;
		for(auto x:v){
			for(auto y:v){
				cnt+=g[x][y];
			}
		}
		return cnt>>1;
	} 
}
int query(const vector<int> &a){
	if(a.size()==1)return 0;
//	++qcnt;
	printf("? %d\n",(int)a.size());
	for(auto x:a)printf("%d ",x);
	printf("\n");
	fflush(stdout);
//	return Grader::Ask(a);
	return read();
}
queue<int> q;
void Solve(int u,vector<int> &v){
	if(v.empty())return;
	int x=query(v);
	v.push_back(u);
	int y=query(v);
	v.pop_back();
	if(x==y)return;
	if(v.size()==1){
		f[v[0]]=u;
		dep[v[0]]=dep[u]+1;
		vis[v[0]]=1;
		q.push(v[0]);
		return;
	}
	vector<int> A,B;
	for(int i=0;i<(int)v.size();++i){
		if(i&1)B.push_back(v[i]);
		else A.push_back(v[i]);
	}
	Solve(u,A);
	Solve(u,B);
}
int Find(int u,vector<int> &v){
	if(v.empty())return -1;
	int x=query(v);
	v.push_back(u);
	int y=query(v);
	v.pop_back();
	if(x==y)return -1;
	if(v.size()==1){
		return v[0];
	}
	vector<int> A,B;
	for(int i=0;i<(int)v.size();++i){
		if(i&1)B.push_back(v[i]);
		else A.push_back(v[i]);
	}
	x=Find(u,A);
	if(~x)return x;
	return Find(u,B);
}
void Get(int x,int y){
	vector<int> A(1,x),B(1,y);
	while(f[x]^f[y]){
		if(dep[x]>=dep[y])A.push_back(x=f[x]);
		else B.push_back(y=f[y]);
	}
	if(x^y)A.push_back(f[x]);
	reverse(B.begin(),B.end());
	printf("N %d\n",(int)A.size()+(int)B.size());
	for(auto x:A)printf("%d ",x);
	for(auto x:B)printf("%d ",x);
}

int main(){
	n=read();
	
	if(n==1){
		printf("Y 1\n1\n");
		fflush(stdout);
		return 0;
	}
		
	/*
	int m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		Grader::adde(u,v);
	}
	*/
	
	vis[1]=dep[1]=1;
	q.push(1);
//	int p=0,las=0;
	while(!q.empty()){
		int i=q.front();
		q.pop();
		vector<int> all;
		for(int u=2;u<=n;++u)if(!vis[u])all.push_back(u);
		Solve(i,all);
	//	cerr<<(++p)<<" "<<qcnt<<" "<<qcnt-las<<endl;
	//	las=qcnt;
	}
	vector<int> even,odd;
	for(int i=1;i<=n;++i){
		if(dep[i]&1)odd.push_back(i);
		else even.push_back(i);
	}
	vector<int> zyk;
	bool ok=true;
	if(query(odd)){
		ok=false;zyk=odd;
	}
	else if(query(even)){
		ok=false;zyk=even;
	}
	if(ok){
		printf("Y %d\n",(int)odd.size());
		for(auto x:odd)printf("%d ",x);
	}
	else{
		for(auto u:zyk){
			vector<int> hzk=zyk;
			hzk.erase(lower_bound(hzk.begin(),hzk.end(),u));
			int v=Find(u,hzk);
			if(!~v)continue;
			Get(u,v);
			break;
		}
	}
	printf("\n");
	fflush(stdout);
//	cerr<<qcnt<<endl;
	return 0;
}