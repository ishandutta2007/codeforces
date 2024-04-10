#include<stdio.h>
#include<vector>
#include<algorithm>
int n,m;
long long int powt[100100];
int edge[100100][3];
std::vector<int> el[100100];
std::vector<long long int> ed[100100];
int chk[100100];
long long int ans;
int sn[100100];
std::vector<int> v1,v2,v3,v4;
void dfs(int x){
	int i;
	chk[x]=1;
	sn[x]=1;
	for(i=0;i<el[x].size();i++){
		if(chk[el[x][i]]==0){
			dfs(el[x][i]);
			sn[x]+=sn[el[x][i]];
		}
	}
}
int fcent(int x,int d){
	int i,cnt;
	chk[x]=2;
	for(i=0;i<el[x].size();i++){
		if(chk[el[x][i]]<2){
			cnt=fcent(el[x][i],d);
			if(cnt!=-1)return cnt;
		}
	}
	if(sn[x]>d)return x;
	return -1;
}
void tdfs(int x,int d,int dep,std::vector<int>& v){
	int i;
	chk[x]=3;
	v.push_back(d*powt[n]%m);
	for(i=0;i<el[x].size();i++){
		if(chk[el[x][i]]<3){
			tdfs(el[x][i],(ed[x][i]*powt[dep]+d)%m,dep+1,v);
		}
	}
}
void zdfs(int x){
	int i;
	chk[x]=0;
	sn[x]=-1;
	for(i=0;i<el[x].size();i++){
		if(chk[el[x][i]]<5&&sn[el[x][i]]!=-1){
			zdfs(el[x][i]);
		}
	}
}
long long gans(std::vector<int>&v,std::vector<int>&w){
	int i,j,k,cnt;
	std::sort(w.begin(),w.end());
	long long int res=0;
	i=0;
	j=0;
	while(i<v.size()&&j<w.size()){
		if(v[i]==w[j]){
			k=i;
			while(k<v.size()&&v[k]==v[i])k++;
			cnt=k-i;
			k=j;
			while(k<w.size()&&w[k]==v[i]){
				k++;
				res+=cnt;
			}
			j=k;
		}
		else if(v[i]<w[j])i++;
		else j++;
	}
	return res;
}
void fans(int ex,int z){
	long long int s=m-z%m;
	s%=m;
	s*=powt[ex];
	s%=m;
	v3.push_back(s);
	v4.push_back(s);
}
void qdfs(int x,int dep,int d){
	int i;
	fans(dep,d);
	chk[x]=4;
	for(i=0;i<el[x].size();i++){
		if(chk[el[x][i]]<4){
			qdfs(el[x][i],dep-1,(d*10LL+ed[x][i])%m);
		}
	}
}
void sdfs(int x){
	int i,j;
	dfs(x);
	int pn=sn[x];
	x=fcent(x,sn[x]/2);
	chk[x]=5;
	v1.clear();
	v3.clear();
	v1.push_back(0);
	for(i=0;i<el[x].size();i++){
		if(chk[el[x][i]]<5)tdfs(el[x][i],ed[x][i],1,v1);
	}
	std::sort(v1.begin(),v1.end());
	zdfs(x);
	dfs(x);
	chk[x]=5;
	for(i=0;i<el[x].size();i++){
		if(chk[el[x][i]]<5){
			v2.clear();
			v4.clear();
			tdfs(el[x][i],ed[x][i],1,v2);
			std::sort(v2.begin(),v2.end());
			qdfs(el[x][i],n-1,ed[x][i]);
			ans-=gans(v2,v4);
		}
	}
	v2.clear();
	v4.clear();
	v2.push_back(0);
	fans(n,0);
	ans-=gans(v2,v4);
	ans+=gans(v1,v3);
	v3.clear();
	v1.clear();
	zdfs(x);
	chk[x]=5;
	for(i=0;i<el[x].size();i++){
		if(chk[el[x][i]]<5){
			sdfs(el[x][i]);
		}
	}
}
int main(){
	int i;
	scanf("%d%d",&n,&m);
	for(i=0;i<n-1;i++){
		scanf("%d%d%d",&edge[i][0],&edge[i][1],&edge[i][2]);
		el[edge[i][0]].push_back(edge[i][1]);
		ed[edge[i][0]].push_back(edge[i][2]);
		el[edge[i][1]].push_back(edge[i][0]);
		ed[edge[i][1]].push_back(edge[i][2]);
	}
	powt[0]=1;
	for(i=0;i<n+5;i++){
		powt[i+1]=powt[i]*10%m;
	}
	ans=0;
	sdfs(0);
	printf("%I64d",ans);
	return 0;
}