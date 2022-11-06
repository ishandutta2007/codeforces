#include<bits/stdc++.h>
using namespace std;

int F[105][81][1<<6],id[5][5],f[5],d[5],_[5],n;
void up(int &x,int y){if (y>x) x=y;}
int get(int u){return f[u]==u?u:f[u]=get(f[u]);}
int main(){
	scanf("%d",&n);
	for (int i=0;i<=n;i++)
		for (int S=0;S<81;S++)
			for (int E=0;E<(1<<6);E++)
				F[i][S][E]=-1e9;
	int S=0;
	for (int i=0;i<4;i++)
		S=S*3+2;
	F[0][S][0]=0;
	int tot=0;
	for (int i=0;i<4;i++)
		for (int j=i+1;j<4;j++)
			id[i][j]=(1<<tot++);
	for (int t=1;t<=n;t++){
		int p,val,q;
		scanf("%d%d%d",&p,&val,&q);
		--p;--q;if (p>q) swap(p,q);
		for (int S=0;S<81;S++){
			for (int i=0,cur=S;i<4;i++)
				d[i]=cur%3,cur/=3;
			for (int E=0;E<(1<<6);E++)
				if (F[t-1][S][E]>=0){
					up(F[t][S][E],F[t-1][S][E]);
					for (int i=0;i<4;i++) _[i]=d[i];
					if (_[p]==2) _[p]=1;else _[p]^=1;
					if (_[q]==2) _[q]=1;else _[q]^=1;
					int newS=0;
					for (int i=3;i>=0;i--)
						newS=newS*3+_[i];
					up(F[t][newS][E|id[p][q]],F[t-1][S][E]+val);
				}
		}
	}
	int ans=0;
	for (int S=0;S<81;S++){
		int sum[3]={0,0,0};
		for (int i=0,cur=S;i<4;i++)
			sum[d[i]=cur%3]++,cur/=3;
		if (sum[1]!=2&&sum[1]!=0) continue;
		for (int E=0;E<(1<<6);E++)
			if (F[n][S][E]>ans){
				for (int i=0;i<4;i++) f[i]=i;
				int tot=0;
				for (int i=0;i<4;i++)
					for (int j=i+1;j<4;j++)
						if ((E>>tot++)&1) f[get(i)]=get(j);
				int rt=-1;
				for (int i=0;i<4;i++)
					if (d[i]!=2) rt=get(i);
				int ok=1;
				for (int i=0;i<4;i++)
					ok&=d[i]==2||get(i)==get(rt);
				if (ok) ans=F[n][S][E];
			}
	}
	printf("%d\n",ans);
}