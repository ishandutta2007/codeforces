#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 2005
const int inf=99999;
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
int n,k,a[N][N],mp[N][N],cnt,f[N][N],ans;
char s[N][N];
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=n;j++){
			if(s[i][j]=='W'){
				mp[i][j]=1;
			}
			else{
				mp[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int l=inf,r=-inf;
		for(int j=1;j<=n;j++){
			if(mp[i][j]==0){
				l=min(l,j);
				r=max(r,j);
			}
		}
		if(l==inf&&r==-inf){
			cnt++;
		}
		else{
			if(r-l+1>k)continue;
			int X1=max(1,i-k+1),Y1=max(1,r-k+1),X2=i,Y2=l;
			a[X1][Y1]++;
			a[X2+1][Y2+1]++;
			a[X2+1][Y1]--;
			a[X1][Y2+1]--;
		}
	}
	for(int i=1;i<=n;i++){
		int l=inf,r=-inf;
		for(int j=1;j<=n;j++){
			if(mp[j][i]==0){
				l=min(l,j);
				r=max(r,j);
			}
		}
		if(l==inf&&r==-inf){
			cnt++;
		}
		else{
			if(r-l+1>k)continue;
			int X1=max(1,r-k+1),Y1=max(1,i-k+1),X2=l,Y2=i;
			a[X1][Y1]++;
			a[X2+1][Y2+1]++;
			a[X2+1][Y1]--;
			a[X1][Y2+1]--;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
			ans=max(ans,f[i][j]);
		}
	}
	cout<<ans+cnt<<endl;
	return 0;
}