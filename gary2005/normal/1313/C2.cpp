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
int m[500000+1];
LL tt[500000+1][2];
int main(){
	fastio;
	int n;
	cin>>n;
	rb(i,1,n){
		cin>>m[i];
	}
	LL res=0;
	stack<mp> q;
	rb(i,1,n){
		tt[i][0]=tt[i-1][0];
		mp pp=II(m[i],1);
		while(!q.empty()&&q.top().FIR>=m[i]){
			pp.SEC+=q.top().SEC;
			tt[i][0]-=(LL)(q.top().FIR)*q.top().SEC;
			q.pop();
		}
		tt[i][0]+=(LL)(pp.FIR)*pp.SEC;
		q.push(pp);
	}
	while(!q.empty())
	q.pop();
	rl(i,n,1){
		tt[i][1]=tt[i+1][1];
		 mp pp=II(m[i],1);
		while(!q.empty()&&q.top().FIR>=m[i]){
			pp.SEC+=q.top().SEC;
			tt[i][1]-=(LL)(q.top().FIR)*q.top().SEC;
			q.pop();
		}
		tt[i][1]+=(LL)(pp.FIR)*pp.SEC;
		q.push(pp);
	}
	rb(i,1,n){
		res=max(res,tt[i][0]+tt[i][1]-m[i]);
	}
//	cout<<res<<endl;
	rb(i,1,n){
		if(tt[i][0]+tt[i][1]-m[i]==res){
//			cout<<i<<endl;
		int las;
			las=m[i];
			for(int j=i-1;j>=1;j--){
			las=min(las,m[j]);
			m[j]=las;
			}
			las=m[i];
			for(int j=i+1;j<=n;j++){
			las=min(las,m[j]);
			m[j]=las;
			}
			rb(i,1,n){
				cout<<m[i]<<" ";
			}
			return 0;
		}
	}
	return 0;
}