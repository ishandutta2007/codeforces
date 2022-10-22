#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,t) for(int i=(s),_t=(t);i<=_t;++i)
#define DOR(i,s,t) for(int i=(s),_t=(t);i>=_t;--i)
#define INF 0x3f3f3f3f
#define M 100005

struct node{
	int x,y,z;
	bool operator <(const node &s) const{
		return y<s.y;	
	}
}A[M<<2];
node MIN(node a,node b) {
	return a.z<b.z?a:b;	
}
bool cmp(node a,node b) {
	return a.x<b.x;	
}
int X[M],Y[M];
node Tmp[M<<2];
node dfs(int L,int R) {
	if(L==R) return (node){0,0,INF};
	int mid=L+R>>1,pos_mid=A[mid].x+A[mid+1].x>>1;
	node tmp=MIN(dfs(L,mid),dfs(mid+1,R));
	sort(A+L,A+R+1);
	int top=0;
	FOR(i,L,R) {
		if((A[i].x-pos_mid)*(A[i].x-pos_mid)>=tmp.z) continue;
		DOR(j,top,1) {
			if((Tmp[j].y-A[i].y)*(Tmp[j].y-A[i].y)>=tmp.z) break;
			if((A[i].z+3)/4!=(Tmp[j].z+3)/4)
				tmp=MIN(tmp,(node){A[i].z,Tmp[j].z,(Tmp[j].y-A[i].y)*(Tmp[j].y-A[i].y)+(Tmp[j].x-A[i].x)*(Tmp[j].x-A[i].x)});
		}
		Tmp[++top]=A[i];
	}
	return tmp;
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int n,m=0;
	scanf("%d",&n);
	FOR(i,1,n) {
		scanf("%d%d",&X[i],&Y[i]);
		A[++m]=(node){X[i],Y[i],m};
		A[++m]=(node){-X[i],Y[i],m};
		A[++m]=(node){X[i],-Y[i],m};
		A[++m]=(node){-X[i],-Y[i],m};
	}
	sort(A+1,A+m+1,cmp);
	node res=dfs(1,m);
	printf("%d %d %d %d\n",(res.x+3)/4,(res.x+3)%4+1,(res.y+3)/4,5-((res.y+3)%4+1));
	return 0;
}