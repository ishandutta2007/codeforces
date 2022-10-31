#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#define IT std::vector<std::pair<ll,ll> >::iterator
typedef long long ll;
const int N=300005;
ll a[N],b[N];
std::vector<std::pair<ll,ll> > v;
std::priority_queue<ll,std::vector<ll>,std::greater<ll> > q;
inline void chmax(ll &a,const ll &b){(a<b)&&(a=b);}
inline void chmin(int &a,const int &b){(a>b)&&(a=b);}
int main()
{
	int n;
	ll st,nt;
	scanf("%d %lld %lld",&n,&st,&nt);
	--n;
	for(int i=1;i<=n;++i) scanf("%lld %lld",&a[i],&b[i]);
	int ans=1;
	ll maxx=0;
	for(int i=1;i<=n;++i)
	{
		if(a[i]<=st)
		{
			chmax(maxx,a[i]);
			v.push_back(std::make_pair(a[i],b[i]));
		}
		else
		{
			++ans;
			q.push(b[i]-a[i]+1);
		}
	}
	std::sort(v.begin(),v.end());
	int res=ans;
	while(!q.empty()&&st>0)
	{
		ll tmp=q.top();
		q.pop();
		if(st>=tmp)
		{
			st-=tmp;
			--ans;
			IT it=std::upper_bound(v.begin(),v.end(),std::make_pair(st,0x7fffffffffffffffll));
			ans+=v.end()-it;
			for(IT itt=it;itt!=v.end();++itt)
			{
				q.push(itt->second-itt->first+1);
			}
			v.erase(it,v.end());
			chmin(res,ans);
		}
		else break;
	}
	printf("%d\n",res);
	return 0;
}
//Dpair AK IOI