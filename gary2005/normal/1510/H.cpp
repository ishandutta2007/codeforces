/*
QwQ 
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
#define record(a,b,c,d) II(II(seg[a].FIR,record[a][b][c][d].FIR),II(record[a][b][c][d].SEC,seg[a].SEC))
using namespace std;
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=2e3+1;
int n,id[MAXN],siz[MAXN],depth[MAXN];
mp ans[MAXN];
bool used[MAXN];
mp seg[MAXN];
vector<int> roots,g[MAXN];
bool cmp(int A,int B){
	return seg[A].FIR<seg[B].FIR;
}
bool cmp2(int A,int B){
	return seg[A].SEC-seg[A].FIR<seg[B].SEC-seg[B].FIR;
}
bool cmp3(mp A,mp B){
	return A.SEC-A.FIR<B.SEC-B.FIR;
}
void build_tree(){
	rb(i,1,n) id[i]=i;
	sort(id+1,id+1+n,cmp);
	vector<int> tmp;
	rb(i_,1,n){
		int i=id[i_],_=-INF;
		rb(j_,i_+1,n){
			int j=id[j_];
			if(seg[j].SEC>seg[i].SEC) break;
			if(seg[j].FIR>_){
				g[i].PB(j); 
				tmp.PB(j);
				_=seg[j].SEC;
			}
		}
	}
	sort(ALL(tmp));
	rb(i,1,n){
		auto ite=lower_bound(ALL(tmp),i);
		if(ite==tmp.end()||*ite!=i) roots.PB(i);
	}
}
vector<mp> rest;
void recover(vector<mp> v){
	sort(ALL(v),cmp3);
	sort(id+1,id+1+n,cmp2);
	rb(i_,1,n){
		int i=id[i_];
		rep(j,n){
			if(!used[j]&&v[j].SEC<=seg[i].SEC&&v[j].FIR>=seg[i].FIR){
				ans[i]=v[j];
				used[j]=1;
				break;
			}
		}
	}
	rb(i,1,n) printf("%d %d\n",ans[i].FIR,ans[i].SEC);
}
namespace DP{
	int dp[MAXN][MAXN][2][2];
	int f[MAXN][MAXN][2][2];
	int fi[MAXN][MAXN][2][2];
	mp record[MAXN][MAXN][2][2];
	struct D{
		short j;
		bool a,b;
		D(){}
		D(int B,bool C,bool Z){
			j=B,a=C,b=Z;
		}
	};
	pair<D,D> pre[MAXN][MAXN][2][2];
	mp merge(mp A,mp B){
		return II(A.FIR,B.SEC); 
	}
	void dfs(int now){
		siz[now]=1;
		for(auto it:g[now]) depth[it]=depth[now]+1,dfs(it),siz[now]+=siz[it];
	}
	void init(){
		rb(i,1,n) rb(j,0,n) rep(a,2) rep(b,2) record[i][j][a][b].FIR=seg[i].FIR,record[i][j][a][b].SEC=seg[i].SEC;
		memset(f,-63,sizeof(f));
		memset(dp,-63,sizeof(dp));
		for(auto it:roots) dfs(it);
		rb(i,1,n) check_min(siz[i],depth[i]);
	}
	void trans(int now){
		if(g[now].empty()){
			dp[now][0][0][0]=seg[now].SEC-seg[now].FIR;
			return;
		}
		int RP=seg[now].FIR;
		vector<int> c;
		sort(ALL(g[now]),cmp);
		for(auto it:g[now]) trans(it),c.PB(seg[it].FIR-RP),RP=seg[it].SEC;
		c.PB(seg[now].SEC-RP);
		rb(i,1,g[now].size()) memset(f[i],-63,sizeof(f[i]));
		f[0][0][0][0]=0;
		f[0][1][1][1]=c[0];
		int tot=1;
		rb(i,1,g[now].size()){
			rb(j,0,tot){
				rep(a1,2){
					rep(a2,2){
						if(f[i-1][j][a1][a2]>=0){
							rb(k,0,siz[g[now][i-1]]){
								rep(a3,2){
									rep(a4,2){
										if(dp[g[now][i-1]][k][a3][a4]>=0){
											int val=f[i-1][j][a1][a2]+dp[g[now][i-1]][k][a3][a4];
											for(int fk=0;fk<=(a2&&a3);fk++){
												check_max(f[i][j+k-fk][a1][0],val);
												check_max(f[i][j+k+1-fk][a1][1],val+c[i]);
												if(a4)
												check_max(f[i][j+k-fk][a1][1],val+c[i]);
											}
										}
									}
								}
							}
						}
					}
				}
			}
			tot+=siz[g[now][i-1]];
		}
		rb(i,0,tot) rep(a,2) rep(b,2) dp[now][i][a][b]=f[g[now].size()][i+1][a][b];
		rb(i,0,1) rep(a,2) rep(b,2){
			if(i==0){
				if(a||b){
					check_max(dp[now][i][0][0],dp[now][i][a][b]);
					dp[now][i][a][b]=-INF;
				}
			}
			else{
				if(a&&b){
					rep(na,2){
						rep(nb,2){
							if(!(na&&nb)){
								check_max(dp[now][i][na][nb],dp[now][i][a][b]);
							}
						}
					}
					dp[now][i][a][b]=-INF;
				}
			}
		}
	}
	void work(){
		LL answer=0;
		for(auto it:roots) trans(it),answer+=dp[it][0][0][0];
		printf("%lld\n",answer);
	}
	void get(int now){
		if(g[now].empty()){
			return;	
		} 
		for(auto it:g[now]) get(it);
		vector<int> c;
		int RP=seg[now].FIR;
		for(auto it:g[now]) c.PB(seg[it].FIR-RP),RP=seg[it].SEC;
		c.PB(seg[now].SEC-RP);
		rb(i,1,g[now].size()) memset(f[i],-63,sizeof(f[i]));
		f[0][0][0][0]=0;
		f[0][1][1][1]=c[0];
		int tot=1;
		rb(i,1,g[now].size()){
			rb(j,0,tot){
				rep(a1,2){
					rep(a2,2){
						if(f[i-1][j][a1][a2]>=0){
							rb(k,0,siz[g[now][i-1]]){
								rep(a3,2){
									rep(a4,2){
										if(dp[g[now][i-1]][k][a3][a4]>=0){
											for(int fk=0;fk<=(a2&&a3);fk++){
											int val=f[i-1][j][a1][a2]+dp[g[now][i-1]][k][a3][a4];
												if(val>f[i][j+k-fk][a1][0]){
													if(i==1){
														fi[i][j+k-fk][a1][0]=record(g[now][i-1],k,a3,a4).FIR.SEC-record(g[now][i-1],k,a3,a4).FIR.FIR;
													}
													else fi[i][j+k-fk][a1][0]=fi[i-1][j][a1][a2];
													f[i][j+k-fk][a1][0]=val;
													pre[i][j+k-fk][a1][0]=II(D(j,a1,a2),D(k,a3,a4));
												}
												val+=c[i];
												if(val>f[i][j+k+1-fk][a1][1]){
													if(i==1){
														fi[i][j+k+1-fk][a1][1]=record(g[now][i-1],k,a3,a4).FIR.SEC-record(g[now][i-1],k,a3,a4).FIR.FIR;
													}
													else fi[i][j+k+1-fk][a1][1]=fi[i-1][j][a1][a2];
													f[i][j+k+1-fk][a1][1]=val;
													pre[i][j+k+1-fk][a1][1]=II(D(j,a1,a2),D(k,a3,a4));
												}
												if(a4){
													if(val>f[i][j+k-fk][a1][1]){
														if(i==1){
															fi[i][j+k-fk][a1][1]=record(g[now][i-1],k,a3,a4).FIR.SEC-record(g[now][i-1],k,a3,a4).FIR.FIR;
														}
														else fi[i][j+k-fk][a1][1]=fi[i-1][j][a1][a2];
														f[i][j+k-fk][a1][1]=val;
														pre[i][j+k-fk][a1][1]=II(D(j,a1,a2),D(k,a3,a4));
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			tot+=siz[g[now][i-1]];
		}
		rb(i,0,tot){
			rep(a,2){
				rep(b,2){
					if(dp[now][i][a][b]>0){
						record[now][i][a][b].FIR=seg[now].FIR;
						record[now][i][a][b].SEC=seg[now].SEC;
						if(i==0);
						else
						if(i==1){
							if(dp[now][i][a][b]==f[g[now].size()][2][a][b]){
								record[now][i][a][b].FIR=seg[now].FIR+c[0]+fi[g[now].size()][i+1][a][b];
								D id=pre[g[now].size()][i+1][a][b].SEC;
								mp Tmp=record(g[now].back(),id.j,id.a,id.b).SEC;
								record[now][i][a][b].SEC=seg[now].SEC-c.back()-(Tmp.SEC-Tmp.FIR);
							}
							else{
								if(dp[now][i][a][b]==f[g[now].size()][2][1][1]){
									record[now][i][a][b].FIR=seg[now].FIR+c[0]+fi[g[now].size()][i+1][1][1];
									D id=pre[g[now].size()][i+1][1][1].SEC;
									mp Tmp=record(g[now].back(),id.j,id.a,id.b).SEC;
									record[now][i][a][b].SEC=seg[now].SEC-c.back()-(Tmp.SEC-Tmp.FIR);
								}
								else{
									assert(0);	
								}
							}
						}
						else{
							record[now][i][a][b].FIR=seg[now].FIR+c[0]+fi[g[now].size()][i+1][a][b];
							D id=pre[g[now].size()][i+1][a][b].SEC;
							mp Tmp=record(g[now].back(),id.j,id.a,id.b).SEC;
							record[now][i][a][b].SEC=seg[now].SEC-c.back()-(Tmp.SEC-Tmp.FIR);
						}
						if(!a) record[now][i][a][b].FIR=seg[now].FIR;
						if(!b) record[now][i][a][b].SEC=seg[now].SEC;
					}
				}
			}
		}
	}
	void print(int now,int K,int needa,int needb){
		if(g[now].empty()){
			rest.PB(seg[now]);
			return ;
		}
		vector<int> c;
		int Pre=seg[now].FIR;
		for(auto it:g[now]) c.PB(seg[it].FIR-Pre),Pre=seg[it].SEC;
		c.PB(seg[now].SEC-Pre);
		rb(i,1,g[now].size()) memset(f[i],-63,sizeof(f[i]));
		f[0][0][0][0]=0;
		f[0][1][1][1]=c[0];
		int tot=1;
		rb(i,1,g[now].size()){
			rb(j,0,tot){
				rep(a1,2){
					rep(a2,2){
						if(f[i-1][j][a1][a2]>=0){
							rb(k,0,siz[g[now][i-1]]){
								rep(a3,2){
									rep(a4,2){
										if(dp[g[now][i-1]][k][a3][a4]>=0){
											for(int fk=0;fk<=(a2&&a3);fk++){
												int val=f[i-1][j][a1][a2]+dp[g[now][i-1]][k][a3][a4];
												if(val>f[i][j+k-fk][a1][0]){
													if(i==1){
														fi[i][j+k-fk][a1][0]=record(g[now][i-1],k,a3,a4).FIR.SEC-record(g[now][i-1],k,a3,a4).FIR.FIR;
													}
													else fi[i][j+k-fk][a1][0]=fi[i-1][j][a1][a2];
													f[i][j+k-fk][a1][0]=val;
													pre[i][j+k-fk][a1][0]=II(D(j,a1,a2),D(k,a3,a4));
												}
												val+=c[i];
												if(val>f[i][j+k+1-fk][a1][1]){
													if(i==1){
														fi[i][j+k+1-fk][a1][1]=record(g[now][i-1],k,a3,a4).FIR.SEC-record(g[now][i-1],k,a3,a4).FIR.FIR;
													}
													else fi[i][j+k+1-fk][a1][1]=fi[i-1][j][a1][a2];
													f[i][j+k+1-fk][a1][1]=val;
													pre[i][j+k+1-fk][a1][1]=II(D(j,a1,a2),D(k,a3,a4));
												}
												if(a4){
													if(val>f[i][j+k-fk][a1][1]){
														if(i==1){
															fi[i][j+k-fk][a1][1]=record(g[now][i-1],k,a3,a4).FIR.SEC-record(g[now][i-1],k,a3,a4).FIR.FIR;
														}
														else fi[i][j+k-fk][a1][1]=fi[i-1][j][a1][a2];
														f[i][j+k-fk][a1][1]=val;
														pre[i][j+k-fk][a1][1]=II(D(j,a1,a2),D(k,a3,a4));
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			tot+=siz[g[now][i-1]];
		}
		bool GL,GR;
		GL=GR=0;
		if(dp[now][K][needa][needb]==f[g[now].size()][K+1][needa][needb]);
		else{
			assert(K<=1);
			if(K==0){
				if(dp[now][K][needa][needb]==f[g[now].size()][K+1][0][1]){
					needb=1;
					GR=1;
				}
				else{
					needa=1;
					GL=1;
				}
			}
			else{
				if(!needa) GL=1;
				else GR=1;
				needa=needb=1;
			}
		}
		++K;
		vector<mp> V;
		vector<pair<mp,mp> > Nex;
		if(needb) V.PB(II(seg[now].SEC-c.back(),seg[now].SEC));
		rl(i,g[now].size(),1){
			pair<D,D> wtf=pre[i][K][needa][needb];
			Nex.PB(II(II(g[now][i-1],wtf.SEC.j),II(wtf.SEC.a,wtf.SEC.b)));
			if(wtf.SEC.b) V.PB(record(g[now][i-1],wtf.SEC.j,wtf.SEC.a,wtf.SEC.b).SEC);
			if(wtf.SEC.a) V.PB(record(g[now][i-1],wtf.SEC.j,wtf.SEC.a,wtf.SEC.b).FIR);
			if(wtf.FIR.b) V.PB(II(seg[g[now][i-1]].FIR-c[i-1],seg[g[now][i-1]].FIR));
			K=wtf.FIR.j;
			needa=wtf.FIR.a;
			needb=wtf.FIR.b;
		}
		reverse(ALL(V));
		vector<mp> tmp;
		for(auto it:V){
			if(tmp.empty()||tmp.back().SEC!=it.FIR) tmp.PB(it);
			else tmp[tmp.size()-1]=merge(tmp[tmp.size()-1],it);
		}
		V=tmp;
		rep(i,V.size()){
			if(V[i].FIR!=seg[now].FIR&&V[i].SEC!=seg[now].SEC) rest.PB(V[i]);
		}
		if(GL) rest.PB(V[0]),assert(V[0].FIR==seg[now].FIR);
		if(GR) rest.PB(V.back()),assert(V.back().SEC==seg[now].SEC);
		for(auto it:Nex) print(it.FIR.FIR,it.FIR.SEC,it.SEC.FIR,it.SEC.SEC);
	}
	void path(){
		for(auto it:roots) get(it);
		for(auto it:roots) print(it,0,0,0);
	}
};
int main(){
//	cout<<(sizeof(DP::pre)+sizeof(DP::record)+sizeof(DP::f)+sizeof(DP::fi)+sizeof(DP::dp))/1024/1024<<endl;
	n=read();
	rb(i,1,n) seg[i].FIR=read(),seg[i].SEC=read();
	build_tree();
	DP:: init(); 
	DP:: work();
	DP:: path();
	assert(rest.size()==n);
	recover(rest);
	return 0;
}