#include<bits/stdc++.h>
using namespace std;
 
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)

typedef long long ll;

int P[15];

const int M=(int)16e5;

int n,V[26][4];
struct node{
	ll v1,v2,v;int now;
	bool operator == (const node &_)const{
		return v1==_.v1&&v2==_.v2;
	}
	bool operator < (const node &_)const{
		if(v1==_.v1){
			if(v2==_.v2)return v>_.v;
			return v2<_.v2;
		}
		return v1<_.v1;
	}
}A1[M],A2[M],B[M];
int n1,n2;

void solve(int L,int R,int p){
	int len=R-L+1;
	int n3=0;
	FOR(i,0,P[len]-1) {
		ll v1=0,v2=0,v3=0;
		FOR(j,0,len-1) {
			int p1=i/P[j]%3;
			if(p1==0) v1+=V[j+L][1],v2+=V[j+L][2];
			if(p1==1) v1+=V[j+L][1],v3+=V[j+L][3];
			if(p1==2) v2+=V[j+L][2],v3+=V[j+L][3];
		}
		B[++n3]=(node){v1-v2,v1-v3,v1,i};
	}
	sort(B+1,B+1+n3);
	FOR(i,1,n3) {
		if(B[i]==B[i-1])continue;
		if(!p)A1[++n1]=B[i];
		else A2[++n2]=B[i];
	}
}
int main(){
	P[0]=1;
	FOR(i,1,14) P[i]=P[i-1]*3;
	scanf("%d",&n);
	FOR(i,1,n) {
		FOR(j,1,3) {
			scanf("%d",&V[i][j]);
		}
	}
	if(n==1){
		if(V[1][1]==0&&V[1][2]==0) puts("LM");
		else if(V[1][1]==0&&V[1][3]==0) puts("LW");
		else if(V[1][2]==0&&V[1][3]==0) puts("MW");
		else puts("Impossible");
		return 0;
	}
	solve(1,n/2,0);
	solve(n/2+1,n,1);
	ll mx=-1e18;int a1=0,a2=0;
	FOR(i,1,n1) {
		node ned=(node){-A1[i].v1,-A1[i].v2,0,0};
		int x=lower_bound(A2+1,A2+1+n2,ned)-A2;
		FOR(j,max(1,x-1),min(x+1,n2)){
			if(A2[j]==ned){
				ll v=A1[i].v+A2[j].v;
				if(v>mx)mx=v,a1=i,a2=j;
			}
		}
	}
	if(a1==0) puts("Impossible");
	else{
		int L=1,R=n/2;
		FOR(i,0,R-L) {
			int p=A1[a1].now/P[i]%3;
			if(p==0) puts("LM");
			if(p==1) puts("LW");
			if(p==2) puts("MW");
		}
		L=n/2+1,R=n;
		FOR(i,0,R-L) {
			int p=A2[a2].now/P[i]%3;
			if(p==0) puts("LM");
			if(p==1) puts("LW");
			if(p==2) puts("MW");
		}
	}
	return 0;
}