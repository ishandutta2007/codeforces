#include<iostream>
#include<cstdio>
using namespace std;
#define N 2505
typedef long long ll;
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
int n,m,k;
int s[N][N],up[2][10];
char ch[N][N];
ll ans=0;
int calc(int x1,int x2,int y1,int y2){
	return s[x2][y2]-s[x1][y2]-s[x2][y1]+s[x1][y1];
}
void solve(int x1,int x2,int y1,int y2,int type){
	if(x1==x2||y1==y2)return;
	if((x1==x2-1)&&(y1==y2-1)){
		ans+=(calc(x1,x2,y1,y2)==k);
		return ;
	}
	if(type){
		int mid=(x1+x2)>>1;
		solve(x1,mid,y1,y2,0);
		solve(mid,x2,y1,y2,0);
		for(int i=y1;i<=y2;i++){
			up[0][0]=up[1][0]=mid;
			for(int p=1;p<=k+1;p++){
				up[0][p]=x1,up[1][p]=x2;
			}
			for(int j=i+1;j<=y2;j++){
				for(int p=1;p<=k+1;p++){
					while(calc(up[0][p],mid,i,j)>=p){
						up[0][p]++;
					}
				}
				for(int p=1;p<=k+1;p++){
					while(calc(mid,up[1][p],i,j)>=p){
						up[1][p]--;
					}
				}
				for(int p=0;p<=k;p++){
					ans+=(ll)(up[0][p]-up[0][p+1])*(up[1][k-p+1]-up[1][k-p]);
				}
			}
		}
	}
	else{
		int mid=(y1+y2)>>1;
		solve(x1,x2,y1,mid,1);
		solve(x1,x2,mid,y2,1);
		for(int i=x1;i<=x2;i++){
			up[0][0]=up[1][0]=mid;
			for(int p=1;p<=k+1;p++){
				up[0][p]=y1;
				up[1][p]=y2;
			}
			for(int j=i+1;j<=x2;j++){
				for(int p=1;p<=k+1;p++){
					while(calc(i,j,up[0][p],mid)>=p){
						up[0][p]++;
					}
				}
				for(int p=1;p<=k+1;p++){
					while(calc(i,j,mid,up[1][p])>=p){
						up[1][p]--;
					}
				}
				for(int p=0;p<=k;p++){
					ans+=(ll)(up[0][p]-up[0][p+1])*(up[1][k-p+1]-up[1][k-p]);
				}
			}
			
		}
	}
}
int main(){
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++){
		scanf("%s",ch[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+ch[i][j]-'0'; 
		}
	}
	solve(0,n,0,m,0);
	cout<<ans<<endl;
	return 0;
}