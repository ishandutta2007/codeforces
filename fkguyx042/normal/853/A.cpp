#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<ctime>
#include<set>
#include<vector>
#include<map>
#include<queue>

#define N 600005
#define M 8000005

#define ls (t<<1)
#define rs ((t<<1)|1)
#define mid ((l+r)>>1)

#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

int i,j,m,n,p,k,a[N],Time[N];

set<pair<int,int> >st;

int main()
{
		scanf("%d%d",&n,&k); long long ans=0,sum=0;
		for (i=1;i<=n;++i) scanf("%d",&a[i]),ans-=1ll*a[i]*i;
		for (i=1;i<=k;++i) st.insert(mk(a[i],i)),sum+=a[i]; 
		for (i=k+1;i<=n+k;++i)
		{
			if (i<=n)
			st.insert(mk(a[i],i)),sum+=a[i];
			set<pair<int,int> >::iterator it=--st.end();
			ans+=1ll*(*it).fi*i;
			Time[(*it).se]=i; 
			st.erase(it);
		}
		printf("%I64d\n",ans);
		for (i=1;i<=n;++i) printf("%d ",Time[i]); 
}