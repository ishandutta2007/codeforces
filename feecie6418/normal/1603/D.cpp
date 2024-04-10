#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353,N=100000;
int tmp[100005];
ll f[20][100005],t[400005],tag[400005];
vector<int> d[100005],g[100005];
ll ans=0;
void Tag(int p,ll z){
	t[p]+=z,tag[p]+=z;
}
void Pushdown(int p){
	if(tag[p])Tag(p*2,tag[p]),Tag(p*2+1,tag[p]),tag[p]=0;
}
void Add(int p,int l,int r,int x,int y,ll z){
	if(x<=l&&r<=y)return Tag(p,z),void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Add(p*2,l,mid,x,y,z);
	if(mid<y)Add(p*2+1,mid+1,r,x,y,z);
	t[p]=min(t[p*2],t[p*2+1]);
}
void Make(int p,int l,int r,int x,ll y){
	if(l==r)return t[p]=y,void();
	Pushdown(p);
	int mid=(l+r)/2;
	if(x<=mid)Make(p*2,l,mid,x,y);
	else Make(p*2+1,mid+1,r,x,y);
	t[p]=min(t[p*2],t[p*2+1]);
}
inline char get_char(){
    static char buf[1000001],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;
}
 
inline int read(void){
    char ch;int x=0;
    do{ch=get_char();}while(ch<'0'||'9'<ch);
    while('0'<=ch&&ch<='9'){x=10*x+ch-'0';ch=get_char();}
    return x;
}
int main(){
	for(int i=1;i<=N;i++)for(int j=i;j<=N;j+=i)d[j].push_back(i);
	for(int i=1;i<=N;i++){
		g[i].resize(d[i].size());
		for(int j=d[i].size()-1;j>=0;j--){
			int ans=i/d[i][j];
			for(int k:d[i/d[i][j]])if(k>1)ans-=tmp[d[i][j]*k];
			g[i][j]=ans,tmp[d[i][j]]=ans;
		}
		for(int j:d[i])tmp[j]=0;
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=N;i++)f[1][i]=1ll*i*(i+1)/2;
	for(int j=2;j<=16;j++){
		memset(t,0x3f,sizeof(t)),memset(tag,0,sizeof(tag));
		for(int i=1;i<=N;i++){
			Make(1,1,N,i,f[j-1][i-1]);
			for(int k=0;k<d[i].size();k++){
				Add(1,1,N,1,d[i][k],g[i][k]);
			}
			f[j][i]=t[1];
		}
	}
	int t=read();
	while(t--){
		int n=read(),k=read();
		if(k>=17)cout<<n<<'\n';
		else cout<<f[k][n]<<'\n';
	}
}