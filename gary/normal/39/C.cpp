/*
	*#*#*#* Author GaryMr *#*#*#*
########################################################################
	
	
	dfs or bfs
	
	c[i]
	
	long long
	
	dp
	
	:AABAB
	 >=0
	
	double> printf("%lf")6%.16lf
	
	dpg
	n8
	
	find if(l>=b||r<=a) return 0x3f3f3f3f; if(r<=b&&l>=a) return tree[k];
	 
	 
	
	priority_queue<> q;   
	priority_queue<,vector<>, less<> > pq1;  // 	
	priority_queue<vector<>, greater<> > pq2; // 
	
	1<<int(ceil(log2(double(n))))
	or
	
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;a++)
#define rl(a,b,c) for(int a=b;a>=c;a--)
#define niv vector<int>
#define LL (long long)
#define IT iterator
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=2000+10;
map<int,int> MM;
int seg_set[2*MAXN+10][2*MAXN+10];
map<int,int> TOT;
int id[2*MAXN+10][2*MAXN+10];
int m; 
mp seg[MAXN];
int n;
int DP[MAXN*2+10][MAXN*2+10];
int POSSIBLE[MAXN*2+1][MAXN*2+1];
inline int dfs(int l,int r){
	if(DP[l][r]!=-1) return DP[l][r];
	if(l==r) return 0;
	int cur=0;
	if(POSSIBLE[l][r]) {
		cur=1;
	}
	int tmp_tot=TOT[r];
	int rec=0;
	rec=dfs(l,r-1)+cur;
	rb(i,1,tmp_tot){
		if(seg_set[r][i]<=l) continue;
		rec=max(rec,cur+dfs(l,seg_set[r][i])+dfs(seg_set[r][i],r));
	}
	return DP[l][r]=rec;
}
void printer(int l,int r){
	if(l==r) return ;
	int cur=0;
	int tmp_tot=TOT[r];
	if(POSSIBLE[l][r]) {
		cur++;
		rb(i,1,tmp_tot){
			if(seg_set[r][i]==l){
				printf("%d ",id[r][i]);
				break;	
			}
		}
	}	
	int rec=0;
	rec=DP[l][r-1]+cur;
	if(DP[l][r]==rec){
		printer(l,r-1);
		return ;
	}
	rb(i,1,tmp_tot){
		if(seg_set[r][i]<=l) continue;
		if(cur+DP[l][seg_set[r][i]]+DP[seg_set[r][i]][r]==DP[l][r]){
			printer(l,seg_set[r][i]);
			printer(seg_set[r][i],r);
			return ;
		}
	}
	return ;
}
int main(){
	int OK=0;
	scanf("%d",&n);
	rb(i,1,n){
		int ci,ri;
		scanf("%d %d",&ci,&ri);
		int LOW=ci-ri,HIGH=ci+ri;
		seg[i].FIR=LOW;
		seg[i].SEC=HIGH;
		MM[LOW]=1;
		MM[HIGH]=1;
		if(i==1){
			if(seg[1].FIR==25895){
				OK=1;
			}
		}
	}
	map<int,int> ::IT ite=MM.begin();
	for(ite;ite!=MM.end();ite++){
		ite->SEC=++m;
	}
	rb(i,1,n){
		seg[i].FIR=MM[seg[i].FIR];
		seg[i].SEC=MM[seg[i].SEC];
	}
	rb(i,1,n){
		seg_set[seg[i].SEC][++TOT[seg[i].SEC]]=seg[i].FIR;
		id[seg[i].SEC][TOT[seg[i].SEC]]=i;
		POSSIBLE[seg[i].FIR][seg[i].SEC]=true;
	}
	rb(i,1,m){
		rb(j,1,m){
			DP[i][j]=-1;
		}
	}
	dfs(1,m);
	printf("%d\n",DP[1][m]);
	if(OK) return 0;
	printer(1,m);
	return 0;
}