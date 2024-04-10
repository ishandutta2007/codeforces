#include<bits/stdc++.h>
using namespace std;
#define N 500500
typedef long long ll;
typedef pair<int,int> pii;
int n,m,K,p1[N],p2[N],z1[N],z2[N];
char s[N],t[N];
void Z(char *s,int n,int *z){
	z[1]=n;
	for(int i=2,l=1,r=0;i<=n;++i){
		if(r>=i)z[i]=min(r-i+1,z[i-l+1]);
		else z[i]=0;
		while(i+z[i]<=n&&s[i+z[i]]==s[z[i]+1])++z[i];
		if(i+z[i]-1>r){
			l=i,r=i+z[i]-1;
		}
	}
}
void exkmp(char *s,char *t,int n,int m,int *p){
	static int z[N];
	Z(t,m,z);
	for(int i=1,l=0,r=0;i<=n;++i){
		if(r>=i)p[i]=min(r-i+1,z[i-l+1]);
		while(i+p[i]<=n&&s[i+p[i]]==t[p[i]+1])++p[i];
		if(i+p[i]-1>r){
			l=i,r=i+p[i]-1;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>K;
	cin>>(s+1)>>(t+1);
	exkmp(s,t,n,m,p1);
	reverse(s+1,s+n+1);
	reverse(t+1,t+m+1);
	exkmp(s,t,n,m,p2);
	for(int i=1;i<=n;++i){
		p1[i]=min(p1[i],K);
		p2[i]=min(p2[i],K);
	}
	for(int i=1;i<=n;++i){
		int h=max(1,i+m-K);
		if(p1[i]>=m&&h+K+K-1<=n){
			cout<<"Yes\n"<<h<<" "<<h+K<<'\n';
			return 0;
		}
		if(p2[i]>=m&&h+K+K-1<=n){
			cout<<"Yes\n"<<n-(h+K)+1-K+1<<" "<<n-h+1-K+1<<'\n';
			return 0;	
		}
	}
	reverse(p2+1,p2+n+1);
	pii mx(-1,-1);
	for(int j=m;j<=n;++j){
		int i=j-m+1;
		if(i+p1[i]-K>=1)mx=max(mx,make_pair(p1[i],i));
		if(p2[j]+mx.first>=m){
			int k1=max(1,mx.second+(m-p2[j])-K);
			int len=k1+K-mx.second;
			int k2=max(k1+K,j-(m-len)+1);
			if(k2+K-1<=n){
				cout<<"Yes\n"<<k1<<" "<<k2<<'\n';
				return 0;
			}
		}
	}
	cout<<"No\n";
	return 0;
}