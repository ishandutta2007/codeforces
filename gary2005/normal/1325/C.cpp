/*
Please, Let Me Become Master 
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
vector<mp> each[100000+20];
int res[100000+20],used[100000+20];
int main(){
	fastio;
	int n;
	cin>>n;
	rb(i,2,n){
		int u,v;
		cin>>u>>v;
		each[u].PB(II(v,i));
		each[v].PB(II(u,i));
	}
	memset(res,-63,sizeof(res));
	int ok=1;
	rb(i,1,n){
		if(each[i].size()>2){
			int z=0;
			used[0]=used[1]=used[2]=1;
			for(auto it:each[i]){
				res[it.SEC]=z++;
				if(z==3) break;
			}
			break;
		}
	}
	int z=3;
	if(!used[0])
	z=0;
	rb(i,2,n){
		if(res[i]<0){
			cout<<z++<<endl;
		}
		else{
			cout<<res[i]<<endl;
		}
	}
	return 0;
}