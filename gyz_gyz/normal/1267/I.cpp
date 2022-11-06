#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
using namespace std;
const int N=210;
char str[N];
int t[N][N],f[N];bool ok[N];
bool bg(int x,int y){
	bool f=0;
	if(x<y){
		swap(x,y);f=1;
	}
	if(!t[x][y]){
		printf("? %d %d\n",x,y);
		fflush(stdout);scanf("%s",str);
		if(str[0]=='>')t[x][y]=1;else t[x][y]=-1;
	}
	if(t[x][y]==1)f^=1;return f;
}
void sol(){int n;
	scanf("%d",&n);
	rep(i,1,n*2)ok[i]=0;
	rep(i,1,n*2)rep(j,1,i)t[i][j]=0;
	rep(i,1,n)if(bg(i,i+n))f[i]=0;else f[i]=1;
	rep(i,1,n){int ct=0;
		rep(j,1,n)if(i!=j)
			if(bg(i+n*(1-f[i]),j+n*(1-f[j])))++ct;
		if(ct==n-1){
			ok[i+n*f[i]]=1;break;
		}
	}
	rep(i,1,n)if(!ok[i+n*f[i]]){int ct=0;
		rep(j,1,n)if(i!=j&&!ok[j+n*f[j]])
			if(bg(i+n*f[i],j+n*f[j]))++ct;
		if(ct==n-2){
			ok[i+n*f[i]]=1;break;
		}
	}
	rep(i,1,n*2)if(!ok[i])rep(j,1,n*2)if(!ok[j]&&i!=j)bg(i,j);
	printf("!\n");fflush(stdout);
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}