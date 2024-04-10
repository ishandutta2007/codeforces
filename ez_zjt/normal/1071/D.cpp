#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int L=1000000,MAXK=30,S1=300,S2=10000,S3=1000;

int st1[S1][MAXK],n1;
int maxs;
int st2[S2][MAXK],n2;
int d[S1][S2],d1[S1][S1];
int cur[MAXK];
map<int,int> S;
map<int,int> s1;
int prod[S2],n3;
vector<int> id2[S3];
bool flag[L+1];
int p[L+1],mind[L+1],np;

void dfs(int x,int lim,int s){
	LL temp=1;
	int t0=0;
	while(t0<lim && temp*p[x]*s<=L) t0++,temp*=p[x];
	for(int i=t0;i>=1;i--){
		cur[++cur[0]]=i+1;
		dfs(x+1,i,s*temp);
		cur[cur[0]--]=0;
		temp/=p[x];
	}
	n1++;
	for(int i=0;i<=cur[0];i++) st1[n1][i]=cur[i];
	s1[s]=n1;
}

void dfs2(int lim,int s){
	for(int i=lim;i>=2;i--)
		if(s+i<=31){
			cur[++cur[0]]=i;
			dfs2(i,s+i);
			cur[cur[0]--]=0;
		}
	n2++;
	for(int i=0;i<=cur[0];i++) st2[n2][i]=cur[i];
}

int dis(int x,int y){
	int l1=st1[x][0],l2=st2[y][0];
	int res=0;
	for(int i=1;i<=l1 && i<=l2;i++)
		res+=abs(st1[x][i]-st2[y][i]);
	for(int i=l1+1;i<=l2;i++) res+=st2[y][i]-1;
	for(int i=l2+1;i<=l1;i++) res+=st1[x][i]-1;
	return res;
}

void init(){
	for(int i=2;i<=L;i++){
		if(!flag[i]){
			p[++np]=i;
			mind[i]=i;
		}
		for(int j=1;j<=np && i*p[j]<=L;j++){
			flag[i*p[j]]=1;
			mind[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
	mind[1]=1;
	dfs(1,20,1);
	for(int i=1;i<=n1;i++){
		int temp=0;
		for(int j=1;j<=st1[i][0];j++) temp+=st1[i][j];
		if(temp>maxs) maxs=temp;
	}
	dfs2(31,0);
	for(int i=1;i<=n2;i++){
		prod[i]=1;
		for(int j=1;j<=st2[i][0];j++)
			prod[i]*=st2[i][j];
		if(!S[prod[i]]) S[prod[i]]=++n3;
		prod[i]=S[prod[i]];
		id2[prod[i]].push_back(i);
	}
	for(int i=1;i<=n1;i++)
		for(int j=1;j<=n3;j++){
			d[i][j]=1<<30;
			for(int k=0;k<id2[j].size();k++)
				d[i][j]=min(d[i][j],dis(i,id2[j][k]));
		}
	for(int i=1;i<=n1;i++)
		for(int j=i+1;j<=n1;j++){
			d1[i][j]=1<<30;
			for(int k=1;k<=n3;k++)
				d1[i][j]=min(d1[i][j],d[i][k]+d[j][k]);
		}
}

int getid(int x){
	static vector<int> temp;
	temp.clear();
	while(x!=1){
		int t=mind[x],t1=0;
		while(x%t==0){
			t1++;
			x/=t;
		}
		temp.push_back(t1);
	}
	sort(temp.begin(),temp.end());
	int s=1;
	for(int i=0;i<temp.size();i++)
		for(int j=0;j<temp[i];j++)
			s*=p[temp.size()-i];
	return s1[s];
}

int query(int x,int y){
	x=getid(x); 
	y=getid(y);
	return d1[min(x,y)][max(x,y)];
}

int main(){
#ifdef DEBUG
	freopen("D.in","r",stdin);
#endif
	init();
	int T;
	scanf("%d",&T);
	while(T--){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",query(x,y));
	}
}