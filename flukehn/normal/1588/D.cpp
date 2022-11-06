#include<bits/stdc++.h>
using namespace std;
const int N=111;
char s[N],t[N];
int p[N];
int a[52][11][2];
int n;
void setv(int *f,int j){
	f[f[0]!=-1]=j;	
}
int cal(char c){
	return c>='A'&&c<='Z'?c-'A':c-'a'+26;
}
using E=pair<int,int>;
int f[N][1<<9],gg[N][1<<9];
E g[N][1<<9];
void work(){
	memset(a,-1,sizeof a);
	memset(f,0,sizeof f);
	for(int i=0;i<N;++i)for(int j=0;j<(1<<9);++j)gg[i][j]=j;
	for(int i=0;i<N;++i)for(int j=0;j<(1<<9);++j)g[i][j]=E(-1,-1);
	cin>>n>>t;
	--n;
	for(int i=0;i<n;++i){
		cin>>s;
		for(int j=0;s[j];++j){
			setv(a[cal(s[j])][i],j);
		}
	}
	int m=strlen(t);
	for(int i=0;i<m;++i)p[i]=cal(t[i]);
	int ans=0;
	E o(-1,-1);
	for(int i=0;i<m;++i){
		for(int w=0;w<(1<<n);++w){
			int j;
			int r[10];
			for(j=0;j<n;++j)
				if((r[j]=a[p[i]][j][w>>j&1])<0)break;
			if(j<n)continue;
			int tmp=0;
			for(int k=i-1;k>=0;--k){
				int tot=0;
				for(j=n-1;j>=0;--j)
					if(r[j]<=a[p[k]][j][0])break;
					else tot=tot*2+(r[j]>a[p[k]][j][1]);
				
				if(j>=0)continue;
				int u=gg[k][tot];
				if(f[k][u]>tmp){
					tmp=f[k][u];
					g[i][w]=E(k,u);
				}
				/*for(int u=tot;;u=(u-1)&tot){
					if(f[k][u]>tmp){
						tmp=f[k][u];
						g[i][w]=E(k,u);
					}
					if(!u)break;
				}*/
			}
			//cout<<i<<" "<<w<<" "<<tmp+1<<endl;
			f[i][w]=tmp+1;
			if(f[i][w]>ans){
				ans=f[i][w];
				o=E(i,w);
			}
		}
		for(int w=0;w<(1<<n);++w){
			for(int j=0;j<n;++j) {
				int &o=gg[i][w|(1<<j)],t=gg[i][w];
				if(f[i][o]<f[i][t])o=t;
			}
		}
	}
	cout<<ans<<"\n";
	string str="";
	while(~o.first)str+=t[o.first],o=g[o.first][o.second];
	reverse(str.begin(),str.end());
	cout<<str<<"\n";
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int t;
	cin>>t;
	while(t--)work();
}