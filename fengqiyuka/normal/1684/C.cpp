#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
vector<int> a[N];
int b[N];bool bk[N];

bool cmp(int n1,int n2) {return (n1<n2);}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) a[i].resize(m+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
		
		bool pd=true;int las1=-1,las2=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) b[j]=a[i][j];
			sort(b+1,b+m+1,cmp);
			int Sum=0,t1=-1,t2=-1;
			for(int j=1;j<=m;j++)
				if(b[j]!=a[i][j]){
					Sum++;
					if(Sum>2) {pd=false;break;}
					if(t1==-1) t1=j;
					else t2=j;
				}
			if(!pd) break;
			if(Sum==2){
				if(las1==-1) las1=t1,las2=t2;
				else if(las1!=t1||las2!=t2) {pd=false;break;}
			}
			if(Sum==0) bk[i]=true;
			else bk[i]=false;
		}
		if(las1==-1) las1=las2=1;
		for(int i=1;i<=n;i++)
			if(bk[i]){
				if(a[i][las1]!=a[i][las2]) {pd=false;break;}
			}
		
		if(!pd){
			printf("-1\n");
		}
		else{
			printf("%d %d\n",las1,las2);
		}
		
		for(int i=1;i<=n;i++) a[i].clear();
	}
	
	return 0;
}