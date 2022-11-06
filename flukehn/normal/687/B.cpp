#include<bits/stdc++.h>
using namespace std;

const int N=1e6+11;

char np[N];
int p[N],tot,mn[N];
void Init(){
	for(int i=2;i<N;++i){
		if(!np[i])p[++tot]=i,mn[i]=i;
		for(int j=1,k;j<=tot&&(k=i*p[j])<N;++j){
			np[k]=1;
			mn[k]=mn[i];
			if(p[j]==mn[i])break;
		}
	}
}

int n,k;
int a[20],b[20],cnt;
int d[20];
int main(){
#ifdef flukehn
	freopen(".in","r",stdin);
#endif
	Init();
	//for(int i=1;i<=20;++i)cout<<i<<" "<<mn[i]<<endl;
	//cout<<"ok\n";
	scanf("%d%d",&n,&k);
	for(;k>1;){
		int x=mn[k];
		a[++cnt]=x;
		for(;k%x==0;k/=x)++b[cnt];
	}
	//cout<<"ok\n";
	for(int i=1;i<=n;++i){
		int x;
		scanf("%d",&x);
		for(;x>1;){
			int y=mn[x];
			int z=0;
			for(;x%y==0;x/=y)++z;
			for(int j=1;j<=cnt;++j)if(a[j]==y){
				d[j]|= (z>=b[j]);
			}
			//cout<<y<<" "<<z<<endl;
		}
	}
	int ans=1;
	for(int i=1;i<=cnt;++i)ans&=d[i];
	puts(ans?"Yes":"No");
}