#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=8000;
int f[222];
int n,x,y,z;
vector<bool>b[N];
int in[N];
vector<int>p,q;
int inp[N],inq[N];
pair<int,int>stp[N],stq[N];
int szp,szq;
int main(){//this generator will explode if x=n or x<y+z or y=0
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=0; i<n ;i++) b[i].resize(n);
	for(int i=48; i<58 ;i++) f[i]=i-48;
	for(int i=65; i<=70 ;i++) f[i]=i-55;
	for(int i=0; i<n ;i++){
		for(int j=0; j<n ;j+=4){
			char c;cin >> c;
			int z=f[c];
			for(int k=0; k<4 ;k++){
			    b[i][j+k]=(z&(1<<(3-k)))!=0;
			    in[i]+=b[i][j+k];
			}
		}
	}
	for(int i=0; i<n ;i++) in[i]=n-1-in[i];
	int x=0;
	{
		for(int i=0; i<n ;i++){
			if(in[i]>in[x]) x=i;
		}
		p.push_back(x);
		for(int i=0; i<n ;i++){
			if(b[i][x]) p.push_back(i);
			else if(i!=x) q.push_back(i);
		}
		szp=p.size();szq=q.size();
	}
	{
		for(int i=0; i<n ;i++){
			for(auto x:p){
				if(b[x][i]) inp[i]++;
			}
			for(auto x:q){
				if(b[x][i]) inq[i]++;
			}
		}
		int ptr=0;
		for(auto x:p) stp[ptr++]={inp[x],x};
		sort(stp,stp+szp);
		ptr=0;
		for(auto x:q) stq[ptr++]={inq[x],x};
		sort(stq,stq+szq);
	}
	int y=0;
	while(y<szp && inq[stp[y].se]==0) y++;
	if(y==szp){
		cout << 1LL*(614*n+1)*n*(n-1)/2 << '\n';
		return 0;
	}
	ll ans=0;
	for(int i=n; i>n-y ;i--) ans+=1LL*(614*n+1)*(i-1);
	for(int i=0; i<szp-y ;i++) stp[i]=stp[i+y];
	for(int i=0; i<szq ;i++) inq[stq[i].se]-=y;
	szp-=y;
	{//P->P
		int e=0,f=0,g=-1;
		for(int i=0; i<szp ;i++){
			if(g!=inq[stp[i].se]) f=0;
			e+=f++;
			g=inq[stp[i].se];
		}
		ans+=1LL*szp*(szp-1)/2;//dist = 1
		ans+=2LL*(szp*(szp-1)/2-e);//dist = 2
		ans+=3LL*(e);//dist=3
	}
	{//P->Q and Q->P
		ans+=3LL*szp*szq;
	}
	{//Q->Q
		int e=0,f=0,g=-1;
		for(int i=0; i<szq ;i++){
			if(g!=inp[stq[i].se]) f=0;
			e+=f++;
			g=inp[stq[i].se];
		}
		ans+=1LL*szq*(szq-1)/2;//dist = 1
		ans+=2LL*(szq*(szq-1)/2-e);//dist = 2
		ans+=3LL*(e);//dist=3
	}
	cout << ans << '\n';
}