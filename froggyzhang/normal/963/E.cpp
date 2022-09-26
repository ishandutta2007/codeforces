#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<iomanip>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int R,id[123][123],n,band;
ll p1,p2,p3,p4,sum;
int g[7846][7846],ans[7846];
#define ID(x,y) id[x+50][y+50]
vector<pair<int,int> > pos;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
inline int Abs(int x){
	return x>=0?x:-x;
}
void Guass(int n,int band){
	for(int i=1;i<=n;++i){
		if(!g[i][i]){
			for(int j=i+1;j<=min(n,i+band);++j){
				if(g[j][i]){
					swap(g[i],g[j]);
					break;
				}
			}
		}
		if(!g[i][i])continue;
		ll Inv=qpow(g[i][i],mod-2);
		for(int j=i+1;j<=min(i+band,n);++j){
			ll div=g[j][i]*Inv%mod;
			for(int k=i;k<=min(i+2*band,n);++k){
				g[j][k]=(g[j][k]-div*g[i][k]%mod+mod)%mod;
			}
			g[j][n+1]=(g[j][n+1]-div*g[i][n+1]%mod+mod)%mod;
		}
	}
	for(int i=n;i>=1;--i){
		ans[i]=g[i][n+1];
		for(int j=i+1;j<=min(i+2*band,n);++j){
			ans[i]=(ans[i]-1LL*g[i][j]*ans[j]%mod+mod)%mod;
		}
		ans[i]=ans[i]*qpow(g[i][i],mod-2)%mod;
	}
}
int main(){
	R=read(),p1=read(),p2=read(),p3=read(),p4=read();
	sum=p1+p2+p3+p4;
	sum=qpow(sum,mod-2);
	p1=p1*sum%mod,p2=p2*sum%mod,p3=p3*sum%mod,p4=p4*sum%mod;
	for(int i=-R;i<=R;++i){
		for(int j=-R;j<=R;++j){
			if(i*i+j*j>R*R)continue;
			pos.push_back(make_pair(i,j));
			ID(i,j)=pos.size();
		} 
	}
	n=pos.size();
	band=1;
	for(auto u:pos){
		int x=u.first,y=u.second;
		g[ID(x,y)][ID(x,y)]=1;
		g[ID(x,y)][n+1]=1;
		if(ID(x-1,y))g[ID(x,y)][ID(x-1,y)]=mod-p1,band=max(band,Abs(ID(x,y)-ID(x-1,y)));
		if(ID(x,y-1))g[ID(x,y)][ID(x,y-1)]=mod-p2,band=max(band,Abs(ID(x,y)-ID(x,y-1)));
		if(ID(x+1,y))g[ID(x,y)][ID(x+1,y)]=mod-p3,band=max(band,Abs(ID(x,y)-ID(x+1,y)));
		if(ID(x,y+1))g[ID(x,y)][ID(x,y+1)]=mod-p4,band=max(band,Abs(ID(x,y)-ID(x,y+1)));
	}
	Guass(n,band);
	printf("%d\n",ans[ID(0,0)]);
	return 0;
}