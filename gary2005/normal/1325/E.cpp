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
int n;
int a[100000+20],depth[100000+1000000+20];
bool used[1000000+100000+20];
vector<int> each[1000000+20+100000];
int res=INF;
void dfs(int now,int deep){
	depth[now]=deep;
	used[now]=1;
	for(auto it:each[now]){
		if(!used[it]){
			dfs(it,deep+1);
		} 
	}
}
int  f[1000000+20+100000];
bool prim[1000000+20];
int main(){
	fastio;
	cin>>n;
	prim[2]=0;
	rb(i,2,1000000){
		if(prim[i]==0){
			for(int j=i*2;j<=1000000;j+=i){
				prim[j]=1;
			}
		}
	}
	vector<int> ps;
	for(int i=1;i*i<=1000000;i++){
		ps.PB(i*i);
	}
	rb(i,1,n){
		cin>>a[i];
		rl(j,1000,1){
			if(a[i]%ps[j-1]==0){
				a[i]/=ps[j-1];
			}
		}
		if(a[i]==1){
			cout<<1<<endl;
			return 0;
		}
		if(f[a[i]]){
			res=2;
		}
		f[a[i]]=1;
		vector<int> pr;
		if(prim[a[i]]==0){
			pr.PB(1);
			pr.PB(a[i]);
		} 
		else
		for(int k=2;k*k<=a[i];k++){
			if(a[i]%k==0)
			if(!prim[k]){
				pr.PB(k);
				pr.PB(a[i]/k);
			}
		}
		each[pr[0]].PB(i+1000000);
		each[pr[1]].PB(i+1000000);
		each[i+1000000].PB(pr[0]);
		each[i+1000000].PB(pr[1]);
	}
	if(res==2){
		cout<<2<<endl;
		return 0;
	}
	rb(i,1,1000){
		memset(used,0,sizeof(used));
		queue<int> q;
		q.push(i);
		depth[i]=1;
		used[i]=1;
//		cout<<i<<endl;
		while(!q.empty()){
			int now=q.front();
			q.pop();
			int cnt=0;
			for(auto it:each[now]){
				if(!used[it]){
					used[it]=1;
					q.push(it);
					depth[it]=depth[now]+1;	
				}
				else{
					if(depth[it]==depth[now]-1){
						cnt++;
					}
				}
			}
			if(cnt>=2){
				res=min(res,depth[now]-1); 
			} 
		}
	}
	if(res==INF){
		res=-1;
		cout<<res<<endl;
	} 
	else{
		cout<<res<<endl;
	} 
	return 0;
}