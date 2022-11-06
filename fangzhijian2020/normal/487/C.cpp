#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int read(){
	int a=0,opt=0;char c=getchar();while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();return opt?-a:a;
}
int T,n,opt,prime[100005],tot,inv[100005];bool vis[100005];
int main(){
//	system("fc perm.out perm2.out");
//	freopen("perm.in","r",stdin);
//	freopen("perm.out","w",stdout);
//    T=read()+1;
    for(int i=2;i<=1e5;++i){
    	if(!vis[i]){prime[++tot]=i;}
    	for(int j=1;j<=tot;++j){
    		if(i*prime[j]>1e5)break;
    		vis[i*prime[j]]=1;
    		if(!(i%prime[j]))break;
		}
	}
//	while(--T){
		n=read();opt=2;
		if(n==1){puts("YES");puts("1");return 0;}
		if(opt==1){
			if(n&1)puts("NO");
			else{
				puts("YES");
				printf("%d ",n);
				for(int i=1;i<n-1;i+=2){
					printf("%d %d ",i,n-i-1);
				}
				printf("%d\n",n-1);
			}
		}
		else{
			if(n==4){puts("YES");puts("1 3 2 4");}
			else{
				if(vis[n])puts("NO");
				else{
					puts("YES");inv[1]=1;
					for(int i=2;i<n;++i){
						inv[i]=n-1ll*(n/i)*inv[n%i]%n;
					}
					int tmp=1;printf("1 ");
					for(int i=2;i<n;++i){
						tmp=1ll*i%n*inv[i-1]%n;
						printf("%d ",tmp);
					}
					printf("%d\n",n);
				}
			}
		}	
//	}	
	return 0;
}