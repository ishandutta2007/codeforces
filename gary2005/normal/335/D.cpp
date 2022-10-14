/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=3000;
int sum[MAXN+3][MAXN+3];
int col[MAXN+3][MAXN+3],row[MAXN+3][MAXN+3];
int n;
typedef pair<mp,mp> RET;
#define x1 FIR.FIR
#define y1 FIR.SEC
#define x2 SEC.FIR
#define y2 SEC.SEC
RET ret[100000+20];
bool in(RET A,RET B);
bool in(RET A,RET B){
	if(A.x1<B.x1||A.y1<B.y1||A.x2>B.x2||A.y2>B.y2) return false;
	return true;
}
bool query(int xs,int ys,int xt,int yt){
	swap(yt,xt);
	swap(ys,xs);
	int Sum=sum[xt][yt]+sum[xs-1][ys-1]-sum[xt][ys-1]-sum[xs-1][yt];
	return Sum==(xt-xs+1)*(yt-ys+1);
}
int main(){
//	fastio;
	cin>>n;
	rb(i,1,n){
		scanf("%d %d %d %d",&ret[i].x1,&ret[i].y1,&ret[i].x2,&ret[i].y2);
//		cin>>ret[i].x1>>ret[i].y1>>ret[i].x2>>ret[i].y2;
		ret[i].x1++;
		ret[i].y1++;
		row[ret[i].y1][ret[i].x1]++;
		row[ret[i].y2][ret[i].x1]--;
		row[ret[i].y1][ret[i].x2+1]--;
		row[ret[i].y2][ret[i].x2+1]++;
//		rb(j,ret[i].y1,ret[i].y2-1){
//			row[j][ret[i].x1]++;
//			row[j][ret[i].x2+1]--;	
//		}
		col[ret[i].x1][ret[i].y1]++;
		col[ret[i].x2][ret[i].y1]--;
		col[ret[i].x1][ret[i].y2+1]--;
		col[ret[i].x2][ret[i].y2+1]++;
//		rb(j,ret[i].x1,ret[i].x2-1){
//			col[j][ret[i].y1]++;
//			col[j][ret[i].y2+1]--;
//		}
		sum[ret[i].y1][ret[i].x1]++;
		sum[ret[i].y2+1][ret[i].x1]--;
		sum[ret[i].y1][ret[i].x2+1]--;
		sum[ret[i].y2+1][ret[i].x2+1]++;
//		rb(j,ret[i].y1,ret[i].y2)
//			sum[j][ret[i].x1]++,sum[j][ret[i].x2+1]--;
	}
	rb(i,1,MAXN)
		rb(j,1,MAXN)
			sum[j][i]+=sum[j-1][i],row[j][i]+=row[j-1][i],col[j][i]+=col[j-1][i];
	rb(i,1,MAXN)
		rb(j,1,MAXN)
			row[i][j]+=row[i][j-1],col[i][j]+=col[i][j-1],sum[i][j]+=sum[i][j-1];
	rb(i,1,MAXN) rb(j,1,MAXN) sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1],row[i][j]+=row[i][j-1],col[i][j]+=col[i][j-1];
	rb(i,1,n){
		int X1,Y1;
		X1=ret[i].x1;
		Y1=ret[i].y1;
		rb(len,1,MAXN){
			int X2,Y2;
			X2=X1+len-1;
			Y2=Y1+len-1;
			if(X2>MAXN||Y2>MAXN) break;
			if(!query(X1,Y1,X2,Y2)) break;
			if(row[Y1-1][X2]-row[Y1-1][X1-1]) break;
			if(col[X1-1][Y2]-col[X1-1][Y1-1]) break;
			if((row[Y2][X2]-row[Y2][X1-1]==0)&&(col[X2][Y2]-col[X2][Y1-1]==0)){
				cout<<"YES ";
				RET AREA;
				AREA=II(II(X1,Y1),II(X2,Y2));
				vector<int> v;
				rb(j,1,n){
					if(in(ret[j],AREA)){
						v.PB(j);
					}
				}
				cout<<v.size()<<endl;
				for(auto it:v){
					cout<<it<<' ';
				}
				cout<<endl;
				return 0;				
			}
		}
	}
	cout<<"NO\n";
	return 0;
}
/** 
  *
  *
  *
  *
  **/