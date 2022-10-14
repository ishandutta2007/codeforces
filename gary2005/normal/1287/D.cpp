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
int ans[2000+10],p[2000+10],c[2000+10];
queue<int> aa;
vector<int> each[2000+10]; 
int dfs_check(int now){
	int size=1;
	for(auto it:each[now]){
		size+=dfs_check(it);
	}
	if(size-1<c[now]){
		cout<<"NO";
		exit(0);
	}
	return size;
}
void dfs(int now){
	for(auto it:each[now]){
		dfs(it);
	}
	queue<int> tmp;
	rb(i,1,c[now])
	{
		tmp.push(aa.front());
		aa.pop();
	}
	tmp.push(now);
	while(!aa.empty()){
		tmp.push(aa.front());
		aa.pop();
	}
	aa=tmp;
}
int main(){
	int n;
	cin>>n;
	int root;
	rb(i,1,n)
		{
			cin>>p[i]>>c[i];
			if(p[i]==0) root=i;
			each[p[i]].PB(i);
		}
	dfs_check(root);
	dfs(root);
	int tot=0;
	while(!aa.empty()){
		++tot;
		ans[aa.front()]=tot;
		aa.pop();
	}
	cout<<"YES"<<endl;
	 rb(i,1,n){
	 	cout<<ans[i]<<" ";
	 }
	return 0;
}