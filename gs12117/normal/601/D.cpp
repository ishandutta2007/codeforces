#include<stdio.h>
#include<algorithm>
int n;
int c[300100];
char str[300100];
int s[300100];
int edge[300100][2];
int en[300100];
int elist[600100];
int q[300100];
int qs,qe;
int chk[300100];
int dist[300100];
int prt[300100];
struct st{
	int val,loc;
	bool operator<(const st&r)const{
		return val<r.val;
	}
};
st a[300100];
int strn[300100];
int strd[300100][30];
int nres[300100];
int sx[300100];
int ans;
int ansn;
void sset(int x){
	int y,z,t,i,d;
	d=0;
	y=prt[x];
	z=strd[y][s[x]];
	if(z==-1){
		strd[y][s[x]]=x;
		return;
	}
	if(strn[z]<strn[x]){
		strd[y][s[x]]=x;
		t=x;
		x=z;
		z=t;
	}
	for(i=0;i<26;i++){
		if(strd[x][i]==-1)continue;
		if(strd[z][i]==-1){
			strd[z][i]=strd[x][i];
			continue;
		}
		prt[strd[x][i]]=z;
		sset(strd[x][i]);
	}
	strn[z]=1;
	for(i=0;i<26;i++){
		if(strd[z][i]!=-1)strn[z]+=strn[strd[z][i]];
	}
}
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	scanf("%s",str);
	for(i=0;i<n;i++){
		s[i+1]=str[i]-'a';
	}
	for(i=0;i<n-1;i++){
		scanf("%d%d",&edge[i][0],&edge[i][1]);
		en[edge[i][0]+2]++;
		en[edge[i][1]+2]++;
	}
	for(i=0;i<n+7;i++){
		en[i+1]+=en[i];
	}
	for(i=0;i<n-1;i++){
		elist[en[edge[i][0]+1]]=edge[i][1];
		en[edge[i][0]+1]++;
		elist[en[edge[i][1]+1]]=edge[i][0];
		en[edge[i][1]+1]++;
	}
	qs=0;
	qe=1;
	q[0]=1;
	chk[1]=1;
	dist[1]=0;
	while(qs<qe){
		for(i=en[q[qs]];i<en[q[qs]+1];i++){
			if(chk[elist[i]]==0){
				chk[elist[i]]=1;
				q[qe]=elist[i];
				dist[elist[i]]=dist[q[qs]]+1;
				prt[elist[i]]=q[qs];
				qe++;
			}
		}
		qs++;
	}
	for(i=0;i<n;i++){
		a[i].loc=i+1;
		a[i].val=dist[i+1];
	}
	std::sort(a,a+n);
	for(i=1;i<=n;i++){
		for(j=0;j<26;j++){
			strd[i][j]=-1;
		}
	}
	for(i=n-1;i>=0;i--){
		j=a[i].loc;
		strn[j]=1;
		for(k=0;k<26;k++){
			if(strd[j][k]!=-1)strn[j]+=strn[strd[j][k]];
		}
		nres[j]=strn[j]+c[j];
		if(i==0)break;
		sset(j);
	}
	ans=-1;
	for(i=1;i<=n;i++){
		if(nres[i]>ans)ans=nres[i];
	}
	ansn=0;
	for(i=1;i<=n;i++){
		if(nres[i]==ans)ansn++;
	}
	printf("%d\n",ans);
	printf("%d",ansn);
}