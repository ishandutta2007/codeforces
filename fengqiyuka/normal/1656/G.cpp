#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int N=2e5+100;
int a[N],Cnt[N],qz[N],fa[N],b[N],ID[N];

int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n;scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),Cnt[a[i]]++;
		
		for(int i=1;i<=n;i++){
			if(Cnt[i]%2!=1) qz[i]=qz[i-1]+Cnt[i];
			else qz[i]=qz[i-1];
		}
		
		int all=n;
		for(int i=1;i<=n;i++){
			if(Cnt[a[i]]%2==1){
				if(all%2==0) b[i]=all/2;
				else b[i]=n-all/2;
				all--;
			}
			else{
				if(qz[a[i]]%2==0) b[i]=qz[a[i]]/2;
				else b[i]=n-qz[a[i]]/2;
				qz[a[i]]--;
			}
		}
		
		for(int i=1;i<=n;i++) ID[b[i]]=i;
		
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++){
			int x=find(i),y=find(b[i]);
			if(x!=y) fa[x]=y;
		}
		
		for(int i=1;i<=n/2;i++){
			int x=ID[i],y=ID[n-i+1];
			if(find(x)!=find(y)){
				swap(b[x],b[y]);
				swap(ID[i],ID[n-i+1]);
				fa[find(x)]=find(y);
			}
		}
		
		for(int i=1;i<n/2;i++){
			int x1=ID[i],x2=ID[i+1],x3=ID[n-i+1],x4=ID[n-i];
			if(find(x1)!=find(x2)&&find(x3)!=find(x4)){
				int t=b[x1];
				b[x1]=b[x2];b[x2]=b[x3];b[x3]=b[x4];b[x4]=t;
				ID[b[x1]]=x1;ID[b[x2]]=x2;ID[b[x3]]=x3;ID[b[x4]]=x4;
				fa[find(x2)]=fa[find(x3)]=fa[find(x4)]=find(x1);
			}
		}
		
		bool pd=true;
		if(n%2==1){
			int x=ID[n/2+1];
			int Sum2=0;
			for(int i=1;i<=n;i++)
				if(find(i)==find(x)) Sum2++;
			if(Sum2==1){
				pd=false;
				for(int i=1;i<=n/2;i++){
					int y=ID[i];
					if(a[x]==a[y]){
						pd=true;
						swap(b[x],b[y]);
						swap(ID[n/2+1],ID[i]);
						break;
					}
				}
			}
		}
		
		int Sum=0;
		for(int i=1;i<=n;i++)
			if(Cnt[i]%2==1) Sum++;
		if(Sum>=2) pd=false;
		
		if(!pd) printf("NO\n");
		else{
			printf("YES\n");
			for(int i=1;i<=n;i++) printf("%d ",ID[i]);
			printf("\n");
		}
		
		for(int i=1;i<=n;i++) Cnt[a[i]]--;
	}
	
	return 0;
}