#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m=2000;
bitset<2005> f[70005];
int n,K,a[20],dep[20],del[20];
void P(int x,int y,int d){
	if(!x)return ;
	if(y*K<=m&&f[x][y*K])return P(x,y*K,d+1),void();
	for(int i=0;i<n;i++){
		if(!(x&(1<<i)))continue;
		if(y>=a[i]&&f[x-(1<<i)][y-a[i]]){
			dep[i]=d,P(x-(1<<i),y-a[i],d);
			return ;
		}
	}
}
int main(){
	cin>>n>>K;
	for(int i=0;i<n;i++)cin>>a[i];
	f[0][0]=1;
	for(int i=0;i<(1<<n);i++){
		for(int j=m/K*K;j>=0;j-=K)if(f[i][j])f[i][j/K]=1;
		for(int j=0;j<n;j++){
			if(i&(1<<j))continue;
			f[i+(1<<j)]|=f[i]<<a[j];
		}
	}
	if(!f[(1<<n)-1][1])return puts("NO"),0;
	puts("YES");
	P((1<<n)-1,1,0);
	for(int i=1;i<n;i++){
		bool fl=0;
		for(int j=0;j<n&&!fl;j++){
			for(int k=j+1;k<n&&!fl;k++){
				if(dep[j]==dep[k]&&!del[j]&&!del[k]){
					cout<<a[j]<<' '<<a[k]<<'\n';
					del[k]=1,a[j]+=a[k];
					while(a[j]%K==0)a[j]/=K,dep[j]--;
					fl=1;
				}
			}
		}
	}
}