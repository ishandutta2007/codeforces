#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int M=4000037,B=67;
char s[8][6];
int a[20][3],hea[M],nxt[M],P[20],tot,n;
ull to[M];
double f[M];
ull Hash() {
	for(int i=1;i<=n;i++) {
		P[i]=0;
		if(i<n&&(!a[i][1]||(!a[i][0]&&!a[i][2])))continue;
		int FL=0;
		if(a[i][0]>a[i][2])swap(a[i][0],a[i][2]),FL=1;
		for(int j=0;j<3;j++)
			P[i]|=a[i][j]<<(2*j);
		if(FL)swap(a[i][0],a[i][2]);
	}
	sort(P+1,P+n);
	ull H=0;
	for(int i=1;i<=n;i++)
		if(P[i])H=H*B+P[i];
	return H;
}
int find(ull H) {
	int x=H%M;
	for(int i=hea[x];i;i=nxt[i])
		if(to[i]==H)return i;
	nxt[++tot]=hea[x];
	hea[x]=tot;
	to[tot]=H;
	f[tot]=-2;
	return tot;
}
double dfs(ull H);
void updata(double &P,double &Q,int col) {
	double p=1.0/6,Min=1e9;
	if(col!=1)p*=2;
	for(int i=1;i<n;i++)
		for(int j=0;j<3;j++) {
			if(a[i][j]==col) {
				if(j==1&&(!a[i][0]||!a[i][2]))continue;
				if((j==0||j==2)&&!a[i][1])continue;
				a[i][j]=0;
				int FL=0;
				if(a[n][0]&&a[n][1]&&a[n][2])n++,FL++;
				for(int k=0;k<3;k++)
					if(!a[n][k]) {
						a[n][k]=col;
						Min=min(Min,dfs(Hash())+1);
						a[n][k]=0;
					}
				a[i][j]=col;
				n-=FL;
			}
		}
	if(Min>1e8)P+=p;
	else Q+=Min*p;
}
double dfs(ull H) {
	int x=find(H);
	if(f[x]>-1)return f[x];
	double P=1.0/6,Q=0;
	updata(P,Q,1);
	updata(P,Q,2);
	updata(P,Q,3);
	if((1-P)<1e-6)return f[x]=0;
	f[x]=(P+Q)/(1-P);
	return f[x];
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s",s[i]);
		for(int j=0;j<3;j++)
			a[i][j]=(s[i][j]=='R'?1:(s[i][j]=='G'?2:3));
		if(a[i][0]>a[i][2])swap(a[i][0],a[i][2]);
	}
	printf("%.9f\n",dfs(Hash()));
	return 0;
}