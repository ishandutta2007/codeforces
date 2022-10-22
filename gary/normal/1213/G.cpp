//* AuThOr GaRyMr *//
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
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<mp > each[200000+10];
mp query[200000+10];LL ans[200000+10];
pair<mp,int> save[200000+10];
int Size[200000+10],flag[200000+10],boss[200000+10];
int n,m;
priority_queue<mp, vector<mp>, greater<mp> > Q;
int Find(int now){
	if(boss[now]==now) return now;
	return boss[now]=Find(boss[now]);
}
int main(){
	cin>>n>>m;
	rep(i,n) boss[i+1]=i+1;
	rep(i,n-1){
		int ui,vi,wi;
		cin>>ui>>vi>>wi;
		each[ui].PB({vi,wi}),each[vi].PB({ui,wi});
		Q.push({wi,i});
		save[i]={{ui,vi},wi};
	}
	rep(i,m) cin>>query[i].FIR,query[i].SEC=i+1;
	sort(query,query+m);
	LL res=0;
	rep(i,m){
		KEEP{
			if(Q.empty()) break;
			if(Q.top().FIR>query[i].FIR) break;
			mp now=Q.top();
			Q.pop();
			pair<mp,int> N;
			N=save[now.SEC];
			if(!flag[N.FIR.FIR]&&!flag[N.FIR.SEC]){
				flag[N.FIR.FIR]=flag[N.FIR.SEC]=1;
				boss[N.FIR.FIR]=N.FIR.SEC;
				Size[N.FIR.SEC]=2;
				res+=1;
			}
			else{
				if(!flag[N.FIR.FIR]){flag[N.FIR.FIR]=flag[N.FIR.SEC]=1;
					boss[N.FIR.FIR]=Find(boss[N.FIR.SEC]);
					Size[Find(boss[N.FIR.SEC])]++;
					res+=Size[Find(boss[N.FIR.SEC])]-1;
				}
				else{
					if(!flag[N.FIR.SEC]){flag[N.FIR.FIR]=flag[N.FIR.SEC]=1;
						boss[N.FIR.SEC]=Find(boss[N.FIR.FIR]);
						Size[Find(boss[N.FIR.FIR])]++;
						res+=Size[Find(boss[N.FIR.FIR])]-1;
					}
					else{
						if(Find(N.FIR.FIR)!=Find(N.FIR.SEC)){
							flag[N.FIR.FIR]=flag[N.FIR.SEC]=1;
							res-=((LL)(Size[Find(N.FIR.SEC)])*(LL)(Size[Find(N.FIR.SEC)]-1))/(LL)(2);
							res-=((LL)(Size[Find(N.FIR.FIR)])*(LL)(Size[Find(N.FIR.FIR)]-1))/(LL)(2);
							Size[Find(N.FIR.SEC)]+=Size[Find(N.FIR.FIR)];
							boss[Find(N.FIR.FIR)]=Find(N.FIR.SEC);	
							res+=((LL)(Size[Find(N.FIR.FIR)])*(LL)(Size[Find(N.FIR.FIR)]-1))/(LL)(2);
						}			
					}
				}
			}
		}
		ans[query[i].SEC]=res;
	}
	rep(i,m) cout<<ans[i+1]<<" ";cout<<endl;
	return 0;
}