#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
#define int long long
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define maxn (1<<20|3)
int n,m,mxs,v1[maxn],v2[maxn];
int f1[maxn],f2[maxn];
int a[20],f[maxn],b[20];

void calc(int*f,int l,int r)
{
	int o=1; f[1]=0;
	For(i,l,r){
		For(j,1,o) f1[j]=f[j]+b[i],f2[j]=f[j]-b[i];
		int x=1,y=1,p=1;
		while(x<=o&&y<=o) f[p]=(f1[x]<f2[y])?f1[x++]:f2[y++],++p;
		while(x<=o) f[p]=f1[x++],++p;
		while(y<=o) f[p]=f2[y++],++p;
		o<<=1;
	}
}
bool check(int s)
{
	int sum=0,k=0;
	For(i,1,n)if(s>>(i-1)&1)b[++k]=a[i],sum+=a[i];
	if((sum-(k-1))%2) return 0;
	calc(v1,1,k/2);
	calc(v2,k/2+1,k);
	int l1=(1<<(k/2)),l2=(1<<(k-k/2));
	int cnt=1+(abs(sum)<k)*2,j=1;
//	For(i,1,l1)cout<<v1[i]<<' ';puts("");For(i,1,l2)cout<<v2[i]<<' ';puts("");
	Rep(i,l2,1){
		while(j<=l1 && v1[j]+v2[i]<=-k) ++j;
		int p=j;
		while(p<=l1&&cnt&&v1[p]+v2[i]<k) --cnt,++p;
	}
//	cout<<s<<" "<<cnt<<endl;
	return !cnt;
}

signed main()
{
	n=read();
	For(i,1,n)a[i]=read(),a[i]&&(a[++m]=a[i]);
	n=m; mxs=(1<<n);
	For(s,1,mxs-1)
    	if(!f[s] && check(s)){
    		f[s]=1;
    		for(int rst=(mxs-1)^s,t=rst; t ;t=(t-1)&rst)
    			f[s|t]=max(f[s|t],f[t]+1);
		}
	cout<<n-f[mxs-1];
	return 0;
}