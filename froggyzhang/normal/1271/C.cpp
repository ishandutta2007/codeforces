#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
const int inf=1000000000;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,sx,sy,ans,px,py;
int ax[N],ay[N];
int main(){
	n=read(),sx=read(),sy=read();ans=-1;
	for(int i=1;i<=n;i++){
		ax[i]=read(),ay[i]=read();
	}
	if(sx>0){
		int tot=0,x=sx-1,y=sy;
		for(int i=1;i<=n;i++){
			if(ax[i]<=x)++tot;
		}
		if(tot>ans)ans=tot,px=x,py=y;
	}
	if(sx<inf){
		int tot=0,x=sx+1,y=sy;
		for(int i=1;i<=n;i++){
			if(ax[i]>=x)++tot;
		}
		if(tot>ans)ans=tot,px=x,py=y;
	}
	if(sy>0){
		int tot=0,x=sx,y=sy-1;
		for(int i=1;i<=n;i++){
			if(ay[i]<=y)++tot;
		}
		if(tot>ans)ans=tot,px=x,py=y;
	}
	if(sy<inf){
		int tot=0,x=sx,y=sy+1;
		for(int i=1;i<=n;i++){
			if(ay[i]>=y)++tot;
		}
		if(tot>ans)ans=tot,px=x,py=y;
	}
	printf("%d\n",ans);
	printf("%d %d\n",px,py);
	return 0;
}