#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n;
#define Maxn 305
#define cout cerr
#define FR first
#define SE second
char ch[Maxn][Maxn];

int dir(char c){
	if(c=='X')return 0;
	return 1;
}
vector<pii> vec[3][2];

void gao(int x,int y){
	if(ch[x][y]=='X')ch[x][y]='O';
	else ch[x][y]='X';
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	int T;rd(T);
	while(T--){
		rd(n);
		for(int i=0;i<3;++i)for(int j=0;j<2;++j)vec[i][j].clear();
		for(int i=1;i<=n;++i){
			scanf("%s",ch[i]+1);
			for(int j=1;j<=n;++j)
				if(ch[i][j]!='.')vec[(i+j)%3][dir(ch[i][j])].push_back(pii(i,j));
		}
		int mn=1000000;pii t1,t2;
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				if(i!=j)
					for(int k=0;k<2;++k){
						if(vec[i][k].size()+vec[j][k^1].size()<mn){
							mn=vec[i][k].size()+vec[j][k^1].size();
							t1=pii(i,k);t2=pii(j,k^1);
						}
					}
		for(int i=0;i<vec[t1.FR][t1.SE].size();++i)gao(vec[t1.FR][t1.SE][i].FR,vec[t1.FR][t1.SE][i].SE);
		for(int i=0;i<vec[t2.FR][t2.SE].size();++i)gao(vec[t2.FR][t2.SE][i].FR,vec[t2.FR][t2.SE][i].SE);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)putchar(ch[i][j]);
			puts("");
		}
	}	
	return 0;
}