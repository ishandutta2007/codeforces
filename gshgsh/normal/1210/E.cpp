#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
#define MAXM 201
int N,M,cnt,a[MAXN],turn[MAXM][MAXM],lst[MAXM],f[MAXN],siz[MAXM];ll ans;vector<int>id[MAXM];map<vector<int>,int>dfn;
int getf(int x){return f[x]==x?x:getf(f[x]);}void mrg(int x,int y){int a=getf(x),b=getf(y);if(a==b)return;if(siz[a]<siz[b])swap(a,b);f[b]=a;siz[a]+=siz[b];}
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),M=get();cnt=1;For(i,1,M)cnt*=i;vector<int>x(M);For(i,0,M-1)x[i]=i;For(i,0,cnt-1){id[i]=x,dfn[x]=i;next_permutation(x.begin(),x.end());}
	For(i,0,cnt-1)For(j,0,cnt-1){vector<int>a=id[i],b=id[j],c(M);For(k,0,M-1)c[k]=a[b[k]];turn[i][j]=dfn[c];}For(i,1,N){vector<int>x(M);For(j,0,M-1)x[j]=get()-1;a[i]=dfn[x];}
	For(i,1,N)
	{
		lst[a[i]]=i;vector<int>x;For(j,0,cnt-1)if(lst[j])x.push_back(lst[j]);sort(x.begin(),x.end(),greater<int>());
		For(j,0,cnt-1)f[j]=j,siz[j]=1;int pre=i;for(auto j:x){ans+=(pre-j)*siz[getf(0)];if(getf(0)!=getf(a[j]))For(k,0,cnt-1)mrg(k,turn[k][a[j]]);pre=j;if(siz[getf(0)]==cnt)break;}ans+=siz[getf(0)]*pre;
	}
	cout<<ans<<endl;return 0;
}