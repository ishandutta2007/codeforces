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
int a[11][11];
int Xx,Yy;
int movex[2][8]={{-2,-1,1,2,2,1,-1,-2},{-1,1,1,-1}};
int movey[2][8]={{1,2,  2,1,-1,-2,-2,-1},{1,1,-1,-1}};
int dp1[11][11][101][3],dp2[11][11][101][3];
struct minecraft{
	int x;
	int y;
	int to;
	int res1,res2;
	int sat;
};
int n;
mp final=II(INF,INF);
void bfs(){
	queue<minecraft> q;
	minecraft tmp;
	tmp.x=Xx;
	tmp.y=Yy;
	tmp.to=0;
	tmp.res1=tmp.res2=0;
	tmp.sat=INF;
	q.push(tmp);
	minecraft now;
//	cout<<"s"<<endl;
	while(!q.empty()){
		now=q.front();
//		cout<<"s"<<endl;
		q.pop();
		int X=now.x,Y=now.y,Res1=now.res1,Res2=now.res2,To=now.to,Sat=now.sat;
		if(X<=0||X>n||Y<=0||Y>n) continue;
		if(a[X][Y]==To+1){
			now.to++;
			To++;
		}
//		cout<<Sat<<endl;
		if(Sat!=INF)
		if(II(dp1[X][Y][To][Sat],dp2[X][Y][To][Sat])<=II(Res1,Res2)){
			continue;
		}
		if(Sat!=INF)dp1[X][Y][To][Sat]=Res1;
		if(Sat!=INF)dp2[X][Y][To][Sat]=Res2;
//		cout<<X<<" "<<Y<<" "<<To<<" "<<Sat<<" "<<Res1<<" "<<Res2<<endl;
		//012 
		if(Res1>final.FIR) continue;
		if(To==n*n){
//			cout<<Res1<<" "<<Res2<<endl;
			final=min(final,II(Res1,Res2));
			continue;
		}
		rep(i,3){
			if(Sat==INF){
				tmp=now;
				tmp.sat=i;
				q.push(tmp);
//				cout<<"change-to"<<i<<endl;
			}
			else{
				if(Sat!=i){
					tmp=now;
					tmp.sat=i;
					tmp.res1++;
					tmp.res2++;
					q.push(tmp);
//					cout<<"change-to"<<i<<endl;
				}
			}
		} 
		//************************************************************
		if(Sat==0){
			int up;
			up=8;
			rep(i,up){
				tmp=now;
				tmp.x+=movex[Sat][i];
				tmp.y+=movey[Sat][i];
				tmp.res1++;
//				cout<<"go-to"<<tmp.x<<" "<<tmp.y<<endl;
				q.push(tmp);
			}
		}
		if(Sat==2){
			rb(i,1,n){
				tmp=now;
				if(i==tmp.x){
					continue;
				}
				tmp.x=i;
				tmp.res1++; 
//				cout<<"go-to"<<tmp.x<<" "<<tmp.y<<endl;
				q.push(tmp);
			}
			rb(i,1,n){
				tmp=now;
				if(i==tmp.y) continue;
				tmp.y=i;
				tmp.res1++;
//				cout<<"go-to"<<tmp.x<<" "<<tmp.y<<endl;
				q.push(tmp);
			}
		}
		if(Sat==1){
			int nowx,nowy;
			//up-left
			nowx=X-1;
			nowy=Y-1;
			while(nowx>0&&nowy>0){
				tmp=now;
				tmp.x=nowx;
				tmp.y=nowy;
				tmp.res1++;
				q.push(tmp);
				nowx--;
				nowy--;
			}
			//up-right
			nowx=X-1;
			nowy=Y+1;
			while(nowx>0&&nowy<=n){
				tmp=now;
				tmp.x=nowx;
				tmp.y=nowy;
				tmp.res1++;
				q.push(tmp);
				nowx--;
				nowy++;
			}
			//down-right
			nowx=X+1;
			nowy=Y+1;
			while(nowx<=n&&nowy<=n){
				tmp=now;
				tmp.x=nowx;
				tmp.y=nowy;
				tmp.res1++;
				q.push(tmp);
				nowx++;
				nowy++;
			}
			//down-left
			nowx=X+1;
			nowy=Y-1;
			while(nowx<=n&&nowy>0){
				tmp=now;
				tmp.x=nowx;
				tmp.y=nowy;
				tmp.res1++;
				q.push(tmp);
				nowx++;
				nowy--;
			}
		}
	}
}
int main(){
//	FREO;
	memset(dp1,0x3f,sizeof(dp1));
	memset(dp2,0x3f,sizeof(dp2));
	scanf("%d",&n);
	rb(i,1,n){
		rb(j,1,n){
			scanf("%d",&a[i][j]);
			if(a[i][j]==1){
				Xx=i;
				Yy=j;
			}
		}
	}
	bfs();
//	final=min(final,II(182,4));
	printf("%d %d\n",final.FIR,final.SEC);
	return 0;
}