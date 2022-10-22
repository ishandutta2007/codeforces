#include<bits/stdc++.h>
using namespace std;
#define F fflush(stdout)
typedef long long LL;
struct node{
	int a,b,c;
	node(int A=0,int B=0,int C=0){int p[5];p[1]=A,p[2]=B,p[3]=C;sort(p+1,p+1+3),a=p[1],b=p[2],c=p[3];}
	bool operator < (node ano) const {return a<ano.a || (a==ano.a && b<ano.b) || (a==ano.a && b==ano.b && c<ano.c);}
};
set<int> S1,S2;
map<node,int> M;
void Solve()
{
	int n;
	scanf("%d",&n);
	int maxn=0;
	S1.clear(),S2.clear();
	M.clear();
	for(int i=3;i<=n;++i)
	{
		int x=M[node(1,2,i)];
		if(!x)	printf("? 1 2 %d\n",i),F,scanf("%d",&x);
		M[node(1,2,i)]=x;
		if(i==3)	maxn=x,S1.insert(i);
		if(x>maxn)	maxn=x,S1.clear(),S1.insert(i);
	}
	maxn=0;
	int beg=*S1.begin();
	for(int i=2;i<=n;++i)
	{
		if(i==beg)	continue;
		int x=M[node(1,i,beg)];
		if(!x)	printf("? 1 %d %d\n",i,beg),F,scanf("%d",&x);
		M[node(1,i,beg)]=x;
		if(x>maxn)	maxn=x,S2.clear(),S2.insert(i);
	}
	S2.insert(beg);
	S2.insert(1);
	int minn=0;
	int A=1,B=*next(S2.begin()),C=*next(next(S2.begin()));
	for(int i=1;i<=n;++i)
	{
		if(i==A || i==B || i==C)	continue;
		minn=i;
		break;
	}
	int X,Y,Z;
	int x;
	x=M[node(A,B,minn)];
	if(!x)	printf("? %d %d %d\n",A,B,minn),F,scanf("%d",&x);
	M[node(A,B,minn)]=X=x;
	x=M[node(A,C,minn)];
	if(!x)	printf("? %d %d %d\n",A,C,minn),F,scanf("%d",&x);
	M[node(A,C,minn)]=Y=x;
	x=M[node(B,C,minn)];
	if(!x)	printf("? %d %d %d\n",B,C,minn),F,scanf("%d",&x);
	M[node(B,C,minn)]=Z=x;
	maxn=max({X,Y,Z});
	if(X==maxn)	printf("! %d %d\n",A,B);
	else if(Y==maxn)	printf("! %d %d\n",A,C);
	else if(Z==maxn)	printf("! %d %d\n",B,C);
	F;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T-->0)	Solve();
	return 0;
}