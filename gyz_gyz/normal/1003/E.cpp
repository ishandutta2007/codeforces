#include<cstdio>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define abs(x) ((x)<0?-(x):(x))
#define N 1048576
#define ll long long
#define inf 1000000000
using namespace std;
int n,d,k,s,t,jj;ll q,w;
int main(){
	scanf("%d%d%d",&n,&d,&k);
	if(d&1){q=2;w=2;
		rep(i,1,(d-1)/2){
			w*=(k-1),q+=w;
			if(q>=n)break;
		}
		if((q<n)||(d>=n))printf("NO");else{
			printf("YES\n");
			if(n>1)printf("1 2\n");s=1;t=3;
			rep(i,1,(d-1)/2){
				rep(j,0,1ll*(t-s)*(k-1)-1){
					printf("%d %d\n",j/(k-1)+s,j+t);
					if(j+t+d-1-i*2+(1ll*j<(t-s)*(k-1)/2)==n){
						if(j+t<n){
							if(j<1ll*(t-s)*(k-1)/2){j++;
								printf("%d %d\n",s+(t-s)/2,j+t);
							}else{j++;printf("%d %d\n",t,j+t);}
						}
						for(t+=j+1;t<=n;t++)printf("%d %d\n",t-2,t);exit(0);
					}jj=j;
				}
				s=t;t+=jj+1;
			}
		}
	}else{q=k+1;w=k;
		rep(i,1,d/2-1){
			w*=(k-1),q+=w;
			if(q>=n)break;
		}
		if((q<n)||(d>=n))printf("NO");else{
			printf("YES\n");s=1;t=2; 
			rep(i,1,d/2){
				rep(j,0,1ll*(t-s)*(k-1+(i==1))-1){
					printf("%d %d\n",j/(k-1+(i==1))+s,j+t);
					if(j+t+d-i*2+(j<1ll*(t-s)*(k-1+(i==1))/k)==n){
						if(j+t<n){
							if(j<1ll*(t-s)*(k-1+(i==1))/k){j++;
								printf("%d %d\n",s+(t-s)/k,j+t);
							}else{j++;printf("%d %d\n",t,j+t);}
						}
						for(t+=j+1;t<=n;t++)printf("%d %d\n",t-2,t);exit(0);
					}jj=j;
				}
				s=t;t+=jj+1;
			}
		}
	}
}