#include<bits/stdc++.h>
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
char _s[12][105];int s[12][105],pos[12][52][2],len[12];typedef std::pair<int,int> pi;
int dp[105][1<<10];pi pre[105][1<<10];
inline int getid(char c){return c>='a'?c-'a':c-'A'+26;}
void MAIN(){
	int n;read(n);
	for(int i=0;i<n;++i){
		scanf("%s",_s[i]),len[i]=strlen(_s[i]);
		for(int j=0;j<len[i];++j)s[i][j]=getid(_s[i][j]);
		for(int j=0;j<52;++j)pos[i][j][0]=pos[i][j][1]=len[i];
		for(int j=0;j<len[i];++j)(pos[i][s[i][j]][0]<len[i]?pos[i][s[i][j]][1]:pos[i][s[i][j]][0])=j;
	}
	memset(dp,-63,sizeof(dp));
	for(int i=0;i<len[0];++i){
		int tmp=s[0][i];bool flag=1;
		for(int j=0;j<n;++j)if(pos[j][tmp][0]>=len[j])flag=0;
		if(flag)dp[i][i==pos[0][tmp][1]]=1;
	}
	for(int i=1;i<len[0];++i){
		for(int j=0;j<i;++j){
			for(int st=0;st<1<<n;++st)if(dp[j][st]>=0){
				bool flag=1;int to=0;
				for(int k=0;k<n;++k){
					int p=pos[k][s[0][j]][st>>k&1],cur=len[k];
					if(pos[k][s[0][i]][0]>p)cur=pos[k][s[0][i]][0];else if(pos[k][s[0][i]][1]>p)cur=pos[k][s[0][i]][1],to|=1<<k;
					if(cur>=len[k]){flag=0;break;}
				}
				if(flag){
					if(dp[j][st]+1>dp[i][to])dp[i][to]=dp[j][st]+1,pre[i][to]={j,st};
				}
			}
		}
	}
	int ans=0,I=-1,J=-1;for(int i=0;i<len[0];++i)for(int j=0;j<1<<n;++j)if(dp[i][j]>ans)ans=dp[i][j],I=i,J=j;
	printf("%d\n",ans);
	std::string res;
	for(int k=0;k<ans;++k){
		res.push_back(_s[0][I]);
		pi tmp=pre[I][J];
		I=tmp.first,J=tmp.second;
	}
	std::reverse(res.begin(),res.end());
	printf("%s\n",res.c_str());
}
int main(){
	int _;read(_);
	while(_--)MAIN();
	return 0;
}