//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
char c[1010][1010];
int mark[1010][1010];
vector<int> res(1000000+10);
int now=0;int n,m;
int dirx[4]={0,0,1,-1},diry[4]={1,-1,0,0};
inline void dfs(int x,int y){
	if(x>n||x<=0||y>m||y<=0) return;
	if(mark[x][y]) return;
	mark[x][y]=now;
	res[now]++;
//	cout<<now<<endl;
	rep(i,4){
		if(!mark[x+dirx[i]][y+diry[i]]&&c[x+dirx[i]][y+diry[i]]!='*'){
			dfs(x+dirx[i],y+diry[i]);
		}
	}
}
int main(){
	
	scanf("%d %d",&n,&m);
	rb(i,1,n){
		rb(j,1,m){
			cin>>c[i][j];
		}
	}
	res[0]=0;
	rb(i,1,n){
		rb(j,1,m){
			if(!mark[i][j]&&c[i][j]=='.'){
				++now;
				res[now]=0;
				dfs(i,j);//cout<<res[now]<<endl;
			}
			
		}
	}
	rb(i,1,n){
		rb(j,1,m){
			if(c[i][j]=='*'){
				map<int,int> app;
				int Res=0;
				rep(k,4){
					int tox,toy;
					tox=i+dirx[k],toy=j+diry[k];
//					cout<<tox<<" "<<toy<<" "<<mark[tox][toy]<<" "<<res[mark[tox][toy]]<<endl;
					if(!app[mark[tox][toy]]){
						app[mark[tox][toy]]=1;
						Res+=res[mark[tox][toy]];
					}
				}
				Res++;
				printf("%d",Res%10);
			}
			else{
				printf(".");
			}
		}
		cout<<endl;
	}
	return 0;
}