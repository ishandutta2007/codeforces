#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define N 3000005
#define pb push_back
#define ll long long
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define db double
#define ls k<<1
#define rs k<<1|1
#define ull unsigned long long
ll mm[5]={998244353,1145141923,1000000007,1000000009,997},M;
ull h[N],cf[N];
vector<ull>f[N];
int n,i,j,k,T,x,y,c,v;
char s[N];
inline ull get(int x,int y){
	if(y<x)return h[y]; 
	return h[x]*f[x][y/x-1]*cf[y%x]+h[y%x];
}
inline bool cmp(int x,int y){
	int l=0,r=k,mid;
	while(l<r){
		mid=r-(r-l>>1);
		if(get(x,mid)^get(y,mid))r=mid-1;
		else l=mid;
	}
	if(s[l%x+1]==s[l%y+1])return x<y;
	return s[l%x+1]<s[l%y+1];
}
int g[N];
int main(){
//	cin>>T;
//	freopen("a.txt","r",stdin);
	srand(time(NULL));
//	while(T--){
		scanf("%d%d%s",&n,&k,s+1);
		M=mm[rand()%5];
		for(i=cf[0]=1;i<=n;++i)g[i]=i,h[i]=h[i-1]*M+s[i],cf[i]=cf[i-1]*M;
		for(i=1;i<=n;++i){
			f[i].push_back(1); 
			for(j=1;j*i<=k;++j)f[i].push_back(cf[j*i]+f[i][j-1]);
		}
		sort(g+1,g+n+1,cmp);
		for(i=0;i<k;++i){
			putchar(s[i%g[1]+1]);
		}
	return 0;
}