#include<cstdio>
#include<cstring>
#include<iostream>

#include<cassert>
#include<ctime>

//#pragma GCC optimize(2)
#define mymax(x,y) ((x)>(y)?(x):(y)) 
using namespace std;

typedef long long ll;
const int N=2e5+100,o=400;

int fa[N],a[N],MAX[N];ll bz[N],b[N];

void read(int &x){
	char ch=getchar();x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}

inline void write(int x){
	if (x < 0) x = ~x + 1, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}


double wow=0;

int main()
{
	
	int n,q,he=0;scanf("%d%d",&n,&q);
	
	for(int i=2;i<=n;i++) read(fa[i]);
	
	memset(bz,0,sizeof(bz));
	memset(b,0,sizeof(b));
	
	fa[1]=a[1]=1;fa[0]=a[0]=1;
	for(int i=2;i<=n;i++){
		if(fa[i]>1&&fa[i]>=i/o*o) a[i]=a[fa[i]];
		else a[i]=fa[i];
		MAX[i/o]=mymax(MAX[i/o],fa[i]);
	}
	
	for(int i=1;i<=q;i++){
		int op;read(op);
		if(op==1){
			int l,r,x;
			read(l);read(r);read(x);
			if(l/o==r/o){
				int t=l/o;MAX[t]=0;
				for(int j=t*o;j<(t+1)*o&&j<=n;j++){
					he++;
					fa[j]=mymax(fa[j]+bz[t]-b[j]-(j<=r&&j>=l)*x,1);
					if(fa[j]>=t*o&&fa[j]>1) a[j]=a[fa[j]];
					else a[j]=fa[j];
					b[j]=bz[t];MAX[t]=mymax(MAX[t],fa[j]);
				}
			}
			else{
				int t1=l/o,t2=r/o;MAX[t1]=MAX[t2]=0;
				for(int j=t1*o;j<(t1+1)*o&&j<=n;j++){
					he++;
					fa[j]=mymax(fa[j]+bz[t1]-b[j]-(j>=l)*x,1);
					if(fa[j]>=t1*o&&fa[j]>1) a[j]=a[fa[j]];
					else a[j]=fa[j];
					b[j]=bz[t1];MAX[t1]=mymax(MAX[t1],fa[j]);
				}
				for(int j=t2*o;j<(t2+1)*o&&j<=n;j++){
					he++;
					fa[j]=mymax(fa[j]+bz[t2]-b[j]-(j<=r)*x,1);
					if(fa[j]>=t2*o&&fa[j]>1) a[j]=a[fa[j]];
					else a[j]=fa[j];
					b[j]=bz[t2];MAX[t2]=mymax(MAX[t2],fa[j]);
				}
//				MAX[t1]=MAX[t2]=0;
//				for(int j=t1*o;j<(t1+1)*o;j++) MAX[t1]=mymax(MAX[t1],fa[j]);
//				for(int j=t2*o;j<(t2+1)*o;j++) MAX[t2]=mymax(MAX[t2],fa[j]);
				for(int j=t1+1;j<t2;j++){
					if(MAX[j]>=j*o){
						MAX[j]=0;
						for(int k=j*o;k<(j+1)*o&&k<=n;k++){
							he++;
							fa[k]=mymax(fa[k]+bz[j]-b[k]-x,1);
							if(fa[k]>=j*o&&fa[k]>1) a[k]=a[fa[k]];
							else a[k]=fa[k];
							MAX[j]=mymax(MAX[j],fa[k]);
							b[k]=bz[j];
						}
					}
					else bz[j]-=x;
				}
			}
		}
		else{
			int x,y;
			read(x);read(y);
			while(x!=y){
				while(x/o!=y/o){
					if(x/o<y/o) swap(x,y);
					while(x/o>y/o){
//						he++;
//						wow=clock();
//						if(wow>1300){
//							printf("he%d\n",i);
//							return 0;
//						}
						fa[x]=mymax(fa[x]+bz[x/o]-b[x],1);
						b[x]=bz[x/o];
						if(fa[x]>=x/o*o&&fa[x]>1) a[x]=a[fa[x]];
						else a[x]=fa[x];
						x=a[x];
					}
				}
				fa[x]=mymax(fa[x]+bz[x/o]-b[x],1);b[x]=bz[x/o];
				fa[y]=mymax(fa[y]+bz[y/o]-b[y],1);b[y]=bz[y/o];
				if(fa[x]>=x/o*o&&fa[x]>1) a[x]=a[fa[x]];
				else a[x]=fa[x];
				if(fa[y]>=y/o*o&&fa[y]>1) a[y]=a[fa[y]];
				else a[y]=fa[y];
				if(a[x]==a[y]){
					while(x!=y){
						if(x<y) swap(x,y);
						while(x>y){
//							he++;	
//							wow=clock();
//							if(wow>1300){
//								printf("he%d\n",i);
//								return 0;
//							}
							fa[x]=mymax(fa[x]+bz[x/o]-b[x],1);b[x]=bz[x/o];
							if(fa[x]>=x/o*o&&fa[x]>1) a[x]=a[fa[x]];
							else a[x]=fa[x];
							x=fa[x];
						}
					}
					break;
				}
				else x=a[x],y=a[y];
			}
			write(x);putchar('\n');
		}

	}
	
//	printf("%d\n",he);
//	printf("%.3lf\n",wow);
	
	return 0;
}