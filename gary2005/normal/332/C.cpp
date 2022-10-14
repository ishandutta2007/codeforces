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
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=100000+20;
int n;
pair<mp,int> event[MAXN];
bool cmp(pair<mp,int> A,pair<mp,int> B){
	return A>B; 
}
bool cmp2(pair<mp,int> A,pair<mp,int> B){
	if(A.FIR.FIR!=B.FIR.FIR){
		return A>B;
	}
	else{
		if(A.FIR.SEC!=B.FIR.SEC)
			return A.FIR.SEC>B.FIR.SEC;
	}
	return A.SEC<B.SEC; 
}
vector<pair<mp,int> > tim[MAXN];
bool used[MAXN];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	fastio;
	R(n);
	int p,k;
	R2(p,k); 
	rb(i,1,n)
	{
		event[i].SEC=i;
		R2(event[i].FIR.SEC,event[i].FIR.FIR);/*FIR-SEC : */
	}
	sort(event+1,event+1+n,cmp);
	int cntType=0;
	rb(i,1,n){
		if(i==1||event[i].FIR.FIR!=event[i-1].FIR.FIR){
			cntType++;
		}
		tim[cntType].PB(II(II(event[i].FIR.SEC,event[i].FIR.FIR),event[i].SEC));
//		cout<<event[i].FIR.FIR<<" "<<event[i].FIR.SEC<<" "<<event[i].SEC<<endl;
	} 
	int jump=p-k;
	vector<pair<mp,int> > q;
	vector<mp> res; 
	rl(i,cntType,1){
		if(tim[i].size()<=jump){
			rep(j,tim[i].size()){
				res.PB(II(i,tim[i][j].SEC));
			}
			jump-=tim[i].size();
			continue;
		}
		else{
			if(jump){
				rep(j,jump)
				{
					res.PB(II(i,tim[i][j].SEC));
				}
				rb(j,jump,tim[i].size()-1){
					q.PB(tim[i][j]);
				}
				jump=0;
				continue; 
			} 
			else{
				rep(j,tim[i].size()){
					q.PB(tim[i][j]);
				}
			}
		}
	}
	sort(ALL(q),cmp2);
	rb(i,1,k){
		used[q[i-1].SEC]=1;
		cout<<(q[i-1].SEC)<<" ";
	} 
	rl(i,cntType,1){
		bool ok=0;
		rep(j,tim[i].size()){
			if(used[tim[i][j].SEC]){
				ok=1;
			}
		}
		if(ok){
			rb(j,0,tim[i].size()-1){
				if(tim[i][j].FIR.FIR!=tim[i][0].FIR.FIR) break;
				if(!used[tim[i][j].SEC])
				res.PB(II(i,tim[i][j].SEC));
			}
			break;
		}
		else{
			rep(j,tim[i].size()){
				res.PB(II(i,tim[i][j].SEC));
			}
		}
	}
	sort(ALL(res));
	res.erase(unique(ALL(res)),res.end());
	assert(res.size()>=p-k);
	rb(i,1,p-k)
	{
		cout<<res[i-1].SEC<<" ";
	} 
	cout<<endl;
	return 0;
}
/*

5 3 2
5 6
5 8
1 3
4 3
4 11

5 3 3
10 18
18 17
10 20
20 18
20 18

*/