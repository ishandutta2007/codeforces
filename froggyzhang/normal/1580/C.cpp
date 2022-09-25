#include<bits/stdc++.h>
using namespace std;
#define N 200020
#define M 505
const int B=400;
typedef long long ll;
int n,m,a[N],b[N],s[N],c[M][M],t[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>b[i];
	}
	for(int i=1,now=0,tot=0;i<=m;++i){
		int opt,k;
		cin>>opt>>k;
		tot+=opt==1?1:-1;
		int w=t[k]?-1:1;
		int pos=t[k]?t[k]:i;
		t[k]=t[k]?0:i;
		int len=a[k]+b[k];
		if(len<=B){
			for(int j=pos%len,z=0;z<a[k];++z,j=(j+1)%len){
				c[len][j]+=w;	
			}	
		}
		else{
			for(int j=pos;j<=m;j+=len){
				if(pos^i&&i>j&&i<=j+a[k])--now;
				s[j]+=w,s[min(m+1,j+a[k])]-=w;	
			}
		}
		now+=s[i];
		int ans=now;
		for(int j=2;j<=B;++j){
			ans+=c[j][i%j];
		}
		cout<<tot-ans<<'\n';
	}
	return 0;
}