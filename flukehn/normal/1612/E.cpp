#include<bits/stdc++.h>
using namespace std;
const int N=2e5+11;
vector<int> ans;
int ansx,ansy=1;
vector<int> a[N];
int b[N];
void upd(vector<int> tmp){
	int n=tmp.size();
	if(!n)return;
	int sum=0;
	for(int x:tmp){
		for(int y:a[x]){
			sum+=min(y,n);
		}
	}
	if ((long long)sum*ansy>(long long)ansx*n){
		ansx=sum;
		ansy=n;
		ans=tmp;
	}
}
int n;
int m[N],k[N];
int f[N][22],p[N][22];

int g[N];
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>m[i]>>k[i];
		a[m[i]].push_back(k[i]);
		b[m[i]]+=k[i];
	}
	for(int i=1;i<=20;++i){
		memset(f,0,sizeof f);
		memset(g,0,sizeof g);
		for(int x=1;x<N;++x){
			int tot=0;
			for(int y:a[x])tot+=min(i,y);
			//if(x<=30)cerr<<x<<" "<<tot<<endl;
			for(int j=1;j<=i;++j){
				if(f[x-1][j]>f[x-1][j-1]+tot){
					f[x][j]=f[x-1][j];
					p[x][j]=0;
				}else{
					f[x][j]=f[x-1][j-1]+tot;
					p[x][j]=1;
				}
			}
		}
		//cerr<<f[N-1][i]<<endl;
		vector<int> tmp;
		int x=N-1,y=i;
		for(;x>=1&&y;--x)
			if(p[x][y])tmp.push_back(x),--y;
		upd(tmp);
		//cerr<<i<<": ";for(int y:tmp)cerr<<y<<" ";cerr<<endl;
	}
	for(int i=0;i<N;++i) g[i]=i;
	sort(g+1,g+N,[](int i,int j){return b[i]>b[j];});
	int u=ansx,v=ansy;
	vector<int> tmp;
	int tot=0,w=0;
	for(int i=1;i<N;++i){
		int x=g[i];
		if(!b[x])break;
		//tmp.push_back(x);
		tot+=b[x];
		//cerr<<i<<" "<<(double)tot/i<<" "<<(double)ansx/ansy<<endl;
		if(i>=20){
			if(1ll*tot*v>1ll*u*i){
				u=tot;
				v=i;
				w=i;
			}
		}
	}
	for(int i=1;i<=w;++i)tmp.push_back(g[i]);
	
	upd(tmp);
	//cerr<<tmp.size()<<" "<<(double)ansx/ansy<<endl;
	/*int l=1,r=n;
	while(l<r){
		int m=(l+r+1)/2;
		vector<int> tmp;
		for(int i=0;i<N;++i)if(b[i]>=m)tmp.push_back(i);
		upd(tmp);
		if(tmp.size()>=20)l=m;
		else r=m-1;
	}
	vector<int> tmp;
	for(int i=0;i<N;++i)if(b[i]>=l)tmp.push_back(i);
	upd(tmp);*/

	sort(ans.begin(),ans.end());
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();++i)cout<<ans[i]<<" \n"[i+1==ans.size()];
}