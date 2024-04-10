#include<bits/stdc++.h>
using namespace std;
#define N 205
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,cnt,T[N][N];
inline int Ask(int x,int y){
	if(~T[x][y])return T[x][y];
	printf("? %d %d\n",x,y);
	fflush(stdout);
	char c;
	do{c=getchar();}while(c!='<'&&c!='>');
	T[x][y]=c=='>';
	return T[x][y];	
}
struct Cmp{
	bool operator () (int x,int y)const{
		return !Ask(x,y);	
	}
};
set<int,Cmp> A,B;
void Solve(){
	memset(T,-1,sizeof(T));
	n=read();
	cnt=0;
	A.clear(),B.clear();
	int X=(n+1)/2,Y=n+1-X;
	for(int i=1;i<=X;++i)A.insert(++cnt);
	for(int i=1;i<=Y;++i)B.insert(++cnt);
	for(int i=1;i<=n;++i){
		int u=*A.begin(),v=*B.begin();
		if(!Ask(u,v)){A.erase(A.begin());if(i<n)A.insert(++cnt);}
		else{B.erase(B.begin());if(i<n)B.insert(++cnt);}
	}
	printf("!\n");
	fflush(stdout);
}
int main(){
	int T=read();
	while(T--)Solve();
	return 0;
}