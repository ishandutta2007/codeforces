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
const LL INF=1e15;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
bool maze[1000000+2];
int las_empty[1000000+2],n,m,k; 
int main(){
	fastio;
	cin>>n>>m>>k;
	n++;
	rb(i,1,m){
		int si;
		cin>>si;
		si++;
		maze[si]=1;
	} 
	LL res=INF;
	rb(i,1,n){
		if(maze[i]==0){
			las_empty[i]=i;
		}
		else{
			las_empty[i]=las_empty[i-1];
		}
	}
	if(maze[1]==1){
		cout<<-1<<endl;
		return 0;
	}
	int st=1;
	rb(i,1,n){
		if(maze[i]==0) break;
		st++;
	}
	rb(i,1,k){
		LL tmp=0;
		int COST;
		cin>>COST;
		for(int j=st;j<n;j+=i){
			if(maze[j]==1){
				j=las_empty[j];
				if(j+i<n)
				if(las_empty[j+i]==j){
					tmp=INF;
					break;
				}
			}
//			cout<<j<<endl;
			tmp+=COST;
		}
//		cout<<tmp<<endl;
		res=min(res,tmp);
	}
	cout<<(res==INF? -1:res)<<endl;
	return 0;
}