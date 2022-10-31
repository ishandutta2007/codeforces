#include<bits/stdc++.h>
template <typename _Tp>void read(_Tp &x){
	char ch(getchar());bool f(false);while(!isdigit(ch))f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch))x=x*10+(ch&15),ch=getchar();
	if(f)x=-x;
}
template <typename _Tp,typename... Args>void read(_Tp &t,Args &...args){read(t);read(args...);}
const int N=100005;typedef long long ll;
int L[N],R[N],p[N],s[N],a[N],n,m,val[N],VAL[N];ll t,lim[N],b[N],suf[N];
ll calc1(int mid){ll tot=0;for(int i=1;i<=n;++i)tot+=std::min(R[i],std::max(L[i],mid));return tot;}
bool check(int mid){
	int x=-1,y=-1;for(int i=1;i<=mid;++i)if(val[i]!=-1)(x==-1?x:y)=val[i];
	if(x!=-1&&y!=-1&&x!=y)return 0;
	if(x==-1&&y==-1){
		ll tmp=1e18,tot=0;
		for(int i=1;i<=m;++i)tot+=i>mid?VAL[i]:0,tmp=std::min(tmp,(lim[i]-tot)/std::min(i,mid));
		for(int i=1;i<=m;++i)b[i]=i<=mid?tmp:VAL[i];
	}
	else for(int i=1;i<=m;++i)b[i]=i<=mid?x:VAL[i];
	ll tot=0;for(int i=1;i<=m;++i){tot+=b[i],suf[i]=lim[i]-tot;if(tot>lim[i])return 0;}
	suf[m+1]=1e18;for(int i=m;i>=1;--i)suf[i]=std::min(suf[i],suf[i+1]);
	ll sum=0;for(int i=mid+1;i<=m;++i)if(val[i]==-1)b[i]=std::min(VAL[i]+suf[i]-sum,b[i-1]),sum+=b[i]-VAL[i];
	for(int i=1;i<m;++i)if(b[i]<b[i+1])return 0;
	return sum+tot==t;
}
int main(){
	read(n,m);
	for(int i=1;i<=n;++i)read(L[i],R[i]);
	int q;read(q);
	memset(val,-1,sizeof(val));
	for(int i=1;i<=q;++i)read(p[i],s[i]),val[p[i]]=s[i],VAL[p[i]]=s[i];
	for(int i=m;i>=1;--i)if(!VAL[i])VAL[i]=VAL[i+1];
	read(t);int l=0,r=m,mid;
	while(l<r)mid=(l+r+1)>>1,calc1(mid)<=t?l=mid:r=mid-1;
	ll tot=0;for(int i=1;i<=n;++i)a[i]=std::min(R[i],std::max(L[i],l)),tot+=a[i];
	for(int i=1;i<=n;++i)if(tot<t&&a[i]!=R[i]&&a[i]==l)++a[i],++tot;
	std::sort(a+1,a+n+1);
	for(int i=1,j=1;i<=m;++i){
		while(j<=n&&a[j]<i)++j;
		lim[i]=std::min(t,lim[i-1]+n-j+1);
	}
	l=1,r=m;while(l<r)mid=(l+r+1)>>1,check(mid)?l=mid:r=mid-1;
	if(!check(l))return puts("-1 -1"),0;
	printf("%d %lld\n",l,b[1]);
	return 0;
}