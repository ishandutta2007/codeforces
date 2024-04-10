#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
#define ll long long
#define pn cout<<"NO\n"
#define py cout<<"YES\n" 
int T,i,j,d,hd,g,n,ee,f1,f2,k,fl,a[N],ans[N],mx,x,y,v,s1[N],st[N],vst[N];
char s[N];
map<pair<int,int> , int>p;
inline gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	ios::sync_with_stdio(false);
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&n,s+1);p.clear();
		for(i=1;i<=n;++i)s1[i]=s1[i-1]+(s[i]=='D');
		for(i=1;i<=n;++i){
			g=gcd(s1[i],i-s1[i]);
			cout<<++p[make_pair(s1[i]/g,(i-s1[i])/g)]<<" ";
		}cout<<"\n";
	}
}