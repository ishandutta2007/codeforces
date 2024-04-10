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
#define FREO freopen("check.out","w",stdout)
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
const int MAGIC=250;
int n,m;
vector<pair<int,mp> > v;
int fa[MAXN];
int root(int index)
{
	if(fa[index]==index) return index;
	return fa[index]=root(fa[index]);
}
int qs[MAXN][2],res[MAXN];
map<mp,int> M;
int main(){
	fastio;
	R2(n,m);
	rb(i,1,m)
	{
		int u,V,c;
		R2(u,V);
		R(c);
		v.PB(II(c,II(u,V)));
	}
	int Q;
	R(Q);
	rb(i,1,Q){
		R2(qs[i][0],qs[i][1]);
		if(qs[i][0]>qs[i][1]) swap(qs[i][0],qs[i][1]);
	}
	sort(ALL(v));
	rep(i,v.size()){
		int j=i;
		while(j!=v.size()-1&&v[j+1].FIR==v[j].FIR) j++;
		if(j-i+1>=MAGIC){
			rb(k,1,n){
				fa[k]=k;
			}
			rb(k,i,j){
				fa[root(v[k].SEC.FIR)]=root(v[k].SEC.SEC);
			}
			rb(k,1,Q){
				if(root(qs[k][0])==root(qs[k][1])){
					res[k]++;	
				}
			}
		}
		else{
			vector<int> ve;
			rb(k,i,j){
				fa[v[k].SEC.FIR]=v[k].SEC.FIR;
				fa[v[k].SEC.SEC]=v[k].SEC.SEC;
				ve.PB(v[k].SEC.FIR);
				ve.PB(v[k].SEC.SEC);
			}
			sort(ALL(ve));
			ve.erase(unique(ALL(ve)),ve.end());
			rb(k,i,j){
				fa[root(v[k].SEC.FIR)]=root(v[k].SEC.SEC);
			}
			rep(I,ve.size()){
				rep(J,ve.size()){
					if(J>I){
						if(root(ve[I])==root(ve[J])){
//							cout<<M[II(ve[I],ve[J])]<<endl;
							M[II(ve[I],ve[J])]++;
						}
					}
				}
			}
		}
		i=j;
	}
	rb(i,1,Q){
		cout<<res[i]+M[II(qs[i][0],qs[i][1])]<<endl;
	}
	return 0;
}