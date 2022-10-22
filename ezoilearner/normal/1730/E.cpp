#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
 
typedef long long ll;
typedef pair<int,int> pii;
#define FR first
#define SE second
 
inline void rd(int &x){
    x=0;char ch=getchar();int f=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    x*=f;
}
 
#define Maxn 500010
#define Maxv 1000010

int T,n,mn[Maxn],mx[Maxn],p[Maxn],cnt[Maxv];
long long ans;
vector<int>divisors[Maxv];

void solve(int l,int r){
	if(l==r)
		return void(++ans);
	int mid=l+r>>1;
	solve(l,mid),solve(mid+1,r);
	mn[mid]=mx[mid]=p[mid];
	mn[mid+1]=mx[mid+1]=p[mid+1];
	rep(i,mid+2,r){
		mn[i]=min(mn[i-1],p[i]);
		mx[i]=max(mx[i-1],p[i]);
	}
	per(i,mid-1,l){
		mn[i]=min(mn[i+1],p[i]);
		mx[i]=max(mx[i+1],p[i]);
	}
	int t=mid,w=mid;
	rep(i,mid+1,r){
		while(t>=l&&mx[t]<=mx[i])
			++cnt[mn[t]],--t;
		while(w>=l&&mn[w]>=mn[i])
			--w;
		for(auto x:divisors[mx[i]])
			if(x<mn[i])ans+=cnt[x];
			else break;
		// mn[t]<mn[i]
		if(mx[i]%mn[i]==0)ans+=mid-max(t,w);
		// mn[t]>=mn[i]
	}
	rep(i,l,mid)cnt[mn[i]]=0;
	t=mid+1,w=mid+1;
	per(i,mid,l){
		while(t<=r&&mx[t]<mx[i])
			++cnt[mn[t]],++t;
		while(w<=r&&mn[w]>=mn[i])
			++w;
		for(auto x:divisors[mx[i]])
			if(x<mn[i])ans+=cnt[x];
			else break;
		if(mx[i]%mn[i]==0)ans+=min(t,w)-mid-1;
	}
	rep(i,mid+1,r)cnt[mn[i]]=0;
}

void work(){
	ans=0;
	rd(n);
	rep(i,1,n)rd(p[i]);
	solve(1,n);
	printf("%lld\n",ans);
}

int main(){
	rep(i,1,1000000)
		for(int j=i;j<=1000000;j+=i)
			divisors[j].emplace_back(i);
	cin>>T;
	while(T--)work();
}