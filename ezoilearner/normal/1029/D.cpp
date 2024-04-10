#pragma GCC optimize(3)
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <unordered_map>
using namespace std;

int n,k,a[500005],dig[500005],p[50];

const int M=1000037;

typedef long long ll;

struct HashMap{
    int cnt=0,head[M],to[M],nxt[M];
    ll v[M];
    bool count(int f){
        int x=f%M;
        for(int i=head[x];i;i=nxt[i]){
            if(to[i]==f){
                return true;
            }
        }
        return false;
    }
    ll get(int f){
        int x=f%M;
        for(int i=head[x];i;i=nxt[i]){
            if(to[i]==f){
                return v[i];
            }
        }
        return 0;
    }
    void set(int f,ll val){
        int x=f%M;
//        printf("%d\n",cnt);
        to[++cnt]=f;
        nxt[cnt]=head[x];
        v[cnt]=val;
        head[x]=cnt;
    }
}mp[11];

inline int get(int x){
	int ans=0;
	while(x){
		ans++;x/=10;
	}
	return ans;
}

int main(){
	scanf("%d%d",&n,&k);
	for(register int i=1;i<=n;i++)scanf("%d",a+i);
	for(register int i=1;i<=n;i++)dig[i]=get(a[i]);
	p[0]=1;
	for(register int i=1;i<=10;i++)p[i]=p[i-1]*10ll%k;
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=10;++j)
			mp[j].set(1ll*a[i]*p[j]%k,mp[j].get(1ll*a[i]*p[j]%k)+1);
	long long ans=0;
	for(register int i=1;i<=n;i++){
		register int now=a[i]%k;
		register int tmp=mp[dig[i]].get((k-now)%k);
		if(tmp){
			ans+=tmp;
			if((now*p[dig[i]]%k)==(k-now)%k)ans--;
		}
	}
	printf("%I64d\n",ans);
}