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
struct mine{
	int x,y;
	int mask;
	int step;
};
char tab;
int n,m;
int len;
int X,Y;
int XY,YY;
int Right,Left,up,down;
int save; 
int no_way[17][17];
int tmp_no_way[17][17];
map<int,mp> snake;
int v[15][15][262144];
int main(){
	Right=3;
	Left=2;
	up=1;
	down=0;
	scanf("%d %d",&n,&m);
	rb(i,1,n)
		rb(j,1,m){
			cin>>tab;
			if(tab=='@') XY=i,YY=j;
			if(tab>='1'&&tab<='9'){
				len=max(len,tab-'0');
				if(tab-'0'==1){
					X=i;
					Y=j;
				}
				snake[tab-'0']=II(i,j);
			}
			if(tab=='#') no_way[i][j]=1;
		}
	save=1<<(len<<1);
	save--;
	mine start;
	start.x=X;
	start.y=Y;
	start.step= 0;
	int lasx,lasy;
	lasx=snake[1].FIR;
	lasy=snake[1].SEC;
	int nowx,nowy;
	int Mask=0;
	rl(i,len,2){
		lasx=snake[i-1].FIR;
		lasy=snake[i-1].SEC;
		nowx=snake[i].FIR;
		nowy=snake[i].SEC;
		Mask<<=2;
		if(nowx==lasx){
			if(lasy==nowy-1){
				Mask|=Right;
			}
			else
				Mask|=Left;
		}
		else{
			if(lasx==nowx-1){
				Mask|=down;
			}
			else
				Mask|=up;
		}
	}
	start.mask=Mask;
	queue<mine> q;
	q.push(start);
	while(!q.empty()){
		mine now=q.front();
		q.pop();
		if(now.x<=0||now.x>n||now.y<=0||now.y>m) continue;
		if(v[now.x-1][now.y-1][now.mask])  continue;
		v[now.x-1][now.y-1][now.mask]=1;
		if((XY==now.x&&YY==now.y)){
			printf("%d\n",now.step);
			return 0;
		}
		memset(tmp_no_way,0,sizeof(tmp_no_way));
		tmp_no_way[now.x][now.y]=1;
		int nowX,nowY;
		nowX=now.x;
		nowY=now.y;
		Mask=now.mask;
		rb(i,2,len-1){
			int oper=Mask&(3);
			if(oper==down){
				nowX=nowX+1;
			}
			else{
				if(oper==up){
					nowX=nowX-1;
				}
				else{
					if(oper==Right){
						nowY=nowY+1;
					}
					else{
						//left
						nowY=nowY-1;
					}
				}
			}
			tmp_no_way[nowX][nowY]=1;
			Mask>>=2;
		}
		mine TMP=now;
		TMP.step++;
		nowX=now.x;
		nowY=now.y;
		if(!tmp_no_way[nowX-1][nowY]&&!no_way[nowX-1][nowY]&&nowX!=1){
			TMP.x=nowX-1;
			TMP.y=nowY; 
			TMP.mask=now.mask;
			TMP.mask<<=2;
			TMP.mask&=save;
			TMP.mask|=down;
			if(!v[TMP.x-1][TMP.y-1][TMP.mask])
			q.push(TMP);
		}
		TMP=now;
		TMP.step++;
		if(!tmp_no_way[nowX][nowY-1]&&!no_way[nowX][nowY-1]&&nowY!=1){
			TMP.x=nowX;
			TMP.y=nowY-1;
			TMP.mask=now.mask;
			TMP.mask<<=2;
			TMP.mask&=save;
			TMP.mask|=Right;
			if(!v[TMP.x-1][TMP.y-1][TMP.mask])
			q.push(TMP);
		}
		TMP=now;
		TMP.step++;
		if(!tmp_no_way[nowX+1][nowY]&&!no_way[nowX+1][nowY]&&nowX!=n){
			TMP.x=nowX+1;
			TMP.y=nowY;
			TMP.mask=now.mask;
			TMP.mask<<=2;
			TMP.mask&=save;
			TMP.mask|=up;
			if(!v[TMP.x-1][TMP.y-1][TMP.mask])
			q.push(TMP);
		}
		TMP=now;
		TMP.step++;
		if(!tmp_no_way[nowX][nowY+1]&&!no_way[nowX][nowY+1]&&nowY!=m){
			TMP.x=nowX;
			TMP.y=nowY+1;
			TMP.mask=now.mask;
			TMP.mask<<=2;
			TMP.mask&=save;
			TMP.mask|=Left;
			if(!v[TMP.x-1][TMP.y-1][TMP.mask])
			q.push(TMP);
		}
	}
	puts("-1");
	return 0;
}