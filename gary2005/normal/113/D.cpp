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
const double eps=1e-11;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int id[23][23];
int cnt;
int n,a,b,m;
vector<int> each[23];
vector<pair<int,double> > finl[24];
double v[500][500];
double p[500];
int get(int x,int y){
	if(x>y){
		return get(y,x);
	}
	return  id[x][y];
}
double cost[500][5005];
double getcost(int x,int y){
	swap(x,y);
	return cost[x][y];
}
double calc(int now){
	cnt=0;
	rb(i,1,n)
		rb(j,i,n)
			id[i][j]=++cnt;
	memset(v,0,sizeof(v));
	rb(i,1,n){
		rb(j,i,n){
			v[get(i,j)][get(i,j)]+=1;
			rb(k,1,n)
				rb(l,k,n){
					if(getcost(k,i)>0&&getcost(l,j)>0) {
//					v[get]
					v[get(i,j)][get(k,l)]-=getcost(k,i)*getcost(l,j);
					}
					if(l!=k)
					if(getcost(k,j)>0&&getcost(l,i)>0) {	
					v[get(i,j)][get(k,l)]-=getcost(k,j)*getcost(l,i);
					}
				}
		}
	}
	
	rb(i,1,n)
	{
		memset(v[get(i,i)],0,sizeof(v[get(i,i)]));
		v[get(i,i)][(get(i,i))]=1;
	}
	v[get(now,now)][cnt+1]=1;
	rb(i,1,cnt){
		int p=i;
		rb(j,i,cnt){
			if(abs(v[j][i])>abs(v[p][i])){
				p=j;
			}
		}
//		cout<<p<<endl;
//		cout<<"!"<<v[p][i]<<endl;
		swap(v[p],v[i]);
		rl(j,cnt+1,i) 
		v[i][j]/=v[i][i];
		rb(j,1,cnt){
			if(j!=i){
				if(abs(v[j][i])>eps)
				rl(k,cnt+1,i){
					v[j][k]-=v[j][i]*v[i][k];
				} 
			}
		}
	}
//	rb(i,1,cnt)
//	{
//		rb(j,1,cnt){
//			cout<<v[i][j]<<"    ";
//		}
//		cout<<"|"<<v[i][cnt+1]<<endl;;
//	}
	return v[get(a,b)][cnt+1];
}
int main(){
//	fastio;
	cin>>n>>m>>a>>b;
	rb(i,1,m){
		int u,v;
		cin>>u>>v;
		each[u].PB(v);
		each[v].PB(u);	
	}
	rb(i,1,n)
		rb(j,1,n)
			cost[i][j]=-1.5;
	rb(i,1,n)
		cin>>p[i];
	rb(i,1,n)
	{
		for(auto it:each[i]){
			finl[i].PB(II(it,(1.0-p[i])/double(each[i].size())));
		}
		finl[i].PB(II(i,p[i]));
		for(auto it:finl[i]){
			int u,v;
			u=i;
			v=it.FIR;
			
			cost[u][v]=it.SEC;
		}
	}
	rb(i,1,n){
		printf("%.16f ",calc(i)); 
	}
	return 0;
}
/*

5 4 2 5
2 1
3 1
4 1
5 1
0.5
0.5
0.5
0.5
0.5

*/