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
#define FREO freopen("check.out","r",stdin)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,m;
map<mp,int> have;
set<int> save;
int in_it[100000+10]; 
int res=0;
queue<int> q; 
void dfs(int now){
	set<int> :: IT ite=save.begin();
	for(;ite!=save.end();)	
	if(!have[II(now,*ite)])
	{
		have.erase(II(now,*ite));
		int num=*ite;
		in_it[num]=0;
		ite++;
		save.erase(num);
		q.push(num);
	}
	else ite++;
}
int main(){
//	FREO;
	cin>>n>>m;
	rb(i,1,m){
		int ui,vi;
		scanf("%d %d",&ui,&vi);
		have[II(ui,vi)]=have[II(vi,ui)]=1;
	}
	rb(i,1,n){
		save.insert(i);
		in_it[i]=1;
	}
	rb(i,1,n)
		if(in_it[i])
			{
				res++;
				in_it[i]=0;
//				cout<<i<<endl;
				save.erase(i);
				dfs(i);
				while(!q.empty()){
					dfs(q.front());
					q.pop();
				}
			}
//	cout<<save.size()<<endl;
	cout<<res-1<<endl; 
	return 0;
}